#ifndef __DFS_TESTING_RESOURCE_TEST_H__
#define __DFS_TESTING_RESOURCE_TEST_H__

#include <gtest/gtest.h>


class ResourceTest : public ::testing::Test {
protected:
    virtual std::string buildResourcesPath(const std::string& pathString) = 0;
};


#endif // __DFS_TESTING_RESOURCE_TEST_H__
