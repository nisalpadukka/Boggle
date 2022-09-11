//
// Created by Nisal Padukka on 2022-09-08.
//

#include "MapperUtils.h"
#include <string>
#include <regex>

using namespace boggle::utils;

string MapperUtils::shrinkQ(const string& word){
    return std::regex_replace(word, std::regex("QU"), "Q");
}

string MapperUtils::enrichQ(const string &word){
    return std::regex_replace(word, std::regex("Q"), "QU");
}