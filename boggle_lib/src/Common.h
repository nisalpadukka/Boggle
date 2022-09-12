//
// Created by Nisal Padukka on 2022-09-10.
//

#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

namespace boggle{
    //Type definitions
    using DiceContainer = vector<vector<string>>;
    using GameBoardSnapshot = vector<vector<char>>;
    using MatchedWords = map<string, unsigned int>;

    //enums
    enum WordFinderType{
        NAIVE,
        DFS_LOOKUP
    };
}

