//
// Created by Nisal Padukka on 2022-09-08.
//

#include <regex>
#include <stdexcept>
#include <fstream>


#include "DiceParser.h"
#include "utils/StringUtils.h"
#include "validator/MatrixValidator.h"

#include <iostream>

using namespace boggle::parser;
using namespace boggle::utils;

vector<vector<string>> DiceParser::parse(const string& filepath){
    ifstream infile(filepath);
    if (!infile.good()){
        throw std::invalid_argument("File does not exist in " + filepath);
    }
    string input;
    DiceContainer diceContainer;
    while (std::getline(infile, input)){
        vector<string> diceRow;
        auto splitted = StringUtils::split(input);
        for (const auto& dice : splitted){
            diceRow.push_back(StringUtils::capitalize(StringUtils::trim(dice)));
        }
        diceContainer.push_back(diceRow);
    }
    if (!boggle::validator::MatrixValidator<string>::isValid(diceContainer)){
        infile.close();
        throw invalid_argument("Dice matrix is incomplete");
    }
    infile.close();
    return diceContainer;
}
