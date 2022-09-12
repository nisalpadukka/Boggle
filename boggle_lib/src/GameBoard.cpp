//
// Created by Nisal Padukka on 2022-09-10.
//

#include <random>

#include "GameBoard.h"


using namespace boggle;

namespace {
    int getRandomNumber(const int& lowerBound, const int& upperBound);
}

GameBoard::GameBoard(const DiceContainer& diceContainer) : m_diceContainer(diceContainer) {

}

GameBoardSnapshot GameBoard::generate() const{
    GameBoardSnapshot gameBoardSnapshot;
    for (const auto& row : m_diceContainer){
        vector<char> diceRow;
        for (auto dice : row){
            diceRow.push_back(dice[getRandomNumber(0, dice.size() - 1)]);
        }
        gameBoardSnapshot.push_back(diceRow);
    }
    return gameBoardSnapshot;
}

namespace {
    int getRandomNumber(const int& lowerBound, const int& upperBound){
        mt19937 mt(time(nullptr));
        uniform_int_distribution<> distribution(lowerBound, upperBound);
        return distribution(mt);
    }
}
