#include "Bank.h"
#include <conio.h>

void Bank::handleAdminTransaction() {
    cout << "Enter id of the account from which you want to perform transaction: ";
    cin >> id;
    for (int i = 0; i < total; i++) {
        if (id == accounts[i].id && accounts[i].roleName != "Admin") {
            cout << "Name: " << accounts[i].name << endl;
            cout << "Address: " << accounts[i].address << endl;
            cout << "Contact: " << accounts[i].contact << endl;
            cout << "Existing Cash: " << accounts[i].cash << endl;

            cout << "Press 1 to deposit." << endl;
            cout << "Press 2 to go back." << endl;
            char ch = _getch();

            if (ch == '1') {
                int cash;
                cout << "How much cash do you want to deposit? ";
                cin >> cash;
                deposit(accounts[i], cash);
            }
            else if (ch == '2') {
                cout << "Transaction Cancelled." << endl;
            }
            else {
                cout << "Invalid input" << endl;
            }
            return;
        }
    }
    cout << "Account not found" << endl;
};
