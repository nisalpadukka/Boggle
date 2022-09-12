//
// Created by Nisal Padukka on 2022-09-12.
//

#include "gtest/gtest.h"
#include "GameBoard.h"

namespace boggletest {
    class TestGameBoard : public testing::TestWithParam<boggle::DiceContainer> {
    protected:
        unique_ptr<boggle::GameBoard> m_gameBoardSnapshot;
    };

    INSTANTIATE_TEST_SUITE_P(
            inputs,
            TestGameBoard,
            ::testing::Values(boggle::DiceContainer(
                              {{"AWOTOT", "BOAJBO", "HNZNHL", "ISTOES"},
                               {"TSDIYT", "PSCAOH", "TYTLRE", "ERXIDL"},
                               {"FSAFPK", "QUIHNM", "SNEIUE", "AEANGE"},
                               {"RVTWEH", "TMUOIC", "WEENGH", "LYVRDE"}
                              }),
                              boggle::DiceContainer(
                              {{"A", "B", "C", "D"},
                               {"E", "F", "G", "H"},
                               {"I", "J", "K", "L"},
                               {"M", "N", "O", "P"}
                              })
                              ));


    TEST_P(TestGameBoard, testBoard) {
        m_gameBoardSnapshot.reset(new boggle::GameBoard(GetParam()));
        auto gameBoardSnapshot = m_gameBoardSnapshot->generate();
        for (auto i = 0;  i < gameBoardSnapshot.size(); i++){
            for (auto j = 0; j < gameBoardSnapshot[i].size(); j++){
                EXPECT_TRUE(GetParam()[i][j].find(gameBoardSnapshot[i][j]) != std::string::npos);
            }
        }
    }
}
