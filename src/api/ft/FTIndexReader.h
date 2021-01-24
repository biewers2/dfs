#ifndef __DFS_FT_INDEX_READER_H__
#define __DFS_FT_INDEX_READER_H__

#include <fstream>
#include "FTIndex.h"


class FTIndexReader {
private:
    FTIndex* m_indexObject;
    std::ifstream m_inputStream;

public:
    FTIndexReader(FTIndex* index);
    FTIndexReader(const std::string& fileName, FTIndex* index);
    ~FTIndexReader();

    void setIndex(FTIndex* index);
    void setInputFile(const std::string& fileName);

    void read();
};


#endif //__DFS_FT_INDEX_READER_H__
