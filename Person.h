#ifndef PERSON_H
#define PERSON_H

#include <string>

struct person {
    std::string name, id, address, contact, password, roleName;
    int cash = 0;
    int role = 0;
};

#endif
