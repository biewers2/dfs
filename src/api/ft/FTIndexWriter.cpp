#include <fstream>

#include "exceptions/fs.h"
#include "FTIndex.h"
#include "FTIndexWriter.h"


FTIndexWriter::FTIndexWriter(FTIndex* index) {
    setIndex(index);
}


FTIndexWriter::FTIndexWriter(const std::string& fileName, FTIndex* index) {
    setIndex(index);
    setInputFile(fileName);
}


FTIndexWriter::~FTIndexWriter() {
    m_outputStream.close();
}


void
FTIndexWriter::setIndex(FTIndex* index) {
    m_indexObject = index;
}


void
FTIndexWriter::setInputFile(const std::string& fileName) {
    if (m_outputStream.is_open()) {
        m_outputStream.close();
    }
    m_outputStream = std::ofstream(fileName);
    if (!m_outputStream.is_open()) {
        throw FileOpenException();
    }
}


void
FTIndexWriter::write() {
    for (const auto& item : *(m_indexObject->index)) {
        m_outputStream << item.first << ' ' << item.second << '\n';
    }
}