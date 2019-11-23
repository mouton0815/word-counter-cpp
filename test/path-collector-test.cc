#include <algorithm>
#include <cassert>
#include <iostream>
#include "../src/constants.hh"
#include "../src/path-collector.hh"
#include "../src/path-queue.hh"
#include "tests.hh"

void testPathCollector() {
    PathQueue queue;
    PathCollector("./data", queue)();

    Path path;
    std::vector<Path> list;
    while ((path = queue.pop()) != STREAM_END) {
        list.push_back(path);
    }
    std::sort(list.begin(), list.end());

    const auto refList = { Path("./data/file1.txt"), Path("./data/file2.txt"), Path("./data/subdir/file3.txt") };
    assert(std::equal(list.begin(), list.end(), refList.begin(), refList.end()));
    std::cout << "ok " << __FUNCTION__ << std::endl;
}
