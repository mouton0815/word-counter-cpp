#include <string>

class WordCount {
private:
    const std::string m_word;
    const int         m_count;
public:
    WordCount(const std::string& word, const int count)
    : m_word(word), m_count(count) {
    }
    const std::string& getWord() const {
        return m_word;
    }
    int getCount() const {
        return m_count;
    }
};

inline bool operator==(const WordCount& x, const WordCount& y) {
    return x.getWord().compare(y.getWord()) == 0 && x.getCount() == y.getCount();
}
