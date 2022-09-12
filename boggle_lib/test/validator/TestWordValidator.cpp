//
// Created by Nisal Padukka on 2022-09-12.
//

#include "gtest/gtest.h"
#include "Common.h"
#include "validator/WordValidator.h"

namespace boggletest {

    TEST(TestWordValidator, validLength) {
        EXPECT_TRUE(boggle::validator::WordValidator::isValidLength("test", 3));
        EXPECT_TRUE(boggle::validator::WordValidator::isValidLength("tes", 3));
        EXPECT_FALSE(boggle::validator::WordValidator::isValidLength("te", 3));
    }
}
