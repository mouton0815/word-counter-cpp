#pragma once
#include <string>

class FileReader {
public:
    virtual void read(const std::string& path);
    virtual void close();
};
