#include <cassert>
#include <iostream>
#include <thread>
#include "tests.hh"
#include "../src/constants.hh"
#include "../src/path-queue.hh"
#include "../src/worker.hh"
#include "file-reader-mock.hh"

void workAndVerify(std::initializer_list<std::string> paths) {
    PathQueue pathQueue;
    FileReaderMock fileReader;
    Worker worker(1, pathQueue, fileReader);

    std::thread t(worker);

    for (const auto& path: paths) {
        pathQueue.push(path);
    }
    pathQueue.push(STREAM_END);

    t.join();

    // for (const auto& x: fileReader.get()) std::cout << "-----> " << x << std::endl;
    // for (const auto& x: paths) std::cout << "--~--> " << x << std::endl;
    assert(std::equal(paths.begin(), paths.end(), fileReader.get().begin(), fileReader.get().end()));
}

void testWorkerEmpty() {
    workAndVerify({});
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testWorkerNormal() {
    workAndVerify({"foo", "bar", "baz"});
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

