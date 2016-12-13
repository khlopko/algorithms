//
// Created by aavens on 04.04.16.
//

#include <iostream>
using std::cout;
using std::endl;
#include "Substitution.h"

Substitution::Substitution(string in, string out) {
    this->in = in;
    this->out = out;
}

bool Substitution::apply(string* s) {
    std::size_t p = s->find(in, 0);
    if (p == std::string::npos) {
        return true;
    }
    bool flag = true;
    p = 0;
    while (flag) {
        p = s->find(in, p);
        if (p == std::string::npos && flag) {
            p = 0;
            flag = s->find(in, 0) != std::string::npos;
            continue;
        }
        s->replace(p, in.size(), out);
    }
    return false;
}
