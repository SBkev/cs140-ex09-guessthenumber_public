//
// Created by aknight on 8/6/18.
//

#ifndef GUESSTHENUMBER_PLAYER_H
#define GUESSTHENUMBER_PLAYER_H

namespace edu { namespace sbcc { namespace cs140 {

    class Player {
    public:
        virtual int guess() const = 0;
        virtual void tooHigh() {};
        virtual void tooLow() {};
    };

// Put the declarations for HumanPlayer and ComputerPlayer here
// or include below.
}}}
#endif //GUESSTHENUMBER_PLAYER_H
