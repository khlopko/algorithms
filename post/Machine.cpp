//
// Created by aavens on 29.03.16.
//

#include <iostream>
using std::cout;
using std::endl;
#include "Machine.h"

Machine::Machine(const Command *commands) {
    ribbon = new bool[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        ribbon[i] =
                (i > 3 && i < 5) ||
                (i > 5 && i < 8) ||
                (i > 9 && i < 13) ||
                (i > 14 && i < 19) ||
                (i > 19 && i < 25) ||
                (i > 25 && i < 30);
    }
    ribbon[8] = true;
    pointer = ribbon;
    this->commands = commands;

}

Machine::~Machine() {
    if (ribbon != NULL) {
        delete[] ribbon;
    }
}

void Machine::run() {
    const int SIZE = 11;
    for (int i = 0; i < SIZE;) {
        Command c = commands[i];
        switch (c.command) {
            case Commands::SET_AND_JUMP:
                *pointer = true;
                i = c.line_A - 1;
                break;
            case Commands::UNSET_AND_JUMP:
                *pointer = false;
                i = c.line_A - 1;
                break;
            case Commands::MOVE_LEFT_AND_JUMP:
                if (pointer != ribbon) {
                    pointer--;
                }
                i = c.line_A - 1;
                break;
            case Commands::MOVE_RIGHT_AND_JUMP:
                if (pointer != (ribbon + LENGTH)) {
                    pointer++;
                }
                i = c.line_A - 1;
                break;
            case Commands::SEE:
                i = *pointer ? c.line_B - 1 : c.line_A - 1;
                break;
            case Commands::STOP:
                i = SIZE;
                break;
            default:
                i++;
                break;
        }
    }
}

void Machine::print_ribbon() {
    for (int i = 0; i < LENGTH; i++) {
        std::cout << ribbon[i] << " ";
    }
    std::cout << std::endl;
}

