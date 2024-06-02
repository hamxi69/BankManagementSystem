#include "Bank.h"

void Bank::accStatement() {
    LoggedInCustomer loggedInUser = getloggedInUser();

    bool headerDisplayed = false;
    char buffer[26];
    int totalDeposits = 0;
    int totalWithdrawals = 0;
    int totalTransfers = 0;

    if (loggedInUser.roleName == "Admin") {
        cout << "Enter the id of the account: " << endl;
        cin >> id;
    }
    else {
        id = loggedInUser.id;
    }
    cout << endl;
    cout << "Account Statements for Account ID: " << id << endl;
    cout << endl;

    bool hasStatements = false;
    for (int i = 0; i < statementCount; i++) {
        if (statements[i].accId == id) {
            hasStatements = true;
            if (!headerDisplayed) {
                cout << left << setw(20) << "Id"
                    << setw(20) << "Account Id"
                    << setw(20) << "Account Name"
                    << setw(20) << "TransactionType"
                    << setw(20) << "Amount"
                    << setw(20) << "Transfer To"
                    << setw(20) << "Deposit From"
                    << setw(20) << "Transacation DateTime"
                    << endl;
                headerDisplayed = true;
            }

            cout << endl;

            cout << left << setw(20) << statements[i].id
                << setw(20) << statements[i].accId
                << setw(20) << getAccountName(statements[i].accId)
                << setw(20) << (statements[i].isDeposit ? "Deposit" : (statements[i].isWithdraw ? "Withdrawal" : (statements[i].isTransfer ? "Transfer" : "Unknown")))
                << std::setw(20) << (statements[i].isDeposit
                    ? "+" + to_string(statements[i].cash)
                    : (statements[i].isWithdraw || statements[i].isTransfer
                        ? "-" + to_string(statements[i].cash)
                        : ""))
                << setw(20) << (statements[i].isTransfer ? getAccountName(statements[i].transferTo) : "N/A")
                << setw(20) << (statements[i].depositFrom != "" ? getAccountName(statements[i].depositFrom) : "N/A")
                << setw(20) << formatTime(&statements[i].CreatedOn, buffer) << endl;

            if (statements[i].isDeposit) {
                totalDeposits += statements[i].cash;
            }
            else if (statements[i].isWithdraw) {
                totalWithdrawals -= statements[i].cash;
            }
            else if (statements[i].isTransfer) {
                totalTransfers -= statements[i].cash;
            }
        }
    }

    if (!hasStatements) {
        cout << endl;
        cout << "No statements found for this account." << endl;
    }
    else {
        cout << endl;
        cout << "Total Amount Of Deposit till date: +" << totalDeposits << endl;
        cout << "Total Amount of Withdrawal till date: -" << totalWithdrawals << endl;
        cout << "Total Amount of Transfer till date: -" << totalTransfers << endl;
    }
}

    string Bank::getAccountName(const string& accountId) {
        for (int i = 0; i < total; i++) {
            if (accounts[i].id == accountId) {
                return accounts[i].name;
            }
        }
        return "Account Not Found";
    }

    string Bank::formatTime(const time_t* time, char* buffer) {
        struct tm timeinfo;
        localtime_s(&timeinfo, time);
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", &timeinfo);
        return buffer;
    }
