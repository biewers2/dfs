#ifndef __DFS_PROTOCOLS_HTP_H__
#define __DFS_PROTOCOLS_HTP_H__

#include <cstddef> /* size_t */


/* Hash Transfer Protocol */
namespace htp {
    struct header_t {
        size_t fileNameSize;
        size_t hashSize;
    };

    struct content_t {
        char* fileName;
        char* hash;
    };

    const size_t HEADER_SIZE{ sizeof(header_t) };
    const size_t CONTENT_SIZE{ sizeof(content_t) };
}


#endif // __DFS_PROTOCOLS_HTP_H__
