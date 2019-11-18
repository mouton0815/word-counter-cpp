#pragma once
#include "file-reader.hh"
#include "tokenizer.hh"

class FileReaderImpl : public FileReader {
private:
    Tokenizer& m_tokenizer;
public:
    FileReaderImpl(Tokenizer& tokenizer);
    void read(const std::string& path) override;
    void close() override;
};
