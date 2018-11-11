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

#ifndef EX09_GUESSTHENUMBER_HUMANPLAYER_H
#define EX09_GUESSTHENUMBER_HUMANPLAYER_H

#include "player.h"

namespace edu { namespace sbcc { namespace cs140 {
    class HumanPlayer : public Player
    {
    public:
        HumanPlayer( ):_rangeMax(DEFAULT_RANGE_MAX),_rangeMin(DEFAULT_RANGE_MIN) {}
        virtual int guess();
    private:
        int _rangeMin;
        int _rangeMax;
        int _guess;
    };
}}}
#endif //EX09_GUESSTHENUMBER_HUMANPLAYER_H
