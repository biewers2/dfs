#ifndef __DFS_FS_FILE_TIME_INDEXER_H__
#define __DFS_FS_FILE_TIME_INDEXER_H__

#include <vector>
#include <string>

#include "FTQueue.h"
#include "IndexFileIterator.h" /* ftPair_t */
#include "api/fs/file.h"


class FTIndexerTest;

class FTIndexer {
private:
    void placeInCache(const ftPair_t& pair);

    timestamp_t retrieveFromIndexFile(const std::string& fileNameKey);
    void eraseFromIndexFile(const std::string& fileNameKey);
    void eraseFromIndexFile(std::vector<std::string> fileNameKey);

    void writeCacheToIndex();
    void writeCacheEntryToIndex(const ftPair_t& entry);

    int m_cacheSize;
    FTQueue* m_cacheQueue;
    std::string m_indexFileName;

public:
    __FTIndexer(const std::string& indexFileName, int cacheSize);
    ~__FTIndexer();

    void index(const std::string& fileName);
    void index(const std::string& fileName, const timestamp_t& timestamp);

    bool contains(const std::string& fileName);
    timestamp_t get(const std::string& fileName);
    void erase(const std::string& fileName);

    friend FileTimeIndexerTest;
};


#endif // __DFS_FS_FILE_TIME_INDEXER_H__
