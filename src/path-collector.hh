#pragma once
#include <string>
#include "string-queue.hh"

class PathCollector {
private:
    const std::string& m_rootPath;
    StringQueue&       m_pathQueue;
public:
    // TODO: Use fs::path instead of std::string!
    PathCollector(const std::string& rootPath, StringQueue& pathQueue);
    void operator()();
};
