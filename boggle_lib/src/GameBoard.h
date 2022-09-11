//
// Created by Nisal Padukka on 2022-09-10.
//
#pragma once

#include <string>
#include <vector>

#include "Common.h"

using namespace std;

namespace boggle {
    class GameBoard{
    private:
        const DiceContainer& m_diceContainer;
    public:
        explicit GameBoard(const DiceContainer& diceContainer);
        GameBoardSnapshot generate();
    };
}