#pragma once
#include "path-queue.hh"
#include "file-reader.hh"

class Worker {
private:
    const int m_id;
    PathQueue& m_pathQueue;
    FileReader& m_fileReader;
public:
    Worker(const int id, PathQueue& pathQueue, FileReader& fileReader);
    void operator()();
};
