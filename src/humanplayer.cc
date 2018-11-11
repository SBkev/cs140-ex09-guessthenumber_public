/**
 * CS 140 Object-Oriented Programming Using C++
 * CRN: [33323]
 * Assignment: EX09 - GuessTheNumber
 *
 * Statement of code ownership: I hereby state that I have written all of this
 * code and I have not copied this code from any other person or source.
 *
 * @keshields@pipeline.sbcc.edu
 */

#include "humanplayer.h"
#include <iostream>

using namespace std;

namespace edu { namespace sbcc { namespace cs140 {
    int HumanPlayer::guess() {
        int guess = 0;
        cout << "Enter your guess, Human!" << endl;
        cin >> guess;
        return guess;
    }
}}}