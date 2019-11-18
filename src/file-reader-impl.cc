#include <fstream>
#include <sstream>
#include <string>
#include "file-reader-impl.hh"

FileReaderImpl::FileReaderImpl(Tokenizer& tokenizer)
    : m_tokenizer(tokenizer) {
}

void FileReaderImpl::read(const std::string& path) {
    std::string line;
    std::ifstream file(path);
    while (std::getline(file, line)) {
        m_tokenizer.tokenize(line);
    }
}

void FileReaderImpl::close() {
    m_tokenizer.close();
}
