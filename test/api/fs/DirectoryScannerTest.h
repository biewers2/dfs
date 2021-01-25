#ifndef __DFS_TESTING_DIRECTORY_SCANNER_TEST_H__
#define __DFS_TESTING_DIRECTORY_SCANNER_TEST_H__

#include <string>

#include <gtest/gtest.h>

#include "fs/DirectoryScanner.h"


class DirectoryScannerTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;

    const std::string ROOT{ "resources/DirectoryScannerTest/" };

    DirectoryScanner* m_scanner;
};


#endif // __DFS_TESTING_DIRECTORY_SCANNER_TEST_H__