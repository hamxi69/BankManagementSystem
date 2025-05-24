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
    char lastChoice = 0; 
    bool exitProgram = false;

    do {
        cout << "=================================================Welcome to the Banking System!==============================================" << endl << endl;

        do {
            login.authenticate(b);
        } while (!b.getLoggedIn());

        while (!exitProgram) {
            if (lastChoice == 0) {
                system("CLS");             
                b.displayMenu(b.getIsAdmin());
                ch = _getch();
                system("CLS");
                lastChoice = ch;
            }
            else {
                ch = lastChoice;
            }

            if (b.getIsAdmin()) {
                b.processAdminMenu(ch);
            }
            else {
                b.processUserMenu(ch);
            }

            if (!b.getLoggedIn()) {
                cout << endl << "Do you want to log in again? (Y/N): ";
                cin >> ch;
                cout << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (ch == 'Y' || ch == 'y') {
                    system("CLS");
                    lastChoice = 0;
                    break; 
                }
                else {
                    exitProgram = true;
                    break; 
                }
            }
            else {
                cout << endl << "Do you want to continue? (Y/N): ";
                cin >> ch;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (ch == 'Y' || ch == 'y') {
                    system("CLS");
                    
                }
                else {
                    lastChoice = 0;
                    system("CLS");
                }
            }
        }

    } while (!exitProgram);

    cout << "Thank you for using the Banking System!" << endl;

    return 0;
}
