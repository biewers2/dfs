#ifndef __DFS_UTIL_FT_QUEUE_H__
#define __DFS_UTIL_FT_QUEUE_H__

#include <string>
#include "api/ft/timestamp.h"
#include "api/ft/ft-types.h"


class FTQueue {
private:
    ftQueue_t* m_queue;

public:
    FTQueue();
    ~FTQueue();

    size_t size();

    ftIterator_t find(const std::string& fileNameEntry);
    bool contains(const std::string& fileNameEntry);

    void enqueue(const ftPair_t& entry);
    ftPair_t dequeue();

    void set(const std::string& fileName, const timestamp_t& timestamp);
    void set(const ftIterator_t& position, const timestamp_t& timestamp);
    void insert(const ftIterator_t& position, const ftPair_t& entry);
    ftPair_t erase(const ftIterator_t& position);

    ftIterator_t begin();
    ftIterator_t end();
};


#endif // __DFS_UTIL_FT_QUEUE_H__
