#ifndef __DFS_UTIL_STP_BUILDER_H__
#define __DFS_UTIL_STP_BUILDER_H__

#include <string>

#include "protocols/stp.h"


class STPBuilder {
public:
    void buildEmpty(const stp::header_t* header, stp::content_t* dataHolder);
    void build(const std::string& fileName, const stp::FileStatus status, stp::header_t* headerHolder, stp::content_t* dataHolder);
    void destroy(stp::content_t* data);
};


#endif // __DFS_UTIL_STP_BUILDER_H__
