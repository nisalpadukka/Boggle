//
// Created by Nisal Padukka on 2022-09-11.
//

#include "WordValidator.h"

using namespace boggle::validator;

bool WordValidator::isValidLength(const string& word, const unsigned int& length){
    if (word.size() < length){
        return false;
    }
    return true;
}