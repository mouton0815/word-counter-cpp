#include "worker.hh"
#include "constants.hh"
#include <iostream> // TODO: Replace by logger

Worker::Worker(const int id, PathQueue& pathQueue, FileReader& fileReader)
    : m_id(id), m_pathQueue(pathQueue), m_fileReader(fileReader) {
}

void Worker::operator()() {
    std::cout << "Worker " << m_id << " starts" << std::endl;
    std::string path;
    while ((path = m_pathQueue.pop()) != STREAM_END) {
        std::cout << "Worker " << m_id << " takes "  << path << std::endl;
    }
    // Inform other workers that pathQueue is empty
    m_pathQueue.push(STREAM_END);
    std::cout << "Worker " << m_id << " leaves" << std::endl;
}

