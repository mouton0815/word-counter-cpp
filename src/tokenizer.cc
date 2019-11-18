#include "tokenizer.hh"

Tokenizer::Tokenizer(StringQueue& wordQueue)
    : m_wordQueue(wordQueue), m_regex("\\s+") {
}

void Tokenizer::tokenize(const std::string& text) {
    std::sregex_token_iterator iter(text.begin(), text.end(), m_regex, -1);
    std::sregex_token_iterator end;
    while (iter != end) {
        m_wordQueue.push(*iter);
        ++iter;
    }
}

void Tokenizer::close() {
}
