#ifndef __DFS_FS_INDEX_FILE_ITERATOR_H__
#define __DFS_FS_INDEX_FILE_ITERATOR_H__

#include <fstream>
#include "api/ft/ft-types.h"
#include "api/ft/timestamp.h"


class IndexFileIteratorTest;

class IndexFileIterator {
private:
    void prepareNext();

    std::ifstream m_inputStream;
    ftPair_t* m_nextItem{ nullptr };

public:
    IndexFileIterator(const std::string& fileName);
    ~IndexFileIterator();

    void close();

    bool hasNext();
    ftPair_t next();

    friend IndexFileIteratorTest;
};


#endif // __DFS_FS_INDEX_FILE_ITERATOR_H__
