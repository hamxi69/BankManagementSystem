#include "Bank.h"
#include <conio.h>
#include <iostream>

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
        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if (accountId == it->id) {
                accounts.erase(it);  
                total = static_cast<int>(accounts.size());
                FileManager::saveAccounts(accounts);
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
        accounts.clear();
        total = 0;
        FileManager::saveAccounts(accounts);  
        cout << "All records have been deleted" << endl;
        break;
    case '3':
        cout << "Delete Cancelled." << endl;
        return;
    default:
        cout << "Invalid Input" << endl;
        break;
    }
}
