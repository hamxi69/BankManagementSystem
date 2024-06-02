#include "Bank.h"

void Bank::displayMenu(bool isAdmin) {
    if (isAdmin) {
        cout << "Press 1 For Create a new account." << endl;
        cout << "Press 2 For View customer list." << endl;
        cout << "Press 3 Update information of existing account." << endl;
        cout << "Press 4 Check the details of an existing account." << endl;
        cout << "Press 5 For transactions." << endl;
        cout << "Press 6 For Account Statement." << endl;
        cout << "Press 7 Remove existing account." << endl;
        cout << "Press 8 For Logout." << endl;
        cout << "Press 9 For Exit." << endl;
    }
    else {
        cout << "Press 1 Check the details of an account." << endl;
        cout << "Press 2 Update information of an account." << endl;
        cout << "Press 3 For transactions." << endl;
        cout << "Press 4 For Account Statement." << endl;
        cout << "Press 5 For Logout." << endl;
        cout << "Press 6 For Exit." << endl;
    }
}