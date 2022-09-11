//
// Created by Nisal Padukka on 2022-09-08.
//

#pragma once
#include <string>

#include "Dictionary.h"

using namespace std;

namespace boggle {
    namespace parser {
        class DictionaryParser {
        public:
            static Dictionary parse(const string& filepath);
        };
    }
}
