#ifndef __DFS_FS_FILE_H__
#define __DFS_FS_FILE_H__

#include <string>
#include <cstdio>
#include "timestamp.h"


namespace file {

using timestamp_t = struct timespec;
using hashString_t = std::string;

enum FileStatus {
    GOOD, NEWER, OLDER
};

std::string hashContents(const std::string &fileName);

std::string hashContents(const std::string& fileName);

timestamp_t getLastModified(const std::string &fileName);

size_t getSizeOfFile(FILE *fd);

size_t getSizeOfFile(const std::string &fileName);

bool fileExists(const std::string &fileName);


};

#endif // __DFS_FS_FILE_H__
