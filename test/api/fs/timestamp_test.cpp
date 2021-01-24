#include <gtest/gtest.h>
#include <fstream>

#include "test-util.h"
#include "api/fs/file.h"
#include "api/fs/timestamp.h"


static const char* FILE_NAME{ "TimestampAPI_randomFile" };


TEST(TimestampAPI, test_operator_EQ) {
    timestamp_t t1, t2;

    // All equal.
    t1 = { .tv_sec = 12345, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 == t2);

    // nsec not equal.
    t1 = { .tv_sec = 12345, .tv_nsec = 67891 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_FALSE(t1 == t2);

    // sec not equal.
    t1 = { .tv_sec = 12346, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_FALSE(t1 == t2);
}


TEST(TimestampAPI, test_operator_NE) {
    timestamp_t t1, t2;

    // sec not equal.
    t1 = { .tv_sec = 12346, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 != t2);

    // nsec not equal.
    t1 = { .tv_sec = 12345, .tv_nsec = 67891 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 != t2);

    // All equal.
    t1 = { .tv_sec = 12345, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_FALSE(t1 != t2);
}


TEST(TimestampAPI, test_operator_GT) {
    timestamp_t t1, t2;

    // sec greater than.
    t1 = { .tv_sec = 12346, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 > t2);

    // nsec greater than.
    t1 = { .tv_sec = 12345, .tv_nsec = 67891 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 > t2);

    // All equal
    t1 = { .tv_sec = 12345, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_FALSE(t1 > t2);
}


TEST(TimestampAPI, test_operator_LT) {
    timestamp_t t1, t2;

    // sec less than.
    t1 = { .tv_sec = 12344, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 < t2);

    // nsec less than.
    t1 = { .tv_sec = 12345, .tv_nsec = 67889 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 < t2);

    // All equal.
    t1 = { .tv_sec = 12345, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_FALSE(t1 > t2);
}


TEST(TimestampAPI, test_operator_GE) {
    timestamp_t t1, t2;

    /* GT Tests. */

    // sec greater than.
    t1 = { .tv_sec = 12346, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 > t2);

    // nsec greater than.
    t1 = { .tv_sec = 12345, .tv_nsec = 67891 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 > t2);

    // All equal
    t1 = { .tv_sec = 12345, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_FALSE(t1 > t2);

    /* EQ Tests. */

    // All equal.
    t1 = { .tv_sec = 12345, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 == t2);

    // nsec not equal.
    t1 = { .tv_sec = 12345, .tv_nsec = 67891 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_FALSE(t1 == t2);

    // sec not equal.
    t1 = { .tv_sec = 12346, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_FALSE(t1 == t2);
}


TEST(TimestampAPI, test_operator_LE) {
    timestamp_t t1, t2;

    /* LT Tests. */

    // sec less than.
    t1 = { .tv_sec = 12344, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 < t2);

    // nsec less than.
    t1 = { .tv_sec = 12345, .tv_nsec = 67889 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 < t2);

    // All equal.
    t1 = { .tv_sec = 12345, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_FALSE(t1 > t2);

    /* EQ Tests. */

    // All equal.
    t1 = { .tv_sec = 12345, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_TRUE(t1 == t2);

    // nsec not equal.
    t1 = { .tv_sec = 12345, .tv_nsec = 67891 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_FALSE(t1 == t2);

    // sec not equal.
    t1 = { .tv_sec = 12346, .tv_nsec = 67890 };
    t2 = { .tv_sec = 12345, .tv_nsec = 67890 };
    ASSERT_FALSE(t1 == t2);
}


TEST(TimestampAPI, test_operator_OStream) {
    std::ofstream outputStream(FILE_NAME);
    ASSERT_NO_THROW(outputStream << (timestamp_t{ .tv_sec = 12345, .tv_nsec = 67890 }) << '\n');
    outputStream.close();

    std::string holderString;
    std::ifstream inputStream(FILE_NAME);
    inputStream >> holderString;
    deleteFile(FILE_NAME);
    ASSERT_STREQ(holderString.c_str(), "timestamp_t{12345,67890}");
}


TEST(TimestampAPI, test_operator_IStream) {
    std::ofstream outputStream(FILE_NAME);
    ASSERT_NO_THROW(outputStream << (timestamp_t{ .tv_sec = 12345, .tv_nsec = 67890 }) << '\n');
    outputStream.close();

    timestamp_t timestampHolder{};
    std::ifstream inputStream(FILE_NAME);
    inputStream >> timestampHolder;
    outputStream.close();
    deleteFile(FILE_NAME);
    ASSERT_EQ(timestampHolder, (timestamp_t{ .tv_sec = 12345, .tv_nsec = 67890 }));
}
