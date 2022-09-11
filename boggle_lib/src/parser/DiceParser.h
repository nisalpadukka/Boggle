//
// Created by Nisal Padukka on 2022-09-08.
//

#pragma once

#include <string>
#include <vector>

#include "../Common.h"

using namespace std;

namespace boggle {
    namespace parser {
        class DiceParser {
        public:
            static DiceContainer parse(const string& filepath);
        };
    }
}
