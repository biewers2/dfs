#ifndef __DFS_FT_INDEX_WRITER_H__
#define __DFS_FT_INDEX_WRITER_H__

#include <fstream>
#include "FileIndex.h"


class FileIndexWriter {
private:
    FileIndex* m_indexObject;
    std::string m_outputFileName;

public:
    FileIndexWriter(FileIndex* index);
    FileIndexWriter(const std::string& fileName, FileIndex* index);

    void setIndex(FileIndex* index);
    void setOutputFile(const std::string& fileName);

    void write();
};


#endif //__DFS_FT_INDEX_WRITER_H__
