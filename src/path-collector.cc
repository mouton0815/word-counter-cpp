#include <experimental/filesystem> // TODO: Upgrade to GCC 8 and remove "experimental" (+ make requirements clear in README.md)
#include "constants.hh"
#include "path-collector.hh"

typedef std::experimental::filesystem::recursive_directory_iterator PathIterator;

// It is awful that the C++ standard library does not have this function...
bool hasSuffix(const std::string& text, const std::string& suffix) {
    if (text.length() < suffix.length()) {
        return false;
    }
    return text.compare(text.length() - suffix.length(), suffix.length(), suffix) == 0;
}

PathCollector::PathCollector(const Path& rootPath, PathQueue& pathQueue)
    : m_rootPath(rootPath), m_pathQueue(pathQueue) {
}

void PathCollector::operator()() {
    for(auto iter = PathIterator(m_rootPath); iter != PathIterator(); ++iter) {
        // TODO: Check for iter->is_regular_file(), which is not supported by the experimental fs implementation
        const auto filename = iter->path();
        if (hasSuffix(filename, ".txt")) {
            m_pathQueue.push(filename);
        }
    }
    m_pathQueue.push(Path(STREAM_END));
}
