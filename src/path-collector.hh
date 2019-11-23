#pragma once
#include <string>
#include "path-queue.hh"

class PathCollector {
private:
    const Path& m_rootPath;
    PathQueue&  m_pathQueue;
public:
    PathCollector(const Path& rootPath, PathQueue& pathQueue);
    void operator()();
};
