// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX05-String in CS140 at Santa Barbara City College.
//
// Author: ahknight@pipeline.sbcc.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>
#include <random>
#include <chrono>

#include "player.h"
#include "computerplayer.h"
#include "humanplayer.h"
#include "gtest/gtest.h"

namespace {

    using edu::sbcc::cs140::HumanPlayer;
    using edu::sbcc::cs140::ComputerPlayer;
    using edu::sbcc::cs140::Player;

// Tests edu::sbcc:cs140::String.

    using std::string;

    using namespace ::testing_internal;

    class PlayerTest : public ::testing::Test {
    protected:
        static const uint MAX_TESTED_SCORE = 20;
        static const uint MAX_OVERALL_SCORE = 25;
        static uint _testScore;

    protected:
        static void TearDownTestCase() {
            if (_testScore == MAX_TESTED_SCORE) {
                std::cout << std::endl << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << std::endl;
            } else {
                std::cout << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                          << ")" << std::endl;
            }

            std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                      << " where the remaining points" << std::endl;
            std::cout << "comes from grading related to documentation, algorithms, and other"
                      << std::endl;
            std::cout << "criteria." << std::endl << std::endl;
        }
    };

    uint PlayerTest::_testScore = 0;

    TEST_F(PlayerTest, Computer100) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.

        ComputerPlayer player;

        ASSERT_EQ(50, player.guess());
        player.tooLow();

        ASSERT_EQ(75, player.guess());
        player.tooLow();

        ASSERT_EQ(88, player.guess());
        player.tooLow();

        ASSERT_EQ(94, player.guess());
        player.tooLow();

        ASSERT_EQ(97, player.guess());
        player.tooLow();

        ASSERT_EQ(99, player.guess());
        player.tooLow();

        ASSERT_EQ(100, player.guess());
        player.tooLow();

        ASSERT_EQ(100, player.guess());

        _testScore += 5;
    }

    TEST_F(PlayerTest, Computer1) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.

        ComputerPlayer player;

        ASSERT_EQ(50, player.guess());
        player.tooHigh();

        ASSERT_EQ(25, player.guess());
        player.tooHigh();

        ASSERT_EQ(13, player.guess());
        player.tooHigh();

        ASSERT_EQ(7, player.guess());
        player.tooHigh();

        ASSERT_EQ(4, player.guess());
        player.tooHigh();

        ASSERT_EQ(2, player.guess());
        player.tooHigh();

        ASSERT_EQ(1, player.guess());
        player.tooHigh();

        ASSERT_EQ(1, player.guess());

        _testScore += 5;
    }

    TEST_F(PlayerTest, ComputerRandom) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.

        ComputerPlayer player;

        std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> numberDistribution(1, 100);
        int number = numberDistribution(generator);

        int guesses = 0;
        for (bool gameOver = false; !gameOver; guesses++) {
            int guess = player.guess();
            if (guess < number) {
                player.tooLow();
            } else if (guess > number) {
                player.tooHigh();
            } else {
                gameOver = true;
            }
        }

        ASSERT_GE(7, guesses);

        _testScore += 5;
    }

    TEST_F(PlayerTest, Human) {
        std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> numberDistribution(1, 100);
        int number = numberDistribution(generator);

        std::stringstream buffer(std::to_string(number) + "\n");
        std::streambuf *cinBuf = std::cin.rdbuf();
        std::cin.rdbuf(buffer.rdbuf());

        HumanPlayer player;
        int guess = player.guess();
        ASSERT_EQ(number, guess);

        _testScore += 5;
        std::cin.rdbuf(cinBuf);
    }
}