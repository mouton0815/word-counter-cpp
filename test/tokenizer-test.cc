#include <cassert>
#include <iostream>
#include <vector>
#include "../src/constants.hh"
#include "../src/string-queue.hh"
#include "../src/tokenizer.hh"

std::vector<std::string> tokenize(const std::string& text) {
    StringQueue queue;
    Tokenizer tokenizer(queue);
    tokenizer.tokenize(text);
    tokenizer.close();

    std::string word;
    std::vector<std::string> result;
    while ((word = queue.pop()) != STREAM_END) {
        result.push_back(word);
    }
    return result;
}

void tokenizeAndVerify(const std::string& text, std::initializer_list<std::string> refWords) {
    const auto words = tokenize(text);
    assert(std::equal(words.begin(), words.end(), refWords.begin(), refWords.end()));
}

void testTokenizerEmpty() {
    tokenizeAndVerify("  ", {});
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testTokenizerTrim() {
    tokenizeAndVerify("  foo* ", { "foo" });
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testTokenizerMulti() {
    tokenizeAndVerify("Foo bAr baZ", { "foo", "bar", "baz" });
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testTokenizerSpecialSigns() {
    tokenizeAndVerify("Foo-~bar #!  baz", { "foo", "bar", "baz" });
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testTokenizerUnderscore() {
    tokenizeAndVerify("foo_bar__baz", { "foo_bar__baz" });
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testTokenizerUnicodeGerman() {
    tokenizeAndVerify("Fö bär baß", { "fö", "bär", "baß" });
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testTokenizerUnicodeRussian() {
    tokenizeAndVerify("Раз, два три!", { "раз", "два", "три" });
}

void testTokenizerUnicodeCzech() {
    tokenizeAndVerify("Jedna, dva tři čtyři pět!", { "jedna", "dva", "tři", "čtyři", "pět" });
}

void testTokenizerIgnoreNumbers() {
    tokenizeAndVerify("foo 123 bar456baz", { "foo", "bar", "baz" });
}

