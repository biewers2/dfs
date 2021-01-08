#include <fstream>
#include <string>
#include <unordered_set>
#include <cstdlib>

#include <gtest/gtest.h>

#include "api/file.h"


void
createRandomFile(const std::string& fileName) {
    std::ofstream outputStream(fileName);
    outputStream << rand();
    outputStream.close();
}


void
deleteFile(const std::string& fileName) {
    EXPECT_EQ(std::remove(fileName.c_str()), 0);
}


TEST(FileAPI, test_hashContents_single) {
    const char* FILE_NAME{ "FileAPI_randomFile1" };
    createRandomFile(FILE_NAME);
    EXPECT_GT(hashContents(FILE_NAME), 0);
    deleteFile(FILE_NAME);
}


TEST(FileAPI, test_hashContents_massive) {
    const std::string FILE_NAME_BASE{ "FileAPI_randomFile" };
    std::unordered_set<hash_t>* hashes = new std::unordered_set<hash_t>();
    std::unordered_set<std::string>* fileNames = new std::unordered_set<std::string>();

    for (int i{ 0 }; i < 1000; ++i) {
        const std::string FILE_NAME{ FILE_NAME_BASE + std::to_string(i) };
        createRandomFile(FILE_NAME);

        hash_t value{ hashContents(FILE_NAME) };
        EXPECT_EQ(hashes->count(value), 0);

        fileNames->insert(FILE_NAME);
        hashes->insert(value);
    }
    for (const std::string& fileName : *fileNames) {
        deleteFile(fileName);
    }

    delete hashes;
    delete fileNames;
}


TEST(FileAPI, test_getLastModified) {
    FAIL();
}


TEST(FileAPI, test_getSizeOfFile_descriptor) {
    FAIL();
}


TEST(FileAPI, test_getSizeOfFile_file_name) {
    FAIL();
}