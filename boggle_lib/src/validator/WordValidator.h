//
// Created by Nisal Padukka on 2022-09-11.
//

#pragma once

#include <string>

using namespace std;

namespace boggle {
    namespace validator {
        class WordValidator {
        public:
            static bool isValidLength(const string &word, const unsigned int &length);
        };
    }
}


