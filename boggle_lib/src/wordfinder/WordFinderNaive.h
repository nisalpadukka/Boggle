//
// Created by Nisal Padukka on 2022-09-11.
//

#pragma once

#include <string>
#include <iostream>
#include <set>

#include "Dictionary.h"
#include "WordFinder.h"

using namespace std;

namespace boggle{
    namespace wordfinder {
        class WordFinderNaive : public WordFinder {
        private:
            set<string> m_allWords;
        public:
            MatchedWords findMatchingWords(const GameBoardSnapshot &boggle, const Dictionary &dictionary) override;
            void printAllWords();
            ~WordFinderNaive() override = default;
        };
    }
}

