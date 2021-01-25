#ifndef __DFS_FT_INDEX_H__
#define __DFS_FT_INDEX_H__

#include <string>
#include <unordered_map>
#include "api/fs/timestamp.h"


class FileIndexer;
class FileIndexReader;
class FileIndexWriter;

class FileIndex {
protected:
    struct FileIndexData {
        timestamp_t timestamp;
        hashString_t hash;
    };

    static FileIndexData bundleData(const timestamp_t& timestamp, const hashString_t& hash);

    std::unordered_map<std::string, FileIndexData>* m_index;

public:
    FileIndex();
    ~FileIndex();

    friend FileIndexer;
    friend FileIndexReader;
    friend FileIndexWriter;
};


#endif // __DFS_FT_INDEX_H__
