//
// Created by aavens on 29.03.16.
//

#ifndef POSTMACHINE_MACHINE_H
#define POSTMACHINE_MACHINE_H

#include <string>

class Command;

class Machine {
public:

    Machine(const Command *);
    ~Machine();

    enum Commands {
        SET_AND_JUMP = 'v',
        UNSET_AND_JUMP = 'x',
        MOVE_LEFT_AND_JUMP = '<',
        MOVE_RIGHT_AND_JUMP = '>',
        SEE = ':',
        STOP = '!'
    };

    void run();
    void print_ribbon();

private:

    bool* ribbon;
    bool* pointer;
    const Command* commands;

    const unsigned short LENGTH = 30000;

    enum Moves {
        LEFT,
        RIGHT
    };

    enum Actions {
        UNSET_MARK,
        SET_MARK,
        MOVE,
    };
};

struct Command {

    Machine::Commands command;
    int line_A;
    int line_B;

    Command(Machine::Commands command, int line_A = -1, int line_B = -1) {
        this->command = command;
        this->line_A = line_A;
        this->line_B = line_B;
    }
};

#endif //POSTMACHINE_MACHINE_H
