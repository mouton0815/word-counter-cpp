#include <algorithm> // sort
#include <locale>
#include "word-count-mapper.hh"

class WordCountComparator {
private:
    // TODO: Understand all this, especially why this is a reference!
    const std::collate<char>& m_collator;
public:
    WordCountComparator()
    : m_collator(std::use_facet<std::collate<char> >(std::locale())) { // TODO: Use English locale -- not supported by MinGW
    }
    bool operator()(const WordCount& c1, const WordCount& c2) {
        if (c1.getCount() == c2.getCount()) {
            return m_collator.compare(
                c1.getWord().data(), c1.getWord().data() + c1.getWord().length(),
                c2.getWord().data(), c2.getWord().data() + c2.getWord().length()) < 0;
            // return c1.getWord().compare(c2.getWord()) == -1;
        }
        return c2.getCount() < c1.getCount(); // Descending order
    }
};

WordCountList WordCountMapper::operator()(const WordCountMap& wordCountMap) {
    WordCountList list;
    for (const auto& item: wordCountMap) {
        list.push_back(WordCount(item.first, item.second));
    }
    WordCountComparator comparator;
    std::sort(list.begin(), list.end(), comparator);
    return list;
}
