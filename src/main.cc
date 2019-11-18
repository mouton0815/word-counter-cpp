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
#include "worker.hh"

using namespace std;

int main(int argc, char** argv) {
    const auto rootPath = "./data";

    const auto numWorkers = 1;
    std::cout << "#workers: " << numWorkers << std::endl;

    StringQueue pathQueue;
    StringQueue wordQueue;

    Tokenizer tokenizer(wordQueue);
    FileReaderImpl fileReader(tokenizer);
    Worker worker(1, pathQueue, fileReader);
    std::thread workerThread([&]{
        worker();
        fileReader.close(); // TODO: Will be done by the pool
    });

    PathCollector collector(rootPath, pathQueue);
    std::thread collectorThread(collector);

    WordCounter counter(wordQueue);
    const WordCountList wordCounts = counter.count();
    for (const auto& item: wordCounts) {
        std::cout << item.getCount() << " - " << item.getWord() << std::endl;
    }

    workerThread.join();
    collectorThread.join();
    return 0;
}
