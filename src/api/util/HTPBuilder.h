#ifndef __DFS_UTIL_HTP_BUILDER_H__
#define __DFS_UTIL_HTP_BUILDER_H__

#include <string>

#include "protocols/htp.h"


class HTPBuilder {
public:
    void buildEmpty(const htp::header_t* header, htp::content_t* dataHolder);
    void build(const std::string& fileName, htp::header_t* headerHolder, htp::content_t* dataHolder);
    void destroy(htp::content_t* data);
};


#endif // __DFS_UTIL_HTP_BUILDER_H__
