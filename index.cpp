#include "Bank.h"
#include <iostream>
#include <limits>
#include "authentication.h"
#include <conio.h>
using namespace std;

int main() {
    Bank b;
    Login login;
    char ch;

    do {
        cout << "=================================================Welcome to the Banking System!==============================================" << endl;
        cout << endl;

        do {
            login.authenticate(b);
        } while (!b.getLoggedIn());

        do {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            b.displayMenu(b.getIsAdmin());
            ch = _getch();
            system("CLS");

            if (b.getIsAdmin()) {
                b.processAdminMenu(ch);
            }
            else {
                b.processUserMenu(ch);
            }

            if (!b.getLoggedIn()) {
                cout << endl;
                cout << "Do you want to log in again? (Y/N): ";
                cin >> ch;
                cout << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (ch == 'Y' || ch == 'y') {
                    break;
                }
            }
            else {
                cout << endl;
                cout << "Do you want to continue? (Y/N): ";
                cin >> ch;
                cout << endl;
            }
        } while (ch == 'Y' || ch == 'y');

    } while (ch == 'Y' || ch == 'y');

    cout << "Thank you for using the Banking System!" << endl;

    return 0;
}
