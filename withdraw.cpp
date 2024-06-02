#include "Bank.h"

void Bank::withDraw(person& account, int cash) {
    if (cash > account.cash) {
        cout << "Insufficient funds. Your current balance is " << account.cash << endl;
        cout << endl;
    }
    else {
        account.cash -= cash;
        Statement newStatement = createStatement(account.id, cash, false, false, true, "");
        addStatement(newStatement);
        cout << "Your new cash balance is " << account.cash << endl;
    }
};
