#include <sstream>

#include "exceptions/fs.h"
#include "FTIndex.h"
#include "FTIndexReader.h"


FTIndexReader::FTIndexReader(FTIndex* index) {
    setIndex(index);
}


FTIndexReader::FTIndexReader(const std::string& fileName, FTIndex* index) {
    setIndex(index);
    setInputFile(fileName);
}


FTIndexReader::~FTIndexReader() {
    m_inputStream.close();
}


void
FTIndexReader::setIndex(FTIndex* index) {
    m_indexObject = index;
}


void
FTIndexReader::setInputFile(const std::string& fileName) {
    if (m_inputStream.is_open()) {
        m_inputStream.close();
    }
    m_inputStream = std::ifstream(fileName);
    if (!m_inputStream.is_open()) {
        throw FileOpenException();
    }
}


bool
parseIndexEntry(std::stringstream& ss, std::pair<std::string, timestamp_t>& entry) {
    std::string garbage;
    ss >> entry.first;
    ss.ignore(1, ' ');
    ss >> entry.second;
    if (entry.first == "" || entry.second == EMPTY_TIMESTAMP) {
        return false;
    }
    return !(ss >> garbage); // Ensure no other data is in the stream.
}


void
FTIndexReader::read() {
    std::string line;
    while(std::getline(m_inputStream, line)) {
        std::pair<std::string, timestamp_t> entry("", EMPTY_TIMESTAMP);
        std::stringstream stringStream(line);
        if (parseIndexEntry(stringStream, entry)) {
            m_indexObject->index->insert(entry);
        }
    }
    m_inputStream.seekg(0, std::ios::beg);
}
