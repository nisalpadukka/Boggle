//
// Created by Nisal Padukka on 2022-09-11.
//

#pragma once

#include <string>
#include <iostream>

#include "Dictionary.h"
#include "WordFinder.h"

using namespace std;

namespace boggle{
    namespace wordfinder {
        class WordFinderDfs : public WordFinder {
        public:
            MatchedWords findMatchingWords(const GameBoardSnapshot &boggle, const Dictionary &dictionary) override;
            ~WordFinderDfs() override = default;
        };
    }
}

