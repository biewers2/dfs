#ifndef __DFS_FILE_H__
#define __DFS_FILE_H__

#include <string>
#include <cstdio>


typedef struct timespec timestamp_t;
typedef std::string hashString_t;

enum FileStatus {
    GOOD, NEWER, OLDER
};

std::string hashContents(const std::string& fileName);

timestamp_t getLastModified(const std::string& fileName);

size_t getSizeOfFile(FILE* fd);
size_t getSizeOfFile(const std::string& fileName);

bool fileExists(const std::string& fileName);


#endif // __DFS_FILE_H__
