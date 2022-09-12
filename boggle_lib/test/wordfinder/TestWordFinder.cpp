//
// Created by Nisal Padukka on 2022-09-12.
//

#include <memory>

#include "gtest/gtest.h"
#include "Boggle.h"
#include "wordfinder/WordFinderNaive.h"
#include "wordfinder/WordFinderDfs.h"


namespace boggletest {
    class TestWordFinder : public testing::Test {
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

        bool availableInMatchedWords(const boggle::MatchedWords matchedWords, const vector<string>& words){
            for (auto word: words){
                if (matchedWords.find(word) == matchedWords.end()){
                    return false;
                }
            }
            return true;
        }
    };

    TEST_F(TestWordFinder, testWordFinderNaive) {
        m_wordFinder = std::make_unique<boggle::wordfinder::WordFinderNaive>();
        auto words = m_wordFinder->findMatchingWords(m_gameBoardSnapshot, m_dictionary);
        EXPECT_TRUE(availableInMatchedWords(words, {"ANY", "CHANT", "PANEL", "PATH", "TRENCH"}));
    }

    TEST_F(TestWordFinder, testWordFinderDFS) {
        m_wordFinder = std::make_unique<boggle::wordfinder::WordFinderDfs>();
        auto words = m_wordFinder->findMatchingWords(m_gameBoardSnapshot, m_dictionary);
        EXPECT_TRUE(availableInMatchedWords(words, {"ANY", "CHANT", "PANEL", "PATH", "TRENCH"}));
    }
}
