//
// Created by Nisal Padukka on 2022-09-11.
//

#include "WordFinderFactory.h"
#include "WordFinderNaive.h"
#include "WordFinderDfs.h"

using namespace boggle::wordfinder;

unique_ptr<WordFinder> WordFinderFactory::create(const WordFinderType& type){
    switch (type){
        case WordFinderType::NAIVE:
            return make_unique<WordFinderNaive>();
        case WordFinderType::DFS_LOOKUP:
            return make_unique<WordFinderDfs>();
        default:
            throw std::logic_error("Unknown WordFinderType " + to_string(type));
    }
}