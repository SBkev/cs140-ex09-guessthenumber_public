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

#include "computerplayer.h"
#include <iostream>
#include <math.h>
namespace edu { namespace sbcc { namespace cs140 {

    void ComputerPlayer::tooHigh() {
        _rangeMax = _guess;
    }

    void ComputerPlayer::tooLow() {
        _rangeMin = _guess;
    }

    int ComputerPlayer::guess() {
        double guessCalc;
        guessCalc = (_rangeMax + _rangeMin)/2;
        std::cout << "guessCalc is: " << guessCalc << std::endl;

        _guess = ceil(guessCalc);
        std::cout << "_guess is: " << _guess << std::endl;
        std::cout << std::endl;

        return _guess;
    }
}}}

