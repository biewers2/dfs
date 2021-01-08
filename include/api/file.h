#ifndef __DFS_FILE_H__
#define __DFS_FILE_H__

#include <string>
#include <cstdio>


typedef size_t hash_t;
typedef struct timespec timestamp_t;

enum FileStatus {
    GOOD, NEWER, OLDER
};

hash_t hashContents(const std::string& fileName);

timestamp_t getLastModified(const std::string& fileName);

size_t getSizeOfFile(FILE* fd);
size_t getSizeOfFile(const std::string& fileName);


#endif // __DFS_FILE_H__
