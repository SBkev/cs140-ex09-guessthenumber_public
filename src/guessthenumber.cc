//
// Created by aknight on 8/6/18.
//

#include "guessthenumber.h"
#include <iostream>
#include <random>
#include <chrono>

using std::cout;
using std::endl;

namespace edu { namespace sbcc { namespace cs140 {

    bool GuessTheNumberGame::_checkForWin(int guess, int answer, Player &p) const {
        if (answer == guess) {
            cout << "You're right! You win!" << endl;
            return true;
        } else if (answer < guess) {
            cout << "Your guess is too high." << endl;
            p.tooHigh();
        } else {
            cout << "Your guess is too low. " << endl;
            p.tooLow();
        }
        return false;
    }

    void GuessTheNumberGame::play(Player &p1, Player &p2, int number) {
        bool gameOver = false;
        do {
            cout << "Player 1's turn to guess." << endl;
            int guess = p1.guess();
            gameOver = _checkForWin(guess, number, p1);

            if (!gameOver) {
                cout << "Player 2's turn to guess." << endl;
                guess = p2.guess();
                cout << "Guess: " << guess << endl;
                gameOver = _checkForWin(guess, number, p2);
            }
        } while (!gameOver);
    }

}}}
