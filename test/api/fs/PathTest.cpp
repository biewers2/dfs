#include <string>

#include <gtest/gtest.h>

#include "fs/Path.h"
#include "PathTest.h"


void
PathTest::SetUp() {
    this->m_path = new Path("");
}


void
PathTest::TearDown() {
    delete this->m_path;
}


std::vector<std::string>
PathTest::parseStringPath(const std::string& stringPath) {
    return m_path->parseStringPath(stringPath);
}


void
PathTest::changeSingleDirectory(const std::string& stringFile) {
    m_path->changeSingleDirectory(stringFile);
}
