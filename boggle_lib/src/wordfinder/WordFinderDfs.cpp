//
// Created by Nisal Padukka on 2022-09-11.
//

#include "WordFinderDfs.h"
#include "../utils/MapperUtils.h"
#include <set>

using namespace boggle;
using namespace boggle::wordfinder;
using namespace boggle::utils;

namespace{
    bool dfs(GameBoardSnapshot& gameBoardSnapshot, string &word, int i, int j, int n, int m, int idx);
}

MatchedWords WordFinderDfs::findMatchingWords(const GameBoardSnapshot& gameBoardSnapshot, const Dictionary& dictionary){
    MatchedWords matchedWords;
    auto wordsInDictionary = dictionary.getWords();
    for (auto word : wordsInDictionary) {
        for(auto j = 0 ; j < gameBoardSnapshot.size(); j++){
            for(auto k = 0; k < gameBoardSnapshot[0].size(); k++){
                GameBoardSnapshot gameBoardSnapshotTemp = gameBoardSnapshot;
                auto formattedWord = MapperUtils::shrinkQ(word);
                if( dfs (gameBoardSnapshotTemp, formattedWord, j, k, gameBoardSnapshot.size(), gameBoardSnapshot[0].size(), 0)){
                    matchedWords.insert({word, dictionary.getScore(word)});
                }
            }
        }
    }
    return matchedWords;
}

namespace {
    bool dfs(GameBoardSnapshot& gameBoardSnapshot, string &word, int i, int j, int n, int m, int idx){

        if( i < 0 || i >= n || j < 0 || j >= m){
            return false;
        }
        if( word[idx] != gameBoardSnapshot[i][j]){
            return false;
        }
        if(idx == word.size()-1){
            return true;
        }

        char temp = gameBoardSnapshot[i][j];
        gameBoardSnapshot[i][j]='*';
        bool north = dfs(gameBoardSnapshot, word, i, j+1, n, m,idx+1);
        bool south= dfs(gameBoardSnapshot, word, i, j-1, n, m,idx+1);
        bool east = dfs(gameBoardSnapshot, word, i+1, j, n, m,idx+1);
        bool west = dfs(gameBoardSnapshot, word, i-1, j, n, m,idx+1);
        bool northEast = dfs(gameBoardSnapshot, word, i+1, j+1, n, m,idx+1);
        bool northWest = dfs(gameBoardSnapshot, word, i-1, j+1, n, m,idx+1);
        bool southEast = dfs(gameBoardSnapshot, word, i+1, j-1, n, m,idx+1);
        bool southWest = dfs(gameBoardSnapshot, word, i-1, j-1, n, m,idx+1);

        gameBoardSnapshot[i][j]=temp;
        return north || south || east || west || northEast || northWest || southEast || southWest;
    }
}
