#pragma once
#include <string>

class FileReader {
public:
    virtual void read(const std::string& path) = 0;
    virtual void close() = 0;
};
