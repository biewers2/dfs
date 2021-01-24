#include <exception>
#include <vector>
#include <string>

#include <gtest/gtest.h>

#include "test-util.h"
#include "exceptions/fs.h"
#include "DirectoryScannerTest.h"


static const std::string MOCK_FILE_NAME{ "mock-file" };
static const std::string TEST_NAME{ "test" };
static const std::string TEST2_NAME{ "test2" };
static const std::string CURRENT_DIR{ "." };
static const std::string PARENT_DIR{ ".." };


TEST_F(DirectoryScannerTest, test_setDirectory) {
    ASSERT_NO_THROW(m_scanner->setDirectory(ROOT + "test"));
    ASSERT_THROW(m_scanner->setDirectory("non-existent"), FilePathException);
    ASSERT_NO_THROW(m_scanner->setDirectory(ROOT + "test/path"));
}


TEST_F(DirectoryScannerTest, test_getListOfFiles) {
    m_scanner->setDirectory(ROOT);
    std::vector<std::string> list = m_scanner->getListOfFiles();

    EXPECT_EQ(list.size(), 1);
    ASSERT_TRUE(vectorContainsString(list, MOCK_FILE_NAME));
}


TEST_F(DirectoryScannerTest, test_getListOfDirectories) {
    m_scanner->setDirectory("resources/DirectoryScannerTest");
    std::vector<std::string> list = m_scanner->getListOfDirectories();

    EXPECT_EQ(list.size(), 2);
    ASSERT_TRUE(vectorContainsString(list, TEST_NAME));
    ASSERT_TRUE(vectorContainsString(list, TEST2_NAME));
}


TEST_F(DirectoryScannerTest, test_getListOfDirectories_include_dots) {
    m_scanner->setDirectory("resources/DirectoryScannerTest");
    std::vector<std::string> list = m_scanner->getListOfDirectories(false);

    EXPECT_EQ(list.size(), 4);
    ASSERT_TRUE(vectorContainsString(list, TEST_NAME));
    ASSERT_TRUE(vectorContainsString(list, TEST2_NAME));
    ASSERT_TRUE(vectorContainsString(list, CURRENT_DIR));
    ASSERT_TRUE(vectorContainsString(list, PARENT_DIR));
}


TEST_F(DirectoryScannerTest, test_getListOfAllContents) {
    m_scanner->setDirectory("resources/DirectoryScannerTest");
    std::vector<std::string> list = m_scanner->getListOfAllContents();

    EXPECT_EQ(list.size(), 3);
    ASSERT_TRUE(vectorContainsString(list, MOCK_FILE_NAME));
    ASSERT_TRUE(vectorContainsString(list, TEST_NAME));
    ASSERT_TRUE(vectorContainsString(list, TEST2_NAME));
}


TEST_F(DirectoryScannerTest, test_getListOfAllContents_include_dots) {
    m_scanner->setDirectory("resources/DirectoryScannerTest");
    std::vector<std::string> list = m_scanner->getListOfAllContents(false);

    EXPECT_EQ(list.size(), 5);
    ASSERT_TRUE(vectorContainsString(list, MOCK_FILE_NAME));
    ASSERT_TRUE(vectorContainsString(list, TEST_NAME));
    ASSERT_TRUE(vectorContainsString(list, TEST2_NAME));
    ASSERT_TRUE(vectorContainsString(list, CURRENT_DIR));
    ASSERT_TRUE(vectorContainsString(list, PARENT_DIR));
}