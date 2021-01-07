#ifndef __DFS_FILE_H__
#define __DFS_FILE_H__

#include <fstream>


typedef size_t hash_t;

enum FileStatus {
    GOOD, NEWER, OLDER
};

hash_t hashContents(const std::ifstream& fileToHash);

std::streamsize getSizeOfStream(std::ifstream& stream);


#endif // __DFS_FILE_H__
