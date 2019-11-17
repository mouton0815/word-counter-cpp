#include "word-count-list.hh"
#include "word-count-map.hh"

class WordCountMapper {
// private:
//     bool compareWordCounts(const WordCount& c1, const WordCount& c2);
public:
    WordCountList operator()(const WordCountMap& wordCountMap);
};
