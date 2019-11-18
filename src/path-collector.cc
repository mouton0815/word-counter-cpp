#include <experimental/filesystem> // TODO: Upgrade to GCC 8 and remove "experimental" (+ make requirements clear in README.md)
#include "constants.hh"
#include "path-collector.hh"
#include <iostream> // TODO: Remove

namespace fs = std::experimental::filesystem;

// It is awful that the C++ standard library does not have this function...
bool hasSuffix(const std::string& text, const std::string& suffix) {
    if (text.length() < suffix.length()) {
        return false;
    }
    return text.compare(text.length() - suffix.length(), suffix.length(), suffix) == 0;
}

PathCollector::PathCollector(const std::string& rootPath, StringQueue& pathQueue)
    : m_rootPath(rootPath), m_pathQueue(pathQueue) {
}

void PathCollector::operator()() {
    const fs::path rootPath(m_rootPath);
    for(auto iter = fs::recursive_directory_iterator(rootPath); iter != fs::recursive_directory_iterator(); ++iter) {
        // TODO: Check for iter->is_regular_file(), which is not supported by the experimental fs implementation
        const auto filename = iter->path();
        if (hasSuffix(filename, ".txt")) {
            m_pathQueue.push(filename);
        }
    }
    m_pathQueue.push(STREAM_END);
}