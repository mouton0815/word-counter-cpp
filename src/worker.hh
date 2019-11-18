#pragma once
#include "string-queue.hh"
#include "file-reader.hh"

class Worker {
private:
    const int m_id;
    StringQueue& m_pathQueue;
    FileReader& m_fileReader;
public:
    Worker(const int id, StringQueue& pathQueue, FileReader& fileReader);
    void operator()();
};
