#include "Bank.h"
#include <conio.h>

void Bank::delAccount() {
    char choice;
    cout << "Press 1 to remove a specific record" << endl;
    cout << "Press 2 to remove all records" << endl;
    cout << "Press 3 to go back." << endl;
    choice = _getch();

    switch (choice) {
    case '1': {
        cout << "Enter ID of the account you want to remove: " << endl;
        string accountId;
        cin >> accountId;

        bool found = false;
        for (int i = 0; i < total; i++) {
            if (accountId == accounts[i].id) {
                for (int j = i; j < total - 1; j++) {
                    accounts[j] = accounts[j + 1];
                }
                total--;
                cout << "The required data has been deleted" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No such record found" << endl;
        }
        break;
    }
    case '2':
        total = 0;
        cout << "All records have been deleted" << endl;
        break;
    case '3':
        cout << "Delete Cancelled." << endl;
        return;
        break;
    default:
        cout << "Invalid Input" << endl;
        break;
    }
}
