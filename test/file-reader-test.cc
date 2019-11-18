#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "../src/constants.hh"
#include "../src/tokenizer.hh"
#include "../src/file-reader-impl.hh"
#include "../src/string-queue.hh"
#include "tests.hh"

void testFileReader() {
    StringQueue queue;
    Tokenizer tokenizer(queue);
    FileReaderImpl reader(tokenizer);
    reader.read("./data/file1.txt");
    reader.close();

    std::string word;
    std::vector<std::string> list;
    while ((word = queue.pop()) != STREAM_END) {
        list.push_back(word);
    }

    assert(list.size() == 100);
    assert(*list.begin() == "lorem");
    assert(*list.rbegin() == "amet");
    std::cout << "ok " << __FUNCTION__ << std::endl;
}
