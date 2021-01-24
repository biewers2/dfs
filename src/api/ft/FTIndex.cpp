#include <unordered_map>
#include <string>

#include "api/fs/timestamp.h"
#include "FTIndex.h"


FTIndex::FTIndex() {
    index = new std::unordered_map<std::string, timestamp_t>();
}


FTIndex::~FTIndex() {
    delete index;
}
