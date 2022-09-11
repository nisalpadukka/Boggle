//
// Created by Nisal Padukka on 2022-09-08.
//

#pragma once

#include <string>
#include <map>

#include "Common.h"

using namespace std;

namespace boggle{
    class ScoreDerivator {
    public:
        static unsigned int getScore(const string& word);
        static unsigned int getTotalScore(const MatchedWords& matchedWords);
    };
}


