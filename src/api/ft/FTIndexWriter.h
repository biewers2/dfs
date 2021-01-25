#ifndef __DFS_FT_INDEX_WRITER_H__
#define __DFS_FT_INDEX_WRITER_H__

#include <fstream>
#include "FTIndex.h"


class FTIndexWriter {
private:
    FTIndex* m_indexObject;
    std::string m_outputFileName;

public:
    FTIndexWriter(FTIndex* index);
    FTIndexWriter(const std::string& fileName, FTIndex* index);

    void setIndex(FTIndex* index);
    void setOutputFile(const std::string& fileName);

    void write();
};


#endif //__DFS_FT_INDEX_WRITER_H__
