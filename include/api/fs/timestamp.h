#ifndef __DFS_FS_TIMESTAMP_H__
#define __DFS_FS_TIMESTAMP_H__

#include <ostream>
#include <istream>
#include <string>


typedef struct timespec timestamp_t;
typedef std::string hashString_t;

const timestamp_t EMPTY_TIMESTAMP{ 0 };

bool operator==(const timestamp_t& leftTimestamp, const timestamp_t& rightTimestamp);
bool operator!=(const timestamp_t& leftTimestamp, const timestamp_t& rightTimestamp);
bool operator>(const timestamp_t& leftTimestamp, const timestamp_t& rightTimestamp);
bool operator<(const timestamp_t& leftTimestamp, const timestamp_t& rightTimestamp);
bool operator>=(const timestamp_t& leftTimestamp, const timestamp_t& rightTimestamp);
bool operator<=(const timestamp_t& leftTimestamp, const timestamp_t& rightTimestamp);

std::ostream& operator<<(std::ostream& outputStream, const timestamp_t& timestamp);
std::istream& operator>>(std::istream& inputStream, timestamp_t& timestamp);


#endif // __DFS_FS_TIMESTAMP_H__
