#include "Bank.h"
#include <iomanip>

void Bank::getAccountById() {

	LoggedInCustomer loggedInUser = getloggedInUser();

	if (loggedInUser.roleName == "Admin") {
		cout << "Enter the id of the account: " << endl;
		cin >> id;
	}
	else {
		id = loggedInUser.id;
	}

	bool found = false;
	for (int i = 0; i < total; i++) {
		if (id == accounts[i].id) {
			cout << left << setw(15) << "Id" << setw(15) << "Name" << setw(15) << "Address" << setw(15) << "Contact" << setw(15) << "Cash" << setw(15) << (loggedInUser.roleName == "Admin" ? "Role" : "") << endl;
			cout << endl;
			cout << left << setw(15) << accounts[i].id << setw(15) << accounts[i].name << setw(15) << accounts[i].address << setw(15) << accounts[i].contact << setw(15) << accounts[i].cash << setw(15) << (loggedInUser.roleName == "Admin" ? accounts[i].roleName : "")<< endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "No such record found" << endl;
	}

}