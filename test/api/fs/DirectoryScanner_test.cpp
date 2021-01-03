#include <exception>
#include <vector>
#include <string>

#include "exceptions/fs.h"
#include "gtest/gtest.h"

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


TEST_F(DirectoryScannerTest, test_getListOfAllContents) {
    m_scanner->setPath(Path("mock-fs/unit"));
    std::vector<std::string> list = m_scanner->getListOfAllContents();

    EXPECT_EQ(list.size(), 3);
    ASSERT_TRUE(listContainsString(list, MOCK_FILE));
    ASSERT_TRUE(listContainsString(list, MOCK_DIRECTORY_TEST));
    ASSERT_TRUE(listContainsString(list, MOCK_DIRECTORY_TEST2));
}
