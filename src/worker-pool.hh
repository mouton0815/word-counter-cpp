#pragma once
#include "file-reader.hh"
#include "path-queue.hh"

class WorkerPool {
private:
    const int   m_numWorkers;
    PathQueue&  m_pathQueue;
    FileReader& m_fileReader;
public:
    WorkerPool(const int numWorkers, PathQueue& pathQueue, FileReader& fileReader);
    void operator()();
};
