#include "Bank.h"

void Bank::transfer(person& sender, person& recipient, int cash) {
    if (cash > sender.cash) {
        cout << "Insufficient funds for transfer." << endl;
    }
    else {
        sender.cash -= cash;
        recipient.cash += cash;
        Statement senderStatement = createStatement(sender.id, cash, false, true, false, recipient.id);
        addStatement(senderStatement);

        Statement recipientStatement = createStatement(recipient.id, cash, true, false, false, sender.id);
        addStatement(recipientStatement);

        cout << "Transfer successful!" << endl;
    }
}