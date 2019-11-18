#pragma once
#include <string>

class FileReader {
public:
    void read(const std::string& path);
    void close();
};
