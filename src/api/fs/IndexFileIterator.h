#ifndef __DFS_FS_INDEX_FILE_ITERATOR_H__
#define __DFS_FS_INDEX_FILE_ITERATOR_H__

#include <fstream>
#include "api/fs/timestamp.h"


typedef std::pair<std::string, timestamp_t> fileTimestampPair_t;

class IndexFileIteratorTest;

class IndexFileIterator {
private:

    void prepareNext();

    std::ifstream m_stream;
    fileTimestampPair_t* m_nextItem{ nullptr };

public:
    IndexFileIterator(const std::string& fileName);
    ~IndexFileIterator();

    bool hasNext();
    fileTimestampPair_t next();

    friend IndexFileIteratorTest;
};


#endif // __DFS_FS_INDEX_FILE_ITERATOR_H__
