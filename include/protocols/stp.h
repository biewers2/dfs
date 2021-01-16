#ifndef __DFS_PROTOCOLS_STP_H__
#define __DFS_PROTOCOLS_STP_H__

#include <cstddef> /* size_t */


/* Status Transfer Protocol */
namespace stp {
    enum FileStatus {
        NEWER, OLDER, GOOD
    };

    typedef struct {
        size_t fileNameSize;
    } header_t;

    typedef struct {
        FileStatus status;
        char* fileName;
    } content_t;

    const size_t HEADER_SIZE{ sizeof(header_t) };
    const size_t BODY_SIZE{ sizeof(content_t) };
}


#endif // __DFS_PROTOCOLS_STP_H__
