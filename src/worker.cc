#include <iostream> // TODO: Replace by logger
#include "worker.hh"
#include "constants.hh"

Worker::Worker(const int id, PathQueue& pathQueue, FileReader& fileReader)
    : m_id(id), m_pathQueue(pathQueue), m_fileReader(fileReader) {
}

void Worker::operator()() {
    std::cerr << "Worker " << m_id << " starts" << std::endl;
    Path path;
    while ((path = m_pathQueue.pop()) != STREAM_END) {
        std::cerr << "Worker " << m_id << " reads "  << path << std::endl;
        m_fileReader.read(path);
    }
    // Inform other workers that pathQueue is empty
    m_pathQueue.push(Path(STREAM_END));
    std::cerr << "Worker " << m_id << " leaves" << std::endl;
}

