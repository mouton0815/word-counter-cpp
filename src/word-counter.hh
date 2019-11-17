#pragma once
#include <map>
#include <vector>
#include "blocking-queue.hh"
#include "word-count-list.hh"
#include "word-count-map.hh"

typedef BlockingQueue<std::string> WordQueue;

class WordCounter {
    WordQueue& m_wordQueue;
    WordCountMap wordCounts;
public:
    WordCounter(WordQueue& wordQueue);
    WordCountList count();
};
