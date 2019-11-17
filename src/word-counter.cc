#include "constants.hh"
#include "word-counter.hh"
#include "word-count-mapper.hh"

WordCounter::WordCounter(WordQueue& wordQueue)
    : m_wordQueue(wordQueue) {
}

WordCountList WordCounter::count() {
    WordCountMap map;
    std::string word;
    while ((word = m_wordQueue.pop()) != STREAM_END) {
        map[word]++;
    }
    return WordCountMapper()(map);
}

