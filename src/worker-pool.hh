#pragma once
#include "string-queue.hh"
#include "file-reader.hh"

class WorkerPool {
private:
    const int    m_numWorkers;
    StringQueue& m_pathQueue;
    FileReader&  m_fileReader;
public:
    WorkerPool(const int numWorkers, StringQueue& pathQueue, FileReader& fileReader);
    void operator()();
};
