//
// Created by Nisal Padukka on 2022-09-08.
//

#pragma once

#include <string>
#include <vector>

using namespace std;

namespace boggle{
    namespace utils{
        class StringUtils {
        public:
            static string trim(const string& input);
            static vector<string> split(string &str);
            static string capitalize(string input);
        };
    }
}


