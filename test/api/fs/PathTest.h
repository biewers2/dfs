#ifndef __DFS_TESTING_PATH_TEST_H__
#define __DFS_TESTING_PATH_TEST_H__

#include <string>

#include <gtest/gtest.h>

#include "fs/DirectoryScanner.h"


class PathTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;

    std::vector<std::string> parseStringPath(const std::string& stringPath);
    void changeSingleDirectory(const std::string& stringFile);

    Path* m_path;
};


#endif // __DFS_TESTING_PATH_TEST_H__