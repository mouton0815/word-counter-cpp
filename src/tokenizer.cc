#include "tokenizer.hh"
#include "constants.hh"
#include <cctype>
#include <iostream>

std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
    return s;
}

Tokenizer::Tokenizer(StringQueue& wordQueue)
    : m_wordQueue(wordQueue), m_pattern("[_[:alpha:]]+") {
}

void Tokenizer::tokenize(const std::string& text) {
    std::smatch res;
    std::string::const_iterator searchStart(text.cbegin());
    while (std::regex_search(searchStart, text.cend(), res, m_pattern)) {
        m_wordQueue.push(toLower(res[0]));
        searchStart = res.suffix().first;
    }
}

void Tokenizer::close() {
    m_wordQueue.push(STREAM_END);
}
