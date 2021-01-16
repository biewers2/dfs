#ifndef __DFS_TESTING_DIRECTORY_SCANNER_TEST_H__
#define __DFS_TESTING_DIRECTORY_SCANNER_TEST_H__

#include <string>

#include <gtest/gtest.h>

#include "fs/DirectoryScanner.h"


const std::string MOCK_FILE{ "mock-file" };
const std::string MOCK_DIRECTORY_TEST{ "test" };
const std::string MOCK_DIRECTORY_TEST2{ "test2" };
const std::string CURRENT_DIRECTORY{ "." };
const std::string PARENT_DIRECTORY{ ".." };


class DirectoryScannerTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;

    DirectoryScanner* m_scanner;
};


#endif // __DFS_TESTING_DIRECTORY_SCANNER_TEST_H__