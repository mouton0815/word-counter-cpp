#include "path-collector.hh"

PathCollector::PathCollector(const std::string& rootPath, StringQueue& pathQueue)
    : m_rootPath(rootPath), m_pathQueue(pathQueue) {
}

void PathCollector::operator()() {
}
