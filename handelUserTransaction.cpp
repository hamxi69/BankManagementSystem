#include "Bank.h"
#include <conio.h>

void Bank::handleUserTransaction(person& account) {
    cout << "Name: " << account.name << endl;
    cout << "Address: " << account.address << endl;
    cout << "Contact: " << account.contact << endl;
    cout << "Existing Cash: " << account.cash << endl;

    cout << "Press 1 to withdraw" << endl;
    cout << "Press 2 for transfer" << endl;
    cout << "Press 3 to go back." << endl;
    char ch = _getch();

    if (ch == '1') {
        int cash;
        cout << "How much cash do you want to withdraw? ";
        cin >> cash;
        withDraw(account, cash);
    }
    else if (ch == '2') {
        string recipientId;
        cout << "Enter the ID of the account to which you want to transfer money: ";
        cin >> recipientId;
        if (recipientId == account.id) {
            cout << "You cannot transfer money to your own account." << endl;
        }
        else {
            for (int j = 0; j < total; j++) {
                if (recipientId == accounts[j].id) {
                    int cash;
                    cout << "Enter the amount to transfer: ";
                    cin >> cash;
                    transfer(account, accounts[j], cash);
                    return;
                }
            }
            cout << "Recipient account not found." << endl;
        }
    }
    else if (ch == '3') {
        cout << "Transaction Cancelled." << endl;
    }
    else {
        cout << "Invalid input" << endl;
    }
}