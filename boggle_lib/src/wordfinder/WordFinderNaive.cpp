//
// Created by Nisal Padukka on 2022-09-11.
//

#include <set>

#include "WordFinderNaive.h"
#include "Constants.h"
#include "../validator/WordValidator.h"
#include "../utils/MapperUtils.h"


using namespace boggle;
using namespace boggle::wordfinder;
using namespace boggle::utils;

namespace{
    set<string> findAllWords(const GameBoardSnapshot& boggle);
    void findAllWordsFromCell(const GameBoardSnapshot& boggle, vector<vector<bool>> visited, int i, int j,
                              string &str, set<string>& words);
}

MatchedWords WordFinderNaive::findMatchingWords(const GameBoardSnapshot& boggle, const Dictionary& dictionary){
    MatchedWords matchedWords;
    auto m_allWords = findAllWords(boggle);
    for (auto word: m_allWords) {
        if (dictionary.exists(MapperUtils::enrichQ(word))){
            matchedWords.insert({word, dictionary.getScore(word)});
        }
    }
    return matchedWords;
}

void  WordFinderNaive::printAllWords() {
    for (auto word : m_allWords){
        cout << word << endl;
    }
}

namespace {
    set<string> findAllWords(const GameBoardSnapshot& boggle){
        std::set<string> allWords;
        string str;
        vector<vector<bool>> visited(boggle.size(), vector<bool>(boggle[0].size(), false));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << "Searching starting from " << boggle[i][j] << endl;
                findAllWordsFromCell(boggle, visited, i, j, str, allWords);
            }
        }
        return allWords;
    }

    void findAllWordsFromCell(const GameBoardSnapshot& boggle, vector<vector<bool>> visited, int i, int j, string &str, set<string>& words) {
        visited[i][j] = true;
        str = str + boggle[i][j];
        if(validator::WordValidator::isValidLength(str, minimumWordLength)) {
            words.insert(str);
        }
        // Traverse 8 adjacent cells of boggle[i][j]
        for (int row = i - 1; row <= i + 1 && row < (int)boggle.size(); row++)
            for (int col = j - 1; col <= j + 1 && col < (int)boggle[0].size(); col++)
                if (row >= 0 && col >= 0 && !visited[row][col])
                    findAllWordsFromCell(boggle, visited, row, col, str, words);
        //mark visited
        str.erase(str.length() - 1);
        visited[i][j] = false;
    }
}