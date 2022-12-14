//
// Created by Nisal Padukka on 2022-09-10.
//

#include "Dictionary.h"
#include "ScoreDerivator.h"
#include "utils/MapperUtils.h"

using namespace boggle;

Dictionary::Dictionary() = default;

void Dictionary::add(const string& word){
    m_dictionary[word] = ScoreDerivator::getScore(word);
}

bool Dictionary::exists(const string& word) const{
    return !(m_dictionary.find(utils::MapperUtils::enrichQ(word)) == m_dictionary.end());
}

unsigned int Dictionary::getScore(const string& word) const{
    auto it = m_dictionary.find(word);
    if (it == m_dictionary.end()){
        throw invalid_argument("Not in dictionary " + word);
    }
    return it->second;
}

vector<string> Dictionary::getWords() const{
    vector<string> words;
    for (const auto &mapIt : m_dictionary){
        words.push_back(mapIt.first);
    }
    return words;
}