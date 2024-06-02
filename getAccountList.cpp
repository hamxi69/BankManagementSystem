#include "Bank.h"
#include <iomanip>

void Bank::getAccountList() {
    cout << left << setw(15) << "Id" << setw(15) << "Name" << setw(15) << "Address" << setw(15) << "Contact" << setw(15) << "Cash" << setw(15) << "Role" << endl;
    cout << endl;
    for (int i = 0; i < total; i++) {
        cout << left << setw(15) << accounts[i].id << setw(15) << accounts[i].name << setw(15) << accounts[i].address << setw(15) << accounts[i].contact << setw(15) << accounts[i].cash << setw(15) << accounts[i].roleName << endl;
    }
}


