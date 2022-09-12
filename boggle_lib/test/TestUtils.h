//
// Created by Nisal Padukka on 2022-09-08.
//

#pragma once

using namespace std;

#define EXPECT_THROW_WITH_MESSAGE(statement, exception, errorMsg) \
    EXPECT_THROW( \
        try { \
            statement; \
        } catch (const exception& ex) { \
            EXPECT_EQ(std::string(ex.what()), errorMsg); \
            throw; \
        } \
    , exception)


