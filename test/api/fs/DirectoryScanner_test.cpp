#include <exception>
#include <vector>
#include <string>

#include <gtest/gtest.h>

#include "exceptions/fs.h"
#include "DirectoryScannerTest.h"


TEST_F(DirectoryScannerTest, test_setPath) {
    ASSERT_NO_THROW(m_scanner->setPath(Path("mock-fs")));
    ASSERT_THROW(m_scanner->setPath(Path("non-existent")), FilePathException);
    ASSERT_NO_THROW(m_scanner->setPath(Path("mock-fs/unit/test/path")));
}


TEST_F(DirectoryScannerTest, test_getListOfFiles) {
    m_scanner->setPath(Path("mock-fs/unit"));
    std::vector<std::string> list = m_scanner->getListOfFiles();

    EXPECT_EQ(list.size(), 1);
    ASSERT_TRUE(listContainsString(list, MOCK_FILE));
}


TEST_F(DirectoryScannerTest, test_getListOfDirectories) {
    m_scanner->setPath(Path("mock-fs/unit"));
    std::vector<std::string> list = m_scanner->getListOfDirectories();

    EXPECT_EQ(list.size(), 2);
    ASSERT_TRUE(listContainsString(list, MOCK_DIRECTORY_TEST));
    ASSERT_TRUE(listContainsString(list, MOCK_DIRECTORY_TEST2));
}


TEST_F(DirectoryScannerTest, test_getListOfDirectories_include_dots) {
    m_scanner->setPath(Path("mock-fs/unit"));
    std::vector<std::string> list = m_scanner->getListOfDirectories(false);

    EXPECT_EQ(list.size(), 4);
    ASSERT_TRUE(listContainsString(list, MOCK_DIRECTORY_TEST));
    ASSERT_TRUE(listContainsString(list, MOCK_DIRECTORY_TEST2));
    ASSERT_TRUE(listContainsString(list, CURRENT_DIRECTORY));
    ASSERT_TRUE(listContainsString(list, PARENT_DIRECTORY));
}


TEST_F(DirectoryScannerTest, test_getListOfAllContents) {
    m_scanner->setPath(Path("mock-fs/unit"));
    std::vector<std::string> list = m_scanner->getListOfAllContents();

    EXPECT_EQ(list.size(), 3);
    ASSERT_TRUE(listContainsString(list, MOCK_FILE));
    ASSERT_TRUE(listContainsString(list, MOCK_DIRECTORY_TEST));
    ASSERT_TRUE(listContainsString(list, MOCK_DIRECTORY_TEST2));
}


TEST_F(DirectoryScannerTest, test_getListOfAllContents_include_dots) {
    m_scanner->setPath(Path("mock-fs/unit"));
    std::vector<std::string> list = m_scanner->getListOfAllContents(false);

    EXPECT_EQ(list.size(), 5);
    ASSERT_TRUE(listContainsString(list, MOCK_FILE));
    ASSERT_TRUE(listContainsString(list, MOCK_DIRECTORY_TEST));
    ASSERT_TRUE(listContainsString(list, MOCK_DIRECTORY_TEST2));
    ASSERT_TRUE(listContainsString(list, CURRENT_DIRECTORY));
    ASSERT_TRUE(listContainsString(list, PARENT_DIRECTORY));
}