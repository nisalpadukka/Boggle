//
// Created by Nisal Padukka on 2022-09-08.
//

#include "parser/DictionaryParser.h"
#include "parser/DiceParser.h"
#include "Boggle.h"
#include "wordfinder/WordFinderFactory.h"


constexpr const char* DICTIONARY_FILE_PATH = "../../../inputs/dictionary.txt";
constexpr const char* DICE_FILE_PATH = "../../../inputs/dice.txt";

int main(){
    auto words = boggle::parser::DictionaryParser::parse(DICTIONARY_FILE_PATH);
    auto diceMatrix = boggle::parser::DiceParser::parse(DICE_FILE_PATH);
    boggle::GameBoard gameBoard(diceMatrix);
    auto wordFinder = boggle::wordfinder::WordFinderFactory::create(boggle::WordFinderType::DFS_LOOKUP);
    boggle::Boggle boggle(gameBoard.generate(), words, wordFinder);
    std::cout << boggle.computeScore() << std::endl;
    return 0;
}
