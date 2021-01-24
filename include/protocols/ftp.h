#ifndef __DFS_PROTOCOLS_FTP_H__
#define __DFS_PROTOCOLS_FTP_H__

#include <cstddef> /* size_t */


/* File Transfer Protocol */
namespace ftp {
    struct header_t {
        size_t fileSize;
    };

    const size_t HEADER_SIZE{ sizeof(header_t) };
};


#endif // __DFS_PROTOCOLS_FTP_H__
