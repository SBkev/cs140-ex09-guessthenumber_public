//
// Created by aknight on 8/6/18.
//

#ifndef GUESSTHENUMBER_GUESSTHENUMBER_H
#define GUESSTHENUMBER_GUESSTHENUMBER_H

#include "player.h"

namespace edu { namespace sbcc { namespace cs140 {

    class GuessTheNumberGame {
    public:
        void play(Player &p1, Player& p2, int number);

    private:
        bool _checkForWin(int guess, int answer, Player &p) const;
    };

}}}

#endif //GUESSTHENUMBER_GUESSTHENUMBER_H
