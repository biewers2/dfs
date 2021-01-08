#include <fstream>
#include <string>
#include <unordered_set>
#include <cstdlib>

#include <gtest/gtest.h>

#include "api/file.h"


const char* FILE_NAME{ "FileAPI_randomFile" };


static void
createRandomFile(const std::string& fileName, size_t sizeInBytes) {
    std::ofstream outputStream(fileName);
    EXPECT_TRUE(outputStream.is_open());
    for (int i{ 0 }; i < sizeInBytes; ++i) {
        outputStream << (char) rand();
    }
    outputStream.close();
}


static void
deleteFile(const std::string& fileName) {
    EXPECT_EQ(std::remove(fileName.c_str()), 0);
}


static void
touchFile(const std::string& fileName) {
    // Update timestamp of file.
    std::ofstream touch(fileName);
    touch.close();
}


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
        deleteFile(FILE_NAME);
    }

    delete hashes;
}


TEST(FileAPI, test_getLastModified) {
    createRandomFile(FILE_NAME, 10);
    timestamp_t timeBefore{ getLastModified(FILE_NAME) };
    touchFile(FILE_NAME);
    timestamp_t timeAfter{ getLastModified(FILE_NAME) };
    EXPECT_GT(timeAfter.tv_nsec, timeBefore.tv_nsec);
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