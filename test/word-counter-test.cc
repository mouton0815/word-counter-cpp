#include <cassert>
#include <iostream>
#include "../src/constants.hh"
#include "../src/word-counter.hh"
#include "../src/blocking-queue.hh"


WordQueue* createWordQueue(std::initializer_list<std::string> words) {
    auto* wordQueue = new WordQueue();
    for (auto& word : words) {
        wordQueue->push(word);
    }
    wordQueue->push(STREAM_END); // End-of-stream marker
    return wordQueue;
}

void countAndVerify(WordQueue& wordQueue, const WordCountList& refList) {
    WordCounter counter(wordQueue);
    const auto list = counter.count();
    assert(std::equal(list.begin(), list.end(), refList.begin(), refList.end()));
}

void testWordCounterEmpty() {
    std::unique_ptr<WordQueue> wordQueuePtr(createWordQueue({}));
    auto refList = WordCountList({});
    countAndVerify(*wordQueuePtr, refList);
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testWordCounterSingle() {
    std::unique_ptr<WordQueue> wordQueuePtr(createWordQueue({ "foo" }));
    auto refList = WordCountList({ WordCount("foo", 1) });
    countAndVerify(*wordQueuePtr, refList);
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testWordCounterMultiple() {
    std::unique_ptr<WordQueue> wordQueuePtr(createWordQueue({ "bar", "foo", "bar" }));
    auto refList = WordCountList({ WordCount("bar", 2), WordCount("foo", 1) });
    countAndVerify(*wordQueuePtr, refList);
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

int main(int argc, char** argv) {
    testWordCounterEmpty();
    testWordCounterSingle();
    testWordCounterMultiple();
    return 0;
}
