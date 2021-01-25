#include <sstream>

#include "exceptions/fs.h"
#include "FileIndex.h"
#include "FileIndexReader.h"


FileIndexReader::FileIndexReader(FileIndex* index) {
    setIndex(index);
}


FileIndexReader::FileIndexReader(const std::string& fileName, FileIndex* index) {
    setIndex(index);
    setInputFile(fileName);
}


FileIndexReader::~FileIndexReader() {
    m_inputStream.close();
}


void
FileIndexReader::setIndex(FileIndex* index) {
    m_indexObject = index;
}


void
FileIndexReader::setInputFile(const std::string& fileName) {
    if (m_inputStream.is_open()) {
        m_inputStream.close();
    }
    m_inputStream = std::ifstream(fileName);
    if (!m_inputStream.is_open()) {
        throw FileOpenException();
    }
}


bool
FileIndexReader::parseIndexEntry(std::stringstream& ss, std::pair<std::string, FileIndex::FileIndexData>& entry) {
    std::string garbage;
    ss >> entry.first;
    ss.ignore(1, ' ');
    ss >> entry.second.timestamp;
    ss.ignore(1, ' ');
    ss >> entry.second.hash;
    if (entry.first == "" || entry.second.timestamp == EMPTY_TIMESTAMP || entry.second.hash == "") {
        return false;
    }
    return !(ss >> garbage); // Ensure no other data is in the stream.
}


void
FileIndexReader::read() {
    const FileIndex::FileIndexData EMPTY_DATA{ .timestamp = EMPTY_TIMESTAMP, .hash = "" };

    std::string line;
    while(std::getline(m_inputStream, line)) {
        std::pair<std::string, FileIndex::FileIndexData> entry("", EMPTY_DATA);
        std::stringstream stringStream(line);
        if (parseIndexEntry(stringStream, entry)) {
            m_indexObject->m_index->insert(entry);
        }
    }

    m_inputStream.seekg(0, std::ios::beg);
}
