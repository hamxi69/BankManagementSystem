#include "authentication.h"
#include "Person.h"
#include "vector"

bool Login::authenticate(Bank& b) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    vector<person> allAccounts = b.getAccounts();
    int total = b.getTotal();

    if (total == 0) {
        cout << "\nNo account holders found.\n" << endl;
        return false;
    }

    for (int i = 0; i < total; i++) {
        if (username == allAccounts[i].id && password == allAccounts[i].password) {
            b.setIsAdmin(allAccounts[i].roleName == "Admin");
            b.setLoggedIn(true);
            b.setLoggedInCustomer(allAccounts[i].id, allAccounts[i].roleName);
            cout << "\nLogin successful!\n" << endl;
            system("CLS");
            return true;
        }
    }

    cout << "Invalid username or password. Please try again." << endl;
    return false;
}
