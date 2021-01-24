#ifndef __DFS_FT_INDEX_H__
#define __DFS_FT_INDEX_H__

#include <string>
#include <unordered_map>
#include "api/fs/timestamp.h"


class FTIndex {
public:
    FTIndex();
    ~FTIndex();

    std::unordered_map<std::string, timestamp_t>* index;
};


#endif // __DFS_FT_INDEX_H__
