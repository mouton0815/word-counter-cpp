#include <vector>
#include "word-count.hh"
#include "blocking-queue.hh"

typedef BlockingQueue<std::string> WordQueue;
typedef std::vector<WordCount> WordCountList;

class WordCounter {
    const WordQueue& m_wordQueue;
public:
    WordCounter(const WordQueue& wordQueue);
    WordCountList count();
};
