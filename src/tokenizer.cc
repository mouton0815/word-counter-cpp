#include "tokenizer.hh"
#include "constants.hh"
#include <cctype>
#include <iostream>

std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
    return s;
}

Tokenizer::Tokenizer(StringQueue& wordQueue)
    //: m_wordQueue(wordQueue), m_pattern("\\s+") {
    : m_wordQueue(wordQueue), m_pattern("[_[:alpha:]]+") {
    // std::locale::global(std::locale("en_US.UTF-8"));
}

void Tokenizer::tokenize(const std::string& text) {
    std::cout << "--t--> " << text << std::endl;

    std::smatch res;
    std::string::const_iterator searchStart(text.cbegin());
    while (std::regex_search(searchStart, text.cend(), res, m_pattern)) {
        std::cout << "--l--> " << res[0] << std::endl;
        m_wordQueue.push(toLower(res[0]));
        searchStart = res.suffix().first;
    }
    /*
    std::sregex_token_iterator iter(text.begin(), text.end(), m_pattern, -1);
    std::sregex_token_iterator end;
    while (iter != end) {
        const std::string& word = *iter;
        if (!word.empty()) { // Skip leading and trailing empty strings
            std::cout << "--l--> '" << word << "'" << std::endl;
            m_wordQueue.push(word);
        }
        ++iter;
    }
    */
}

void Tokenizer::close() {
    m_wordQueue.push(STREAM_END);
}
