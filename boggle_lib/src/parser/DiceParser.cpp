//
// Created by Nisal Padukka on 2022-09-08.
//

#include <regex>
#include <stdexcept>
#include <fstream>


#include "DiceParser.h"
#include "utils/StringUtils.h"

#include <iostream>

using namespace boggle::parser;
using namespace boggle::utils;

vector<vector<string>> DiceParser::parse(const string& filepath){
    ifstream infile(filepath);
    string input;
    DiceMatrix diceMatrix;
    while (std::getline(infile, input)){
        vector<string> diceRow;
        auto splitted = StringUtils::split(input);
        for (const auto& dice : splitted){
            diceRow.push_back(StringUtils::capitalize(StringUtils::trim(dice)));
        }
        diceMatrix.push_back(diceRow);
    }
    return diceMatrix;
}
