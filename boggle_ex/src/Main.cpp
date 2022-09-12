//
// Created by Nisal Padukka on 2022-09-08.
//

#include "parser/DictionaryParser.h"
#include "parser/DiceParser.h"
#include "Boggle.h"
#include "wordfinder/WordFinderFactory.h"


constexpr const char* DICTIONARY_FILE_PATH = "../../../inputs/dictionary.txt";
constexpr const char* DICE_FILE_PATH = "../../../inputs/dice.txt";

void printGameBoard(boggle::GameBoardSnapshot gameBoardSnapshot){
    cout << "Game Board" << std::endl;
    for (auto row : gameBoardSnapshot){
        for (auto cell : row){
            std::cout << cell << ",";
        }
        std::cout << endl;
    }
}

int main(){

    auto diceContainer = boggle::parser::DiceParser::parse(DICE_FILE_PATH);
    boggle::GameBoard gameBoard(diceContainer);
    auto wordFinder = boggle::wordfinder::WordFinderFactory::create(boggle::WordFinderType::DFS_LOOKUP);
    auto gameBoardSnapshot = gameBoard.generate();
    printGameBoard(gameBoardSnapshot);
    cout << "Please update words in file at Dictionary.txt" << endl;
    cout << "Press Enter to Continue";
    cin.ignore();
    auto words = boggle::parser::DictionaryParser::parse(DICTIONARY_FILE_PATH);
    boggle::Boggle boggle(gameBoardSnapshot, words, wordFinder);
    boggle.process();
    cout << "Matched Words" << endl;
    boggle.printMatchedWords();
    std::cout << "Your score : " << boggle.computeScore() << std::endl;
    return 0;
}
