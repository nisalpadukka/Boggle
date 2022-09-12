//
// Created by Nisal Padukka on 2022-09-08.
//

#include <regex>
#include <stdexcept>
#include <fstream>


#include "DictionaryParser.h"
#include "utils/StringUtils.h"

using namespace boggle;
using namespace boggle::parser;
using namespace boggle::utils;

Dictionary DictionaryParser::parse(const string& filepath){
    Dictionary dictionary;
    ifstream infile(filepath);

    if (!infile.good()){
        throw std::invalid_argument("File does not exist in " + filepath);
    }

    string input;
    while (std::getline(infile, input)){
        dictionary.add(StringUtils::capitalize(StringUtils::trim(input)));
    }
    infile.close();
    return dictionary;
}
