//
// Created by aavens on 04.04.16.
//

#ifndef NAMALGO_NMA_H
#define NAMALGO_NMA_H

#include <string>
#include <vector>
#include "Substitution.h"

using std::string;

class NMA {
public:
    NMA();

    void modify(string *);
    void add(Substitution);
private:
    std::vector<Substitution>* subs;

    bool finish;
};


#endif //NAMALGO_NMA_H
