#ifndef __DFS_FT_INDEX_READER_H__
#define __DFS_FT_INDEX_READER_H__

#include <fstream>
#include "FileIndex.h"


class FileIndexReader {
private:
    bool parseIndexEntry(std::stringstream& ss, std::pair<std::string, FileIndex::FileIndexData>& entry);

    FileIndex* m_indexObject;
    std::ifstream m_inputStream;

public:
    FileIndexReader(FileIndex* index);
    FileIndexReader(const std::string& fileName, FileIndex* index);
    ~FileIndexReader();

    void setIndex(FileIndex* index);
    void setInputFile(const std::string& fileName);

    void read();
};


#endif //__DFS_FT_INDEX_READER_H__
