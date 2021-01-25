#ifndef __DFS_UTIL_FILE_TIMESTAMP_INDEXER_H__
#define __DFS_UTIL_FILE_TIMESTAMP_INDEXER_H__

#include <string>
#include <unordered_map>
#include "api/fs/timestamp.h"
#include "FileIndex.h"


typedef std::unordered_map<std::string, timestamp_t>::iterator ftIterator_t;


class FTIndexerTest;

class FileIndexer {
private:
    FileIndex::FileIndexData getData(const std::string& fileName);

    FileIndex* m_indexObject;

public:
    FileIndexer(FileIndex* index);

    timestamp_t getTimestamp(const std::string& fileName);
    hashString_t getHashString(const std::string& fileName);
    bool contains(const std::string& fileName);

    void insert(const std::string& fileName, const timestamp_t& timestamp, const hashString_t& hash);
    void erase(const std::string& fileName);

    friend FTIndexerTest;
};


#endif // __DFS_UTIL_FILE_TIMESTAMP_INDEXER_H__
