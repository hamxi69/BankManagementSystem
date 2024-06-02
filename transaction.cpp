#include "Bank.h"

int Bank::idCounter = 1;
void Bank::transaction() {
    LoggedInCustomer loggedInUser = getloggedInUser();
    if (loggedInUser.roleName == "Admin") {
        handleAdminTransaction();
    }
    else {
        string id = loggedInUser.id;
        for (int i = 0; i < total; i++) {
            if (id == accounts[i].id) {
                handleUserTransaction(accounts[i]);
                return;
            }
        }
        cout << "Account not found" << endl;
    }
}