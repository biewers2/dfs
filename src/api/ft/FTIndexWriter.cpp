#include <fstream>

#include "exceptions/fs.h"
#include "FTIndex.h"
#include "FTIndexWriter.h"


FTIndexWriter::FTIndexWriter(FTIndex* index) {
    setIndex(index);
}


FTIndexWriter::FTIndexWriter(const std::string& fileName, FTIndex* index) {
    setIndex(index);
    setOutputFile(fileName);
}


void
FTIndexWriter::setIndex(FTIndex* index) {
    m_indexObject = index;
}


void
FTIndexWriter::setOutputFile(const std::string& fileName) {
    m_outputFileName = fileName;
}


void
FTIndexWriter::write() {
    std::ofstream outputStream(m_outputFileName);
    if (!outputStream.is_open()) {
        throw FileOpenException();
    }
    for (const auto& item : *(m_indexObject->index)) {
        outputStream << item.first << ' ' << item.second << '\n';
    }
    outputStream.close();
}