#ifndef __DFS_FT_INDEX_WRITER_H__
#define __DFS_FT_INDEX_WRITER_H__

#include <fstream>
#include "FTIndex.h"


class FTIndexWriter {
private:
    FTIndex* m_indexObject;
    std::ofstream m_outputStream;

public:
    FTIndexWriter(FTIndex* index);
    FTIndexWriter(const std::string& fileName, FTIndex* index);
    ~FTIndexWriter();

    void setIndex(FTIndex* index);
    void setInputFile(const std::string& fileName);

    void write();
};


#endif //__DFS_FT_INDEX_WRITER_H__
