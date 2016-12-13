//
// Created by aavens on 04.04.16.
//

#ifndef NAMALGO_SUBSTITUTION_H
#define NAMALGO_SUBSTITUTION_H

#include <string>
using std::string;

class Substitution {
public:
    Substitution(string, string);

    bool apply(string *);
private:
    string in;
    string out;
};


#endif //NAMALGO_SUBSTITUTION_H
