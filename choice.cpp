#include "Bank.h"
#include <conio.h>
#include <windows.h>

void Bank::choice(bool isAdmin) {
    char ch;
    while (1) {
        displayMenu(isAdmin);
        ch = _getch();
        system("CLS");

        if (isAdmin) {
            processAdminMenu(ch);
        }
        else {
            processUserMenu(ch);
        }
    }
}