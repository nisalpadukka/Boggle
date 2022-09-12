//
// Created by Nisal Padukka on 2022-09-12.
//

#include "gtest/gtest.h"
#include "utils/StringUtils.h"

namespace boggletest {

    TEST(TestStringUtils, trim){
        EXPECT_EQ(boggle::utils::StringUtils::trim(" ABC "), "ABC");
        EXPECT_EQ(boggle::utils::StringUtils::trim("ABC "), "ABC");
        EXPECT_EQ(boggle::utils::StringUtils::trim(" ABC"), "ABC");
    }

    TEST(TestStringUtils, split){
        string toBeSplitted = "AWOTOT,BOAJBO,HNZNHL,ISTOES";
        auto splitted = boggle::utils::StringUtils::split(toBeSplitted);
        EXPECT_EQ(splitted.size(), 4);
    }

    TEST(TestStringUtils, capitalize){
        EXPECT_EQ(boggle::utils::StringUtils::capitalize("AbfCdd"), "ABFCDD");
    }
}
