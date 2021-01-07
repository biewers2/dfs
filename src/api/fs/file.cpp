#include <fstream>
#include <limits>

#include "api/file.h"


hash_t
hashContents(const std::ifstream& fileToHash) {
    return 0;
}


struct timespec getLastModified(const std::ifstream& ) {
    return (struct timespec){};
}


std::streamsize
getSizeOfStream(std::ifstream& stream) {
    stream.ignore(std::numeric_limits<std::streamsize>::max());
    std::streamsize size{ stream.gcount() };
    stream.clear();
    stream.seekg(0, std::ios_base::beg);
    return size;
}