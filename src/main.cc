#include <algorithm> // std::max
#include <chrono>
#include <iostream>
#include <map>
#include <thread>
#include "constants.hh"
#include "blocking-queue.hh"
#include "tokenizer.hh"
#include "path-collector.hh"
#include "file-reader-impl.hh"
#include "string-queue.hh"
#include "word-counter.hh"
#include "worker-pool.hh"

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::duration<float> Duration;

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Syntax: " << argv[0] << " <folder>" << std::endl;
        return -1;
    }
    const auto rootPath = argv[1];

    // Measure time including setup
    const auto startTime = Clock::now();

    // Reserve one core for current thread (the counter), and another one for the path collector
    const auto numWorkers = std::max(static_cast<int>(std::thread::hardware_concurrency()) - 2, 1);
    std::cerr << "#workers: " << numWorkers << std::endl;

    StringQueue pathQueue;
    StringQueue wordQueue;

    Tokenizer tokenizer(wordQueue);
    FileReaderImpl fileReader(tokenizer);
    WorkerPool workerPool(numWorkers, pathQueue, fileReader);
    std::thread poolThread(workerPool);

    PathCollector collector(rootPath, pathQueue);
    std::thread collThread(collector);

    WordCounter counter(wordQueue);
    const WordCountList wordCounts = counter.count();
    for (const auto& item: wordCounts) {
        std::cout << item.getCount() << " - " << item.getWord() << std::endl;
    }

    poolThread.join();
    collThread.join();

    const Duration elapsed = Clock::now() - startTime;
    std::cerr << "Elapsed time: " << elapsed.count() << " seconds"<< std::endl;
    return 0;
}
