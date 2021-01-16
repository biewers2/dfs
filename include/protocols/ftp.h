#ifndef __DFS_PROTOCOLS_FTP_H__
#define __DFS_PROTOCOLS_FTP_H__

#include <cstddef> /* size_t */


/* File Transfer Protocol */
namespace ftp {
    typedef struct {
        size_t fileSize;
    } header_t;

    const size_t HEADER_SIZE{ sizeof(header_t) };
};


#endif // __DFS_PROTOCOLS_FTP_H__
