//
// Created by Nisal Padukka on 2022-09-11.
//

#pragma once

#include "GameBoard.h"
#include "wordfinder/WordFinder.h"
#include <memory>

using namespace std;

namespace boggle {
    class Boggle {
    public:
        Boggle(const GameBoardSnapshot&  gameBoardSnapshot, const Dictionary& dictionary, unique_ptr<wordfinder::WordFinder>& wordFinder);
        void process();
        void printMatchedWords();
        unsigned int computeScore();
    private:
        const GameBoardSnapshot m_gameBoardSnapshot;
        const Dictionary& m_dictionary;
        unique_ptr<wordfinder::WordFinder>& m_wordFinder;
        MatchedWords m_matchWords;
    };
}


