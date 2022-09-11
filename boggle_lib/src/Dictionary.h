//
// Created by Nisal Padukka on 2022-09-10.
//
#pragma once

#include <string>
#include <map>
#include <vector>

using namespace std;

namespace boggle {
    class Dictionary{
    private:
        map<string, unsigned int> m_dictionary;
    public:
        Dictionary();
        void add(const string& word);
        bool exists(const string& word) const;
        unsigned int getScore(const string& word) const;
        vector<string> getWords() const;
    };
}