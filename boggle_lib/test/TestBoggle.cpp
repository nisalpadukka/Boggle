//
// Created by Nisal Padukka on 2022-09-12.
//

#include "gtest/gtest.h"
#include "Boggle.h"
#include "wordfinder/WordFinderNaive.h"
#include "wordfinder/WordFinderDfs.h"


namespace boggletest {
    class BoggleTest : public testing::Test {
    protected:
        unique_ptr<boggle::wordfinder::WordFinder> m_wordFinder;
        boggle::Dictionary m_dictionary;
        boggle::GameBoardSnapshot m_gameBoardSnapshot;

        void SetUp() override{
            m_dictionary.add("ANY");
            m_dictionary.add("CHANT");
            m_dictionary.add("PANEL");
            m_dictionary.add("PATH");
            m_dictionary.add("TRENCH");
            m_gameBoardSnapshot = {{'Y', 'A', 'T','R'}, {'P', 'H', 'N','E'}, {'X', 'C', 'L','Y'}, {'S', 'V', 'E', 'Q'}};
        }
    };

    TEST_F(BoggleTest, testBoogleNaive) {
        m_wordFinder.reset(new boggle::wordfinder::WordFinderNaive());
        boggle::Boggle boggle(m_gameBoardSnapshot, m_dictionary, m_wordFinder);
        EXPECT_EQ(boggle.computeScore(), 9);
    }

    TEST_F(BoggleTest, testBoogleDfs) {
        m_wordFinder.reset(new boggle::wordfinder::WordFinderDfs());
        boggle::Boggle boggle(m_gameBoardSnapshot, m_dictionary, m_wordFinder);
        EXPECT_EQ(boggle.computeScore(), 9);
    }
}
