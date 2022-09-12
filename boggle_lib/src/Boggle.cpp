//
// Created by Nisal Padukka on 2022-09-11.
//

#include <iostream>

#include "Boggle.h"
#include "ScoreDerivator.h"

using namespace boggle;

Boggle::Boggle(const GameBoardSnapshot&  gameBoardSnapshot, const Dictionary& dictionary, unique_ptr<wordfinder::WordFinder>& wordFinder):
    m_gameBoardSnapshot(gameBoardSnapshot), m_dictionary(dictionary), m_wordFinder(wordFinder){
};

void Boggle::process(){
    m_matchWords = m_wordFinder->findMatchingWords(m_gameBoardSnapshot, m_dictionary);
}

void Boggle::printMatchedWords(){
    for (auto word : m_matchWords){
        std::cout << word.first << std::endl;
    }
}

unsigned int Boggle::computeScore(){
    return ScoreDerivator::getTotalScore(m_matchWords);
}
