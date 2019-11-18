#include <algorithm>
#include <cassert>
#include <iostream>
#include "../src/constants.hh"
#include "../src/path-collector.hh"
#include "../src/string-queue.hh"
#include "tests.hh"

void testPathCollector() {
    StringQueue queue;
    PathCollector("./data", queue)();

    std::string path;
    std::vector<std::string> list;
    while ((path = queue.pop()) != STREAM_END) {
        list.push_back(path);
    }
    std::sort(list.begin(), list.end());

    const auto refList = { "file1.txt", "file2.txt", "file3.txt" };
    // for (const auto& x: list) std::cout << "-----> " << x << std::endl;
    // for (const auto& x: refList) std::cout << "--~--> " << x << std::endl;
    assert(std::equal(list.begin(), list.end(), refList.begin(), refList.end()));
    std::cout << "ok " << __FUNCTION__ << std::endl;
}
