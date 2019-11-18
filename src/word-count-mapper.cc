#include <algorithm> // sort
#include <locale>
#include "word-count-mapper.hh"

class WordCountComparator {
private:
    const std::locale m_locale;
public:
    WordCountComparator() : m_locale("en_US.utf8") {}
    bool operator()(const WordCount& c1, const WordCount& c2) {
        if (c1.getCount() == c2.getCount()) {
            // See https://en.cppreference.com/w/cpp/locale/locale/operator()
            return m_locale(c1.getWord(), c2.getWord());
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
