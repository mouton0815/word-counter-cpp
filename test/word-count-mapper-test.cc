#include <cassert>
#include <iostream>
#include "../src/word-count-mapper.hh"
#include "tests.hh"

void mapAndVerify(const WordCountMap& map, const WordCountList& refList) {
    const auto list = WordCountMapper()(map);
    // for (const auto& x: list) std::cout << "-----> " << x.getWord() << " -- " << x.getCount() << std::endl;
    // for (const auto& x: refList) std::cout << "--~--> " << x.getWord() << " -- " << x.getCount() << std::endl;
    assert(std::equal(list.begin(), list.end(), refList.begin(), refList.end()));
}

void testWordCountMapperEmpty() {
    const WordCountMap map;
    const WordCountList list;
    mapAndVerify(map, list);
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testWordCountMapperSimple() {
    const WordCountMap map = { {"foo", 1} };
    const WordCountList list = { WordCount("foo", 1) };
    mapAndVerify(map, list);
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testWordCountMapperSecondary() {
    const WordCountMap map = { {"foo", 2}, {"bar", 1}, {"baz", 2} };
    const WordCountList list = { WordCount("baz", 2), WordCount("foo", 2), WordCount("bar", 1) };
    mapAndVerify(map, list);
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testWordCountMapperUnicode() {
    const WordCountMap map = { {"über", 1}, {"Zuse", 1}, {"Ödem", 1} };
    const WordCountList list = { WordCount("Ödem", 1), WordCount("über", 1), WordCount("Zuse", 1) };
    mapAndVerify(map, list);
    std::cout << "ok " << __FUNCTION__ << std::endl;
}
