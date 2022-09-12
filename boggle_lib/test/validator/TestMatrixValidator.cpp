//
// Created by Nisal Padukka on 2022-09-12.
//

#include "gtest/gtest.h"
#include "Common.h"
#include "validator/MatrixValidator.h"

namespace boggletest {

    TEST(TestMatrixValidator, trim) {
        EXPECT_TRUE(boggle::validator::MatrixValidator<string>::isValid(boggle::DiceContainer(
                {{"AWOTOT", "BOAJBO", "HNZNHL", "ISTOES"},
                 {"TSDIYT", "PSCAOH", "TYTLRE", "ERXIDL"},
                 {"FSAFPK", "QUIHNM", "SNEIUE", "AEANGE"},
                 {"RVTWEH", "TMUOIC", "WEENGH", "LYVRDE"}
                })));
        EXPECT_FALSE(boggle::validator::MatrixValidator<string>::isValid(boggle::DiceContainer(
                {{"AWOTOT", "BOAJBO", "HNZNHL", "ISTOES"},
                 {"TSDIYT", "PSCAOH", "TYTLRE"},
                 {"FSAFPK", "QUIHNM", "SNEIUE", "AEANGE"},
                 {"RVTWEH", "TMUOIC", "WEENGH", "LYVRDE"}
                })));
    }
}
