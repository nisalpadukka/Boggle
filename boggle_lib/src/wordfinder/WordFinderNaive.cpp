//
// Created by Nisal Padukka on 2022-09-11.
//

#include "WordFinderNaive.h"
#include "Constants.h"
#include "../validator/WordValidator.h"
#include <set>

using namespace boggle;
using namespace boggle::wordfinder;

namespace{
    set<string> findAllWords(const GameBoardSnapshot& boggle);
    void findAllWordsFromCell(const GameBoardSnapshot& boggle, vector<vector<bool>> visited, int i, int j,
                              string &str, set<string>& words);
}

MatchedWords WordFinderNaive::findMatchingWords(const GameBoardSnapshot& boggle, const Dictionary& dictionary){
    MatchedWords matchedWords;
    auto allWords = findAllWords(boggle);
    for (auto word: allWords) {
        if (dictionary.exists(word)){
            matchedWords.insert({word, dictionary.getScore(word)});
        }
    }
    return matchedWords;
}

namespace {
    set<string> findAllWords(const GameBoardSnapshot& boggle){
        std::set<string> allWords;
        vector<vector<bool>> visited(boggle.size(), vector<bool> (boggle[0].size(), false));
        string str = "";
        for (int i = 0; i < boggle.size(); i++)
            for (int j = 0; j < boggle[0].size(); j++)
                findAllWordsFromCell(boggle, visited, boggle.size() - 1, boggle[0].size() - 1, str, allWords);
        return allWords;
    }

    void findAllWordsFromCell(const GameBoardSnapshot& boggle, vector<vector<bool>> visited, int i, int j, string &str, set<string>& words) {
        visited[i][j] = true;
        str = str + boggle[i][j];
        if(validator::WordValidator::isValidLength(str, minimumWordLength)) {
            words.insert(str);
        }
        // Traverse 8 adjacent cells of boggle[i][j]
        for (int row = i - 1; row <= i + 1 && row < boggle.size(); row++)
            for (int col = j - 1; col <= j + 1 && col < boggle[0].size(); col++)
                if (row >= 0 && col >= 0 && !visited[row][col])
                    findAllWordsFromCell(boggle, visited, row, col, str, words);
        //mark visited
        str.erase(str.length() - 1);
        visited[i][j] = false;
    }
}
