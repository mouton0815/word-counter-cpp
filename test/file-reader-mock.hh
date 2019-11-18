#pragma once
#include <vector>
#include "../src/file-reader.hh"

class FileReaderMock : public FileReader {
private:
    std::vector<std::string> m_result;
public:
    void read(const std::string& path) override { m_result.push_back(path); }
    void close() override {}
    const std::vector<std::string>& get() { return m_result; }
};
