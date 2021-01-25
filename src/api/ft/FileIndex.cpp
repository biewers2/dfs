#include <unordered_map>
#include <string>

#include "api/fs/timestamp.h"
#include "FileIndex.h"


FileIndex::FileIndex() {
    index = new std::unordered_map<std::string, FileIndexData>();
}


FileIndex::~FileIndex() {
    delete index;
}


FileIndex::FileIndexData
FileIndex::bundleData(const timestamp_t& timestamp, const hashString_t& hash) {
    return FileIndex::FileIndexData{ .timestamp = timestamp, .hash = hash };
}
