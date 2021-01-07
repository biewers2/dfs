#include <cstdio>

#include <sys/stat.h>

#include "api/file.h"


hash_t
hashContents(const char* fileName) {
    return 0;
}


timestamp_t getLastModified(const char* fileName) {
    return timestamp_t();
}


size_t
getSizeOfFile(FILE* fd) {
    return 0;
}


size_t
getSizeOfFile(const char* fileName) {
    return 0;
}