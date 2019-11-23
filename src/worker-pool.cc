#include <thread>
#include <vector>
#include "worker.hh"
#include "worker-pool.hh"

WorkerPool::WorkerPool(const int numWorkers, PathQueue& pathQueue, FileReader& fileReader)
    : m_numWorkers(numWorkers), m_pathQueue(pathQueue), m_fileReader(fileReader) {
}

void WorkerPool::operator()() {
    std::vector<std::thread> threads;
    for (int i = 0; i < m_numWorkers; ++i) {
        Worker worker(i, m_pathQueue, m_fileReader);
        threads.push_back(std::thread(worker));
    }
    for (auto& thread: threads) {
        thread.join();
    }
    m_fileReader.close();
}

