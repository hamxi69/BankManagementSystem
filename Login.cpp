#include "authentication.h"

bool Login::authenticate(Bank& b) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == "admin" && password == "password") {
        b.setIsAdmin(true);
        b.setLoggedIn(true);
        b.setLoggedInCustomer("100", "Admin");
        cout << endl;
        system("CLS");

        cout << "Login successful!" << endl;

        cout << endl;

        return true;
    }
    else {
        Bank::person* allAccounts = b.getAccounts();
        int total = b.getTotal();
        if (total == 0) {
            cout << endl;
            cout << "No account holders in this account." << endl;
            cout << endl;

            return false;
        }
        else {
            for (int i = 0; i < total; i++) {
                if (username == allAccounts[i].id && password == allAccounts[i].password) {
                    if (allAccounts[i].roleName == "Admin") {
                        b.setIsAdmin(true);
                        b.setLoggedIn(true);
                        b.setLoggedInCustomer(allAccounts[i].id, allAccounts[i].roleName);
                        cout << endl;
                        system("CLS");

                        cout << "Login successful!" << endl;

                        cout << endl;
                        return true;
                    }
                    else {
                        b.setIsAdmin(false);
                        b.setLoggedIn(true);
                        b.setLoggedInCustomer(allAccounts[i].id,allAccounts[i].roleName);
                        cout << endl;
                        system("CLS");

                        cout << "Login successful!" << endl;

                        cout << endl;

                        return true;
                    }
                }
            }
            cout << "Invalid username or password. Please try again." << endl;
            return false;
        }
    }
}
