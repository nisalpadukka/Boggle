//
// Created by Nisal Padukka on 2022-09-11.
//

#pragma once

#include "Common.h"
#include "WordFinder.h"

namespace boggle {
    namespace wordfinder {
        class WordFinderFactory {
        public:
            static unique_ptr<WordFinder> create(const WordFinderType& type);
        };
    }
}


