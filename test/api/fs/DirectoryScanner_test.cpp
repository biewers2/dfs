#include <exception>
#include <vector>
#include <string>

#include <gtest/gtest.h>

#include "test-util.h"
#include "exceptions/fs.h"
#include "DirectoryScannerTest.h"


TEST_F(DirectoryScannerTest, test_setDirectory) {
    ASSERT_NO_THROW(m_scanner->setDirectory("mock-fs"));
    ASSERT_THROW(m_scanner->setDirectory("non-existent"), FilePathException);
    ASSERT_NO_THROW(m_scanner->setDirectory("mock-fs/unit/test/path"));
}


TEST_F(DirectoryScannerTest, test_getListOfFiles) {
    m_scanner->setDirectory("mock-fs/unit");
    std::vector<std::string> list = m_scanner->getListOfFiles();

    EXPECT_EQ(list.size(), 1);
    ASSERT_TRUE(vectorContainsString(list, MOCK_FILE));
}


TEST_F(DirectoryScannerTest, test_getListOfDirectories) {
    m_scanner->setDirectory("mock-fs/unit");
    std::vector<std::string> list = m_scanner->getListOfDirectories();

    EXPECT_EQ(list.size(), 2);
    ASSERT_TRUE(vectorContainsString(list, MOCK_DIRECTORY_TEST));
    ASSERT_TRUE(vectorContainsString(list, MOCK_DIRECTORY_TEST2));
}


TEST_F(DirectoryScannerTest, test_getListOfDirectories_include_dots) {
    m_scanner->setDirectory("mock-fs/unit");
    std::vector<std::string> list = m_scanner->getListOfDirectories(false);

    EXPECT_EQ(list.size(), 4);
    ASSERT_TRUE(vectorContainsString(list, MOCK_DIRECTORY_TEST));
    ASSERT_TRUE(vectorContainsString(list, MOCK_DIRECTORY_TEST2));
    ASSERT_TRUE(vectorContainsString(list, CURRENT_DIRECTORY));
    ASSERT_TRUE(vectorContainsString(list, PARENT_DIRECTORY));
}


TEST_F(DirectoryScannerTest, test_getListOfAllContents) {
    m_scanner->setDirectory("mock-fs/unit");
    std::vector<std::string> list = m_scanner->getListOfAllContents();

    EXPECT_EQ(list.size(), 3);
    ASSERT_TRUE(vectorContainsString(list, MOCK_FILE));
    ASSERT_TRUE(vectorContainsString(list, MOCK_DIRECTORY_TEST));
    ASSERT_TRUE(vectorContainsString(list, MOCK_DIRECTORY_TEST2));
}


TEST_F(DirectoryScannerTest, test_getListOfAllContents_include_dots) {
    m_scanner->setDirectory("mock-fs/unit");
    std::vector<std::string> list = m_scanner->getListOfAllContents(false);

    EXPECT_EQ(list.size(), 5);
    ASSERT_TRUE(vectorContainsString(list, MOCK_FILE));
    ASSERT_TRUE(vectorContainsString(list, MOCK_DIRECTORY_TEST));
    ASSERT_TRUE(vectorContainsString(list, MOCK_DIRECTORY_TEST2));
    ASSERT_TRUE(vectorContainsString(list, CURRENT_DIRECTORY));
    ASSERT_TRUE(vectorContainsString(list, PARENT_DIRECTORY));
}