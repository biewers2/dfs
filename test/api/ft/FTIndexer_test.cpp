#include <exception>
#include <string>

#include <gtest/gtest.h>

#include "test-util.h"
#include "api/fs/file.h"
#include "FTIndexerTest.h"


TEST_F(FTIndexerTest, test_insert_single) {
    touchFile(FILE_NAME);
    ASSERT_NO_THROW(m_indexer->insert(FILE_NAME, file::getLastModified(FILE_NAME)));
    ASSERT_TRUE(indexRef().count(FILE_NAME) > 0);
    deleteFile(FILE_NAME);
}


TEST_F(FTIndexerTest, test_insert_multiple) {
    for (int i{ 0 }; i < 10; ++i) {
        std::string FILE_NAME_i{ FILE_NAME + std::to_string(i) };
        touchFile(FILE_NAME_i);
        ASSERT_NO_THROW(m_indexer->insert(FILE_NAME_i, file::getLastModified(FILE_NAME_i)));
        ASSERT_TRUE(indexRef().count(FILE_NAME_i) > 0);
        deleteFile(FILE_NAME_i);
    }
}


TEST_F(FTIndexerTest, test_contains_single) {
    touchFile(FILE_NAME);
    ASSERT_NO_THROW(m_indexer->insert(FILE_NAME, file::getLastModified(FILE_NAME)));
    ASSERT_TRUE(m_indexer->contains(FILE_NAME));
    deleteFile(FILE_NAME);
}


TEST_F(FTIndexerTest, test_contains_multiple) {
    for (int i{ 0 }; i < 10; ++i) {
        std::string FILE_NAME_i{ FILE_NAME + std::to_string(i) };
        touchFile(FILE_NAME_i);
        ASSERT_NO_THROW(m_indexer->insert(FILE_NAME_i, file::getLastModified(FILE_NAME_i)));
        deleteFile(FILE_NAME_i);
    }

    ASSERT_TRUE(m_indexer->contains(FILE_NAME + std::to_string(1)));
    ASSERT_TRUE(m_indexer->contains(FILE_NAME + std::to_string(6)));
    ASSERT_TRUE(m_indexer->contains(FILE_NAME + std::to_string(9)));
    ASSERT_FALSE(m_indexer->contains("random-file-name"));
}


TEST_F(FTIndexerTest, test_at_single) {
    touchFile(FILE_NAME);
    ASSERT_NO_THROW(m_indexer->insert(FILE_NAME, file::getLastModified(FILE_NAME)));
    ASSERT_NE(m_indexer->at(FILE_NAME), EMPTY_TIMESTAMP);
    deleteFile(FILE_NAME);
}


TEST_F(FTIndexerTest, test_at_multiple) {
    for (int i{ 0 }; i < 10; ++i) {
        std::string FILE_NAME_i{ FILE_NAME + std::to_string(i) };
        touchFile(FILE_NAME_i);
        ASSERT_NO_THROW(m_indexer->insert(FILE_NAME_i, file::getLastModified(FILE_NAME_i)));
        deleteFile(FILE_NAME_i);
    }
    ASSERT_NE(m_indexer->at(FILE_NAME + std::to_string(0)), EMPTY_TIMESTAMP);
    ASSERT_NE(m_indexer->at(FILE_NAME + std::to_string(3)), EMPTY_TIMESTAMP);
    ASSERT_NE(m_indexer->at(FILE_NAME + std::to_string(8)), EMPTY_TIMESTAMP);
    ASSERT_EQ(m_indexer->at("random-file-name"), EMPTY_TIMESTAMP);
}


TEST_F(FTIndexerTest, test_erase_single) {
    touchFile(FILE_NAME);
    ASSERT_NO_THROW(m_indexer->insert(FILE_NAME, file::getLastModified(FILE_NAME)));
    ASSERT_TRUE(m_indexer->contains(FILE_NAME));
    ASSERT_NO_THROW(m_indexer->erase(FILE_NAME));
    ASSERT_FALSE(m_indexer->contains(FILE_NAME));
    deleteFile(FILE_NAME);
}


TEST_F(FTIndexerTest, test_erase_multiple) {
    for (int i{ 0 }; i < 10; ++i) {
        std::string FILE_NAME_i{ FILE_NAME + std::to_string(i) };
        touchFile(FILE_NAME_i);
        ASSERT_NO_THROW(m_indexer->insert(FILE_NAME_i, file::getLastModified(FILE_NAME_i)));
        deleteFile(FILE_NAME_i);
    }
    ASSERT_NO_THROW(m_indexer->erase(FILE_NAME + std::to_string(2)));
    ASSERT_FALSE(m_indexer->contains(FILE_NAME + std::to_string(2)));
    ASSERT_NO_THROW(m_indexer->erase(FILE_NAME + std::to_string(4)));
    ASSERT_FALSE(m_indexer->contains(FILE_NAME + std::to_string(4)));
    ASSERT_NO_THROW(m_indexer->erase(FILE_NAME + std::to_string(6)));
    ASSERT_FALSE(m_indexer->contains(FILE_NAME + std::to_string(6)));
    ASSERT_NO_THROW(m_indexer->erase("random-file-name"));
}