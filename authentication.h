#pragma once
#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <limits>
#include "Bank.h"
using namespace std;

class Login {
public:
	static bool authenticate(Bank& b);
};

#endif
