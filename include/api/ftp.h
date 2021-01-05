#ifndef __DFS_FTP_H__
#define __DFS_FTP_H__

#include <iostream>
#include <limits>

#define FTP_HEADER_SIZE (sizeof(std::streamsize))


inline std::streamsize getFileSizeFromStream(std::ifstream& stream) {
    stream.ignore(std::numeric_limits<std::streamsize>::max());
    std::streamsize charactersInFile = stream.gcount();
    stream.clear();
    stream.seekg(0, std::ios_base::beg);
    return charactersInFile;
}


#endif // __DFS_FTP_H__
