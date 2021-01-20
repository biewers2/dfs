#include <unordered_map>

#include "IndexFileIteratorTest.h"


static const std::unordered_map<std::string, timestamp_t> PAIRS{
        {"file1", timestamp_t{ .tv_sec=123, .tv_nsec=456 }},
        {"file2", timestamp_t{ .tv_sec=100, .tv_nsec=200 }},
        {"file3", timestamp_t{ .tv_sec=902, .tv_nsec=513 }},
        {"file4", timestamp_t{ .tv_sec=135, .tv_nsec=246 }},
        {"file5", timestamp_t{ .tv_sec=333, .tv_nsec=555 }}
};


TEST_F(IndexFileIteratorTest, test_basic) {
    while (m_iterator->hasNext()) {
        fileTimestampPair_t pair{ m_iterator->next() };
        ASSERT_TRUE(PAIRS.count(pair.first) > 0);
        ASSERT_EQ(PAIRS.at(pair.first), pair.second);
    }
}