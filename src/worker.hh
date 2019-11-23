#pragma once
#include "file-reader.hh"
#include "path-queue.hh"

class Worker {
private:
    const int   m_id;
    PathQueue&  m_pathQueue;
    FileReader& m_fileReader;
public:
    Worker(const int id, PathQueue& pathQueue, FileReader& fileReader);
    void operator()();
};
