//
// Created by Nisal Padukka on 2022-09-12.
//

#include "gtest/gtest.h"
#include "parser/DictionaryParser.h"
#include "../TestUtils.h"

namespace boggletest {

    bool availableInDictionary(boggle::Dictionary dictionary, const vector<string>& words){
        for (auto word: words){
            if (!dictionary.exists(word)){
                return false;
            }
        }
        return true;
    }

    TEST(TestDictionaryParser, invalidDirectory){
        boggle::parser::DictionaryParser DictionaryParser;
        EXPECT_THROW_WITH_MESSAGE(DictionaryParser.parse("invalid"), invalid_argument, "File does not exist in invalid");
    }

    TEST(TestDictionaryParser, validDirectory) {
        boggle::parser::DictionaryParser dictionaryParser;
        auto dictionary = dictionaryParser.parse("../../../inputs/dictionary.txt");
        availableInDictionary(dictionary, {"ANY", "CHANT", "PANEL", "PATH", "TRENCH"});
    }
}
