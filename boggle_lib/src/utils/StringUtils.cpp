//
// Created by Nisal Padukka on 2022-09-08.
//

#include "StringUtils.h"
#include <string>
#include <regex>

using namespace boggle::utils;

vector<string> StringUtils::split(string& str){
    auto const re = regex{R"(,)"};
    return {
            sregex_token_iterator{begin(str), end(str), re, -1},
            sregex_token_iterator{}
    };
}

string StringUtils::capitalize(string input) {
    std::transform(input.begin(), input.end(),input.begin(), ::toupper);
    return input;
}

string StringUtils::trim(const string &input) {
    auto const re = regex("^ +| +$|( ) +");
    return regex_replace(input, re, "$1");
}

