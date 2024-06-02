#pragma once
#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <limits>
#include "Bank.h"
using namespace std;

class Login {
private:
	bool isAdmin;
	bool loggedIn;
	string RoleName;

	struct LoggedInCustomer {
		string id, roleName;
	}loggedInCustomer;

public:
	static bool authenticate(Bank& b);
};

#endif
