//
// Created by aavens on 04.04.16.
//

#include "NMA.h"

NMA::NMA() {
    subs = new std::vector<Substitution>();
    finish = false;
}

void NMA::modify(string *s) {
    while (!finish) {
        for (int i = 0; i < subs->size(); i++) {
            Substitution sub = subs->at(i);
            finish = sub.apply(s);
        }
    }
}

void NMA::add(Substitution sub) {
    subs->push_back(sub);
}
