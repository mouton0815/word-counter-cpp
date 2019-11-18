#pragma once
#include <regex>
#include <string>
#include "string-queue.hh"

class Tokenizer {
private:
    StringQueue& m_wordQueue;
    std::regex m_regex;
public:
    Tokenizer(StringQueue& wordQueue);
    void tokenize(const std::string& text);
    void close();
};
