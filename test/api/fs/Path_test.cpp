#include <exception>
#include <vector>
#include <string>

#include "gtest/gtest.h"

#include "exceptions/fs.h"
#include "PathTest.h"


TEST_F(PathTest, test_parseStringPath_absolute) {
    std::vector<std::string> pathList;

    ASSERT_NO_THROW(pathList = parseStringPath("/"));
    EXPECT_EQ(pathList.size(), 1);
    ASSERT_STREQ(pathList.at(0).c_str(), "/");

    ASSERT_NO_THROW(pathList = parseStringPath("/one"));
    EXPECT_EQ(pathList.size(), 2);
    ASSERT_STREQ(pathList.at(0).c_str(), "/");
    ASSERT_STREQ(pathList.at(1).c_str(), "one");

    ASSERT_NO_THROW(pathList = parseStringPath("/one/two/three"));
    EXPECT_EQ(pathList.size(), 4);
    ASSERT_STREQ(pathList.at(0).c_str(), "/");
    ASSERT_STREQ(pathList.at(1).c_str(), "one");
    ASSERT_STREQ(pathList.at(2).c_str(), "two");
    ASSERT_STREQ(pathList.at(3).c_str(), "three");
}


TEST_F(PathTest, test_parseStringPath_relative) {
    std::vector<std::string> pathList;

    ASSERT_NO_THROW(pathList = parseStringPath(""));
    EXPECT_EQ(pathList.size(), 0);

    ASSERT_NO_THROW(pathList = parseStringPath("one"));
    EXPECT_EQ(pathList.size(), 1);
    ASSERT_STREQ(pathList.at(0).c_str(), "one");

    ASSERT_NO_THROW(pathList = parseStringPath("one/two/three"));
    EXPECT_EQ(pathList.size(), 3);
    ASSERT_STREQ(pathList.at(0).c_str(), "one");
    ASSERT_STREQ(pathList.at(1).c_str(), "two");
    ASSERT_STREQ(pathList.at(2).c_str(), "three");
}


TEST_F(PathTest, test_parseStringPath_current) {
    std::vector<std::string> pathList;

    ASSERT_NO_THROW(pathList = parseStringPath("."));
    ASSERT_EQ(pathList.size(), 0);

    ASSERT_NO_THROW(pathList = parseStringPath("././."));
    ASSERT_EQ(pathList.size(), 0);
}


TEST_F(PathTest, test_parseStringPath_previous) {
    std::vector<std::string> pathList;

    ASSERT_NO_THROW(pathList = parseStringPath("one/.."));
    EXPECT_EQ(pathList.size(), 0);

    ASSERT_NO_THROW(pathList = parseStringPath("one/../two/three/.."));
    EXPECT_EQ(pathList.size(), 1);
    ASSERT_STREQ(pathList.at(0).c_str(), "two");

    ASSERT_NO_THROW(pathList = parseStringPath(".."));
    EXPECT_EQ(pathList.size(), 0);
}


TEST_F(PathTest, test_parseStringPath_ending) {
    std::vector<std::string> pathList;

    ASSERT_NO_THROW(pathList = parseStringPath("one/"));
    EXPECT_EQ(pathList.size(), 1);
    ASSERT_STREQ(pathList.at(0).c_str(), "one");

    ASSERT_NO_THROW(pathList = parseStringPath("/one/two/"));
    EXPECT_EQ(pathList.size(), 3);
    ASSERT_STREQ(pathList.at(0).c_str(), "/");
    ASSERT_STREQ(pathList.at(1).c_str(), "one");
    ASSERT_STREQ(pathList.at(2).c_str(), "two");
}


TEST_F(PathTest, test_parseStringPath_bad_format) {
    std::vector<std::string> pathList;

    ASSERT_THROW(pathList = parseStringPath("//"), FilePathParseException);
    ASSERT_THROW(pathList = parseStringPath("/one/two//"), FilePathParseException);
    ASSERT_THROW(pathList = parseStringPath("/one/two//three"), FilePathParseException);
}


TEST_F(PathTest, test_constructor) {
    Path path("");
    std::vector<std::string> pathList;

    ASSERT_NO_THROW(path = Path("/one/two"));
    pathList = path.getComponents();
    EXPECT_EQ(pathList.size(), 2);
    ASSERT_STREQ(pathList.at(0).c_str(), "one");
    ASSERT_STREQ(pathList.at(1).c_str(), "two");
    ASSERT_TRUE(path.isAbsolute());

    ASSERT_NO_THROW(path = Path("/one/../two/three/../four"));
    pathList = path.getComponents();
    EXPECT_EQ(pathList.size(), 2);
    ASSERT_STREQ(pathList.at(0).c_str(), "two");
    ASSERT_STREQ(pathList.at(1).c_str(), "four");
    ASSERT_TRUE(path.isAbsolute());
}


//TEST_F(PathTest, test_changeDirectory_single) {
//    std::vector<std::string> pathList;
//
//    m_path->changeDirectory("one");
//    EXPECT_EQ(m_path->getComponents())
//}