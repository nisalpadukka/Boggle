//
// Created by Nisal Padukka on 2022-09-11.
//

#pragma once

#include <string>
#include <iostream>

#include "Common.h"
#include "Dictionary.h"

using namespace std;

namespace boggle{
    namespace wordfinder {
        class WordFinder {
        public:
            virtual MatchedWords findMatchingWords(const GameBoardSnapshot &boggle, const Dictionary &words) = 0;
            virtual ~WordFinder() = default;;
        };
    }
}

