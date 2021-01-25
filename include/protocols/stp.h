#ifndef __DFS_PROTOCOLS_STP_H__
#define __DFS_PROTOCOLS_STP_H__

#include <cstddef> /* size_t */


/* Status Transfer Protocol */
namespace stp {
    enum FileStatus {
        NEWER, OLDER, GOOD
    };

    struct header_t {
        size_t fileNameSize;
    };

    struct content_t {
        FileStatus status;
        char* fileName;
    };

    const size_t HEADER_SIZE{ sizeof(header_t) };
    const size_t BODY_SIZE{ sizeof(content_t) };
}


#endif // __DFS_PROTOCOLS_STP_H__
