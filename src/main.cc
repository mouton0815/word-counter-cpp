#include <iostream>
#include <map>
#include <thread>
#include "constants.hh"
#include "blocking-queue.hh"
#include "tokenizer.hh"
#include "file-reader-impl.hh"
#include "string-queue.hh"
#include "word-counter.hh"
#include "worker.hh"

using namespace std;

int main(int argc, char** argv) {
    const auto rootPath = "./data/file1.txt";

    const auto numWorkers = 1;
    std::cout << "#workers: " << numWorkers << std::endl;

    StringQueue pathQueue;
    pathQueue.push(rootPath);
    pathQueue.push(STREAM_END);
    StringQueue wordQueue;

    Tokenizer tokenizer(wordQueue);
    FileReaderImpl fileReader(tokenizer);
    Worker worker(1, pathQueue, fileReader);
    std::thread t([&]{
        worker();
        fileReader.close(); // TODO: Will be done by the pool
    });

    WordCounter counter(wordQueue);
    const WordCountList wordCounts = counter.count();
    for (const auto& item: wordCounts) {
        std::cout << item.getCount() << " - " << item.getWord() << std::endl;
    }
    /*
    reader.read(rootPath);
    reader.close();

    std::string word;
    while ((word = myQueue.pop()) != STREAM_END) {
        std::cout << "---" << word;
    }
    std::cout << std::endl;
    */
    t.join();
    return 0;
}
