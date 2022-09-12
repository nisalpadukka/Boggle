//
// Created by Nisal Padukka on 2022-09-12.
//

#include "gtest/gtest.h"
#include "wordfinder/WordFinderDfs.h"
#include "TestUtils.h"


namespace boggletest {
    class TestDictionary : public testing::Test {
    protected:
        boggle::Dictionary m_dictionary;

        void SetUp() override{
            m_dictionary.add("ANY");
            m_dictionary.add("CHANT");
            m_dictionary.add("PANEL");
            m_dictionary.add("PATH");
            m_dictionary.add("TRENCH");
        }
    };

    TEST_F(TestDictionary, testExists) {
        m_dictionary.add("TEST1");
        EXPECT_TRUE(m_dictionary.exists("TEST1"));
        EXPECT_FALSE(m_dictionary.exists("TEST2"));
    }

    TEST_F(TestDictionary, testGetScore) {
        EXPECT_EQ(m_dictionary.getScore("ANY"), 1);
        EXPECT_EQ(m_dictionary.getScore("CHANT"), 2);
        EXPECT_EQ(m_dictionary.getScore("PANEL"), 2);
        EXPECT_EQ(m_dictionary.getScore("PATH"), 1);
        EXPECT_EQ(m_dictionary.getScore("TRENCH"), 3);
    }

    TEST_F(TestDictionary, testGetScoreInvalid) {
        EXPECT_THROW_WITH_MESSAGE(m_dictionary.getScore("INVALID"), invalid_argument, "Not in dictionary INVALID");
    }
}
