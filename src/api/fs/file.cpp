#include <string>
#include <cstdio>

#include <sys/stat.h>

#include "api/file.h"


hash_t
hashContents(const std::string& fileName) {
    return 0;
}


timestamp_t getLastModified(const std::string& fileName) {
    return timestamp_t();
}


size_t
getSizeOfFile(FILE* fd) {
    long currPosition{ ftell(fd) };
    fseek(fd, 0L, SEEK_END);

    long size{ ftell(fd) };
    fseek(fd, currPosition, SEEK_SET);

    return size;
}


size_t
getSizeOfFile(const std::string& fileName) {
    FILE* fd{ fopen(fileName.c_str(), "r") };
    size_t size{ getSizeOfFile(fd) };
    fclose(fd);
    return size;
}