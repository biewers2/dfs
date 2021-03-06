#include <string>
#include <unordered_set>

#include <gtest/gtest.h>

#include "test-util.h"
#include "api/fs/file.h"


const char* FILE_NAME{ "FileAPI_randomFile" };


TEST(FileAPI, test_hashContents_single_large) {
    createRandomFile(FILE_NAME, 10000);
    ASSERT_NO_THROW(hashContents(FILE_NAME));
    deleteFile(FILE_NAME);
}


TEST(FileAPI, test_hashContents_many_small) {
    std::unordered_set<hashString_t>* hashes = new std::unordered_set<hashString_t>();

    for (int i{ 0 }; i < 1000; ++i) {
        const std::string FILE_NAME_i{ FILE_NAME + std::to_string(i) };
        createRandomFile(FILE_NAME_i, 10);
        hashString_t value{ hashContents(FILE_NAME_i) };
        EXPECT_EQ(hashes->count(value), 0);
        hashes->insert(value);
        deleteFile(FILE_NAME_i);
    }

    delete hashes;
}


TEST(FileAPI, test_getLastModified) {
    createRandomFile(FILE_NAME, 10);
    timestamp_t timeBefore{ getLastModified(FILE_NAME) };
    touchFile(FILE_NAME);
    timestamp_t timeAfter{ getLastModified(FILE_NAME) };
    EXPECT_GE(timeAfter.tv_nsec, timeBefore.tv_nsec);
    deleteFile(FILE_NAME);
}


TEST(FileAPI, test_getSizeOfFile_descriptor) {
    createRandomFile(FILE_NAME, 10);
    FILE* fd{ fopen(FILE_NAME, "r") };
    EXPECT_EQ(getSizeOfFile(fd), 10);
    deleteFile(FILE_NAME);
}


TEST(FileAPI, test_getSizeOfFile_file_name) {
    createRandomFile(FILE_NAME, 10);
    EXPECT_EQ(getSizeOfFile(FILE_NAME), 10);
    deleteFile(FILE_NAME);
}