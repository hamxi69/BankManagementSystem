#include "Bank.h"

void Bank::deposit(person& account, int cash) {
    account.cash += cash;
    Statement newStatement = createStatement(account.id, cash, true, false, false, "");
    addStatement(newStatement);
    cout << "Your new cash balance is " << account.cash << endl;
};

