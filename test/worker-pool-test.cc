#include <algorithm> // std::sort
#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../src/constants.hh"
#include "../src/path-queue.hh"
#include "../src/worker-pool.hh"
#include "file-reader-mock.hh"
#include "tests.hh"

std::string toPath(const int i) {
    std::stringstream s;
    s << std::setw(2) << std::setfill('0') << i;
    return Path(s.str());
}

void runWorkerPoolAndVerify(const int pathCount) {
    PathQueue pathQueue;
    std::vector<Path> refList;
    for (int i = 0; i < pathCount; i++) {
        const auto path = toPath(i);
        refList.push_back(path);
        pathQueue.push(path);
    }
    pathQueue.push(STREAM_END);

    FileReaderMock fileReader;
    WorkerPool(4, pathQueue, fileReader)();

    auto list = fileReader.get();
    std::sort(list.begin(), list.end());
    assert(std::equal(list.begin(), list.end(), refList.begin(), refList.end()));
}

void testWorkerPoolNoInput() {
    runWorkerPoolAndVerify(0);
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testWorkerPoolWithInput() {
    runWorkerPoolAndVerify(100);
    std::cout << "ok " << __FUNCTION__ << std::endl;
}
