#include <fstream>

#include "exceptions/fs.h"
#include "FileIndex.h"
#include "FileIndexWriter.h"


FileIndexWriter::FileIndexWriter(FileIndex* index) {
    setIndex(index);
}


FileIndexWriter::FileIndexWriter(const std::string& fileName, FileIndex* index) {
    setIndex(index);
    setOutputFile(fileName);
}


void
FileIndexWriter::setIndex(FileIndex* index) {
    m_indexObject = index;
}


void
FileIndexWriter::setOutputFile(const std::string& fileName) {
    m_outputFileName = fileName;
}


void
FileIndexWriter::write() {
    std::ofstream outputStream(m_outputFileName);
    if (!outputStream.is_open()) {
        throw FileOpenException();
    }
    for (const auto& item : *(m_indexObject->m_index)) {
        outputStream << item.first << ' '
                     << item.second.timestamp << ' '
                     << item.second.hash << '\n';
    }
    outputStream.close();
}