## Exercise: Guess The Number (25 Points)

The objective of this project is to learn about inheritance and polymorphism in the context of object oriented programming
and the syntax and semantics in C++.

The first thing you will need to do is fork and clone this assignment
from GitHub. Follow the instructions
[here](https://github.com/sbcc-cs140-fall2018/Course-Information/wiki)
to get started.

Be sure that you fork the project first and use the URL from
the forked project when you clone it in CLion.

### Requirements of this project

This project is based on the programming assignments 5 and 6 from Chapter 15 on page 690 of _Absolute C++_(5th Edition). In 
it you will create several classes (in the namespace `edu::sbcc::cs140`). These classes will ultimately
implement the guess the number game, both as a human player and a computer player. The human player
can guess by asking a user for their next guess. The computer user will guess smartly to find the
answer in the fewest number of guesses.

You are given the gameplay code in `guessthenumber.cc`, you will provide the player code in `player.h` and
`player.cc`. This code will implement the play strategies of human and player through the classes
`Human` and `Computer` respectively. 

For example, you can use these object to play the game in `main.cc`:

```cpp
#include "guessthenumber.h"

using edu::sbcc::cs140::HumanPlayer;
using edu::sbcc::cs140::ComputerPlayer;
using edu::sbcc::cs140::GuessTheNumberGame;

int main() {

    HumanPlayer player1;
    ComputerPlayer player2;

    GuessTheNumberGame game;
    game.play(player1, player2, 56);

    return 0;
}
```

### Writing the code for this Project

For each of the `Human` and `Computer` classes, you'll need to add `.h` and 
`.cc` files. 

In these you will write the strategies for the `Human` and `Computer` classes. For the 
`Human` player the strategy is to ask the user for a number and use that as a guess. The
strategy for the `Computer` player is to use a binary search based on whether the last guess
was too high or too low. The first guess, would then be right in the middle of the range. 

For the `Human` class you will need to right the `guess` method. For the `Computer` class you
will need to right the `tooLow` and `toHigh` methods and keep track of the last guess.

The unit tester only includes `player.h`, to include the `Human` and `Computer` declarations
those classes must either be defined in there, or included from there. Otherwise, the unit test
code **will not compile**.

#### All files must have the header comment

Be sure to add the proper header comment to each `.cc` and `.h` file you add to this project.

### Running the code for this project

Running this code should be straightforward. In the drop-down 
menu in the upper right-hand corner you should see a *Run
Configuration* called `GuessTheNumber | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It should look something like this:

```bash
Player 1's turn to guess.
Enter guess: 50
Your guess is too low. 
Player 2's turn to guess.
Guess: 50
Your guess is too low. 
Player 1's turn to guess.
Enter guess: 75
Your guess is too high.
Player 2's turn to guess.
Guess: 75
Your guess is too high.
Player 1's turn to guess.
Enter guess: 62
Your guess is too high.
Player 2's turn to guess.
Guess: 62
Your guess is too high.
Player 1's turn to guess.
Enter guess: 56
You're right! You win!

Process finished with exit code 0
```

Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `GuessTheNumber_Gtest` and press the
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from PlayerTest
[ RUN      ] PlayerTest.Computer100
[       OK ] PlayerTest.Computer100 (0 ms)
[ RUN      ] PlayerTest.Computer1
[       OK ] PlayerTest.Computer1 (0 ms)
[ RUN      ] PlayerTest.ComputerRandom
[       OK ] PlayerTest.ComputerRandom (0 ms)
[ RUN      ] PlayerTest.Human
Enter guess: [       OK ] PlayerTest.Human (0 ms)

Your unit test score is 20 out of 20
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 4 tests from PlayerTest (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.

Process finished with exit code 0
```

You should also see your score for this
assignment minus code styling points which I will add later.

### Submitting the code for this project

First, right click on the project name, then select `Git -> Commit Directory...`. 
Make sure only the files you want to push are selected, `main.cc` `player.cc`, `human.cc` (or whatever you called them) and `balrog.h`, `cyberdemon.h`, `elf.h`, &
`player.h` (along with any others you created). Then uncheck `Perform code analysis` and `Check TODO`. It's OK to leave them checked,
but committing will take longer. Leave `Run git hooks` checked. Put a message in `Commit Message`
and then press the **Commit** button. If anything goes wrong check the _Version Control_ view
in the lower left corner and select the _Console_ tab.
 
Finally, right click on the project name,
then select `Git -> Repository -> Push...`. Follow the onscreen directions
and press **OK**. This step will run the tests again, check that everything is OK
and then submit them to the cloud to have the tests run for grading.

If you do not understand these directions, or wish to do them on the command
line rather than in CLion, then read these [directions](https://github.com/sbcc-cs140-fall2018/Course-Information/wiki/How-to-Turn-In-Every-Project).
