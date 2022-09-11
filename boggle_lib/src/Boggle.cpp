//
// Created by Nisal Padukka on 2022-09-11.
//

#include "Boggle.h"
#include "ScoreDerivator.h"

using namespace boggle;

Boggle::Boggle(const GameBoardSnapshot&  gameBoardSnapshot, const Dictionary& dictionary, unique_ptr<wordfinder::WordFinder>& wordFinder):
    m_gameBoardSnapshot(gameBoardSnapshot), m_dictionary(dictionary), m_wordFinder(wordFinder){
};

unsigned int Boggle::computeScore(){
    return ScoreDerivator::getTotalScore(m_wordFinder->findMatchingWords(m_gameBoardSnapshot, m_dictionary));
}
