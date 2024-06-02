#include "Bank.h"
#include <conio.h>
#include <windows.h>

void Bank::processAdminMenu(char ch) {
    bool validInput = false;
    switch (ch) {
    case '1':
        createAccount();
        validInput = true;
        break;
    case '2':
    case '3':
    case '4':
    case '5':
    case '7':
        if (total == 0) {
            cout << "No data is entered." << endl;
            cout << endl;

        }
        else {
            switch (ch) {
            case '2': getAccountList(); break;
            case '3': updateAccountById(); break;
            case '4': getAccountById(); break;
            case '5': transaction(); break;
            case '7': delAccount(); break;
            }
        }
        validInput = true;
        break;
    case '6':
        if (statementCount == 0) {
            cout << "No transaction is performed." << endl;
            cout << endl;
        }
        else {
            accStatement();
        }
        validInput = true;
        break;
    case '8':
        setIsAdmin(false);
        setLoggedIn(false);
        return;
    case '9':
        exit(0);
    default:
        cout << endl << "Invalid Input." << endl;
    }
}