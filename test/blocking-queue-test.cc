#include <algorithm> // sort
#include <cassert>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include "../src/blocking-queue.hh"

void testSimple() {
    BlockingQueue<std::string> myQueue;
    const auto input = "Hello world";
    myQueue.push(input);
    const auto result = myQueue.pop();
    assert(result.compare(input) == 0);
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void testBlocking() {
    BlockingQueue<int> myQueue;
    auto thread = std::thread([&myQueue]{
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        myQueue.push(5);
    });
    const auto result = myQueue.pop(); // Main thread blocks until result is available
    assert(result == 5);
    thread.join();
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

void push(BlockingQueue<int>& queue, const int threadId, const int numberOfItems) {
    for (int i = 0; i < numberOfItems; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 10));
        queue.push(threadId * numberOfItems + i);
    }
}

void testConcurrently() {
    std::srand(std::time(nullptr)); // Use current time as seed for random generator

    BlockingQueue<int> myQueue;

    const int numberOfThreads = 4;
    const int itemsPerThread  = 100;
    auto threads = std::vector<std::thread>();

    for (int i = 0; i < numberOfThreads; i++) {
        threads.push_back(std::thread(push, std::ref(myQueue), i, itemsPerThread));
    }

    auto result = std::vector<int>();
    for (int i = 0; i < numberOfThreads * itemsPerThread; i++) {
        result.push_back(myQueue.pop());
    }

    for (auto& thread: threads) {
        thread.join();
    }

    std::sort(result.begin(), result.end());
    for (int i = 0; i < numberOfThreads * itemsPerThread; i++) {
        assert(result[i] == i);
    }
    std::cout << "ok " << __FUNCTION__ << std::endl;
}

int main(int argc, char** argv) {
    testSimple();
    testBlocking();
    testConcurrently();
    return 0;
}
