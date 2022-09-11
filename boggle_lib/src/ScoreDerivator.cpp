//
// Created by Nisal Padukka on 2022-09-08.
//

#include <numeric>

#include "ScoreDerivator.h"

using namespace boggle;

unsigned int ScoreDerivator::getScore(const string& word){
    if (word.size() < 3){
        return 0;
    }

    switch (word.size()){
        case 3:
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 5;
        default:
            return 11;
    }
}

unsigned int ScoreDerivator::getTotalScore(const MatchedWords& matchedWords){
    return std::accumulate(std::begin(matchedWords), std::end(matchedWords), 0,
                                          [](const size_t previous, const std::pair<const std::string, std::size_t>& p)
                                          { return previous + p.second; });
}