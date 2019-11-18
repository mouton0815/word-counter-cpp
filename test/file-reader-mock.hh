#pragma once
#include <vector>
#include "../src/file-reader.hh"

class FileReaderMock : public FileReader {
public:
    std::vector<std::string> get();
};
