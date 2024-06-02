#include "Bank.h"
#include <conio.h>
#include <windows.h>

void Bank::processUserMenu(char ch) {

    bool validInput = false;
    switch (ch) {
    case '1': getAccountById(); validInput = true; break;
    case '2': updateAccountById(); validInput = true; break;
    case '3': transaction(); validInput = true; break;
    case '4':
        if (statementCount == 0) {
            cout << "No Transaction performed." << endl;
            cout << endl;
        }
        else {
            accStatement();
        }
        validInput = true;
        break;
    case '5':
        setIsAdmin(false);
        setLoggedIn(false);
        return;
    case '6':
        exit(0);
    default:
        cout << endl << "Invalid Input." << endl;
    }

}