//
// Created by Nisal Padukka on 2022-09-11.
//

#pragma once

#include <string>

using namespace std;

namespace boggle {
    namespace validator {
        template<typename T>
        class MatrixValidator {
        public:
            static bool isValid(const vector<vector<T>>& matrix){
                auto width = matrix[0].size();
                for (auto row : matrix){
                    if (width != row.size()){
                        return false;
                    }
                }
                return true;
            }
        };
    }
}


