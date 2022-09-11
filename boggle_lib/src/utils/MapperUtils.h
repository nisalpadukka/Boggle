//
// Created by Nisal Padukka on 2022-09-08.
//

#pragma once

#include <string>

using namespace std;

namespace boggle{
    namespace utils{
        class MapperUtils {
        public:
            static string shrinkQ(const string& word);
            static string enrichQ(const string& word);
        };
    }
}


