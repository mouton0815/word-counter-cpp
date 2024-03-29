#include <cassert>
#include <iostream>
#include <thread>
#include "tests.hh"
#include "../src/constants.hh"
#include "../src/path-queue.hh"
#include "../src/worker.hh"
#include "file-reader-mock.hh"

void workAndVerify(std::initializer_list<Path> paths) {
    PathQueue pathQueue;
    FileReaderMock fileReader;
    Worker worker(1, pathQueue, fileReader);

    std::thread t(worker);

    for (const auto& path: paths) {
        pathQueue.push(path);
    }
    pathQueue.push(STREAM_END);

    t.join();

    assert(std::equal(paths.begin(), paths.end(), fileReader.get().begin(), fileReader.get().end()));
}

void testWorkerEmpty() {
    workAndVerify({});
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testWorkerNormal() {
    workAndVerify({Path("foo"), Path("bar"), Path("baz")});
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

