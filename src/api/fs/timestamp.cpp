#include "api/fs/timestamp.h"


static const std::string TYPE_STRING{ "timestamp_t" };


bool
operator==(const timestamp_t& leftTimestamp, const timestamp_t& rightTimestamp) {
    return leftTimestamp.tv_sec == rightTimestamp.tv_sec
        && leftTimestamp.tv_nsec == rightTimestamp.tv_nsec;
}


bool
operator!=(const timestamp_t& leftTimestamp, const timestamp_t& rightTimestamp) {
    return !(leftTimestamp == rightTimestamp);

}


bool
operator>(const timestamp_t& leftTimestamp, const timestamp_t& rightTimestamp) {
    if (leftTimestamp.tv_sec > rightTimestamp.tv_sec) {
        return true;
    } else if (leftTimestamp.tv_sec == rightTimestamp.tv_sec) {
        return leftTimestamp.tv_nsec > rightTimestamp.tv_nsec;
    } else {
        return false;
    }
}


bool
operator<(const timestamp_t& leftTimestamp, const timestamp_t& rightTimestamp) {
    if (leftTimestamp.tv_sec < rightTimestamp.tv_sec) {
        return true;
    } else if (leftTimestamp.tv_sec == rightTimestamp.tv_sec) {
        return leftTimestamp.tv_nsec < rightTimestamp.tv_nsec;
    } else {
        return false;
    }
}


bool
operator>=(const timestamp_t& leftTimestamp, const timestamp_t& rightTimestamp) {
    return !(leftTimestamp < rightTimestamp);
}


bool
operator<=(const timestamp_t& leftTimestamp, const timestamp_t& rightTimestamp) {
    return !(leftTimestamp > rightTimestamp);
}


std::ostream&
operator<<(std::ostream& outputStream, const timestamp_t& timestamp) {
    return outputStream << TYPE_STRING + '{' << timestamp.tv_sec << ',' << timestamp.tv_nsec << '}';
}


std::istream&
operator>>(std::istream& inputStream, timestamp_t& timestamp) {
    inputStream.ignore(TYPE_STRING.length() + 1, '{');
    inputStream >> timestamp.tv_sec;
    inputStream.ignore(1, ',');
    inputStream >> timestamp.tv_nsec;
    inputStream.ignore(1, '}');
    return inputStream;
}
