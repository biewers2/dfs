#ifndef __DFS_FS_FILE_TIME_INDEXER_H__
#define __DFS_FS_FILE_TIME_INDEXER_H__

#include <unordered_map>
#include <vector>
#include <string>
#include "api/fs/file.h"


class FileTimeIndexerTest;

class FileTimeIndexer {
private:
    typedef std::unordered_map<std::string, timestamp_t> fileTimestampIndex_t;

    timestamp_t retrieveFromFile(const std::string& fileName);
    void writeOutCache();

    int m_cacheSize;
    fileTimestampIndex_t* m_cache;
    std::string* m_cacheIndexArray;
    int m_nextToReplaceInCache;
    std::string m_indexFileName;

public:
    FileTimeIndexer(const std::string& indexFileName, int cacheSize);
    ~FileTimeIndexer();

    void index(const std::string& fileName);
    void index(const std::string& fileName, const timestamp_t& timestamp);
    bool contains(const std::string& fileName);
    timestamp_t get(const std::string& fileName);
    void remove(const std::string& fileName);

    friend FileTimeIndexerTest;
};


#endif // __DFS_FS_FILE_TIME_INDEXER_H__
