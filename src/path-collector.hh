#pragma once
#include <string>
#include "string-queue.hh"

class PathCollector {
private:
    const std::string& m_rootPath;
    StringQueue&       m_pathQueue;
public:
    PathCollector(const std::string& rootPath, StringQueue& pathQueue);
    void operator()();
};
