//
// Created by Nisal Padukka on 2022-09-12.
//

#include "gtest/gtest.h"
#include "parser/DiceParser.h"
#include "../TestUtils.h"

namespace boggletest {
    TEST(TestDiceParser, invalidDirectory){
        boggle::parser::DiceParser diceParser;
        EXPECT_THROW_WITH_MESSAGE(diceParser.parse("invalid"), invalid_argument, "File does not exist in invalid");
    }

    TEST(TestDiceParser, validDirectory) {
        boggle::parser::DiceParser diceParser;
        EXPECT_EQ(diceParser.parse("../../../inputs/dice.txt"), boggle::DiceContainer(
                {
                    { "AWOTOT", "BOAJBO", "HNZNHL", "ISTOES" },
                    { "TSDIYT", "PSCAOH", "TYTLRE", "ERXIDL" },
                    { "FSAFPK", "QUIHNM", "SNEIUE", "AEANGE" },
                    { "RVTWEH", "TMUOIC", "WEENGH", "LYVRDE" }
                }));
    }
}
