//
// Created by Nisal Padukka on 2022-09-12.
//

#include "gtest/gtest.h"
#include "utils/MapperUtils.h"

namespace boggletest {


    TEST(TestMapperUtils, shrinkQ){
        EXPECT_EQ(boggle::utils::MapperUtils::shrinkQ("AQUIN"), "AQIN");
    }

    TEST(TestMapperUtils, enrichQ){
        EXPECT_EQ(boggle::utils::MapperUtils::enrichQ("AQIN"), "AQUIN");
    }
}
