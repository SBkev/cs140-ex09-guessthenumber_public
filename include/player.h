//
// Created by aknight on 8/6/18.
//

#ifndef GUESSTHENUMBER_PLAYER_H
#define GUESSTHENUMBER_PLAYER_H

namespace edu { namespace sbcc { namespace cs140 {

    class Player {
    protected:
        int DEFAULT_RANGE_MAX = 100;
        int DEFAULT_RANGE_MIN = 0;
    public:
        virtual int guess() = 0;
        virtual void tooHigh() {};
        virtual void tooLow() {};
    };

// Put the declarations for HumanPlayer and ComputerPlayer here
// or include below.
//#include "humanplayer.h"
//#include "computerplayer.h"
}}}
#endif //GUESSTHENUMBER_PLAYER_H
