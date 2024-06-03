#include "Bank.h"
#include <regex> 
#include <limits> 

void Bank::createAccount() {

    cout << "Do you want to create account? (y/n): ";
    string choice;
    getline(cin, choice);
    if (choice != "y" && choice != "Y") {
        cout << "Create canceled." << endl;
        cout << endl;
        return;
    }

    cout << "Enter data of accounts:" << total + 1 << endl;

    cout << "Enter name: ";
    getline(cin, accounts[total].name);
    while (accounts[total].name.empty() || accounts[total].name.find_first_not_of(' ') == string::npos) {
        cout << "Invalid input. Please enter a non-empty name: ";
        getline(cin, accounts[total].name);
    }

    cout << "ID (format: XXX or XXX-XXX): ";
    while (true) {
        getline(cin, accounts[total].id);
        if (regex_match(accounts[total].id, regex("^\\d{3}(-\\d{3})?$"))) {
            bool idExists = false;
            for (int i = 0; i < total; ++i) {
                if (accounts[i].id == accounts[total].id) {
                    idExists = true;
                    break;
                }
            }
            if (idExists) {
                cout << "ID already exists. Please enter a unique ID: ";
                continue;
            }
            break;
        }
        cout << "Invalid ID format. Please enter ID in the format XXX or XXX-XXX: ";
    }


    cout << "Enter Password: ";
    getline(cin, accounts[total].password);
    while (accounts[total].password.empty() || accounts[total].password.find_first_not_of(' ') == string::npos) {
        cout << "Invalid input. Please enter a non-empty password: ";
        getline(cin, accounts[total].password);
    }

    cout << "Address: ";
    getline(cin, accounts[total].address);
    while (accounts[total].address.empty() || accounts[total].address.find_first_not_of(' ') == string::npos) {
        cout << "Invalid input. Please enter a non-empty address: ";
        getline(cin, accounts[total].address);
    }

    cout << "Contact (format: 03XX-XXXXXXX or +92XXXXXXXXXX): ";
    while (true) {
        getline(cin, accounts[total].contact);
        if (regex_match(accounts[total].contact, regex("^03\\d{9}$|^\\+923\\d{9}$"))) {
            bool contactExists = false;
            for (int i = 0; i < total; ++i) {
                if (accounts[i].contact == accounts[total].contact) {
                    contactExists = true;
                    break;
                }
            }
            if (contactExists) {
                cout << "Contact number already exists. Please enter a unique contact number: ";
                continue;
            }
            break;
        }
        cout << "Invalid input. Please enter a valid contact in the format 03XX-XXXXXXX or +92XXXXXXXXXX: ";
    }

    while (true) {
        cout << "Role: " << endl;
        cout << "Press 1 For Role Admin." << endl;
        cout << "Press 2 For Role Customer." << endl;
        if (!(cin >> accounts[total].role) || (accounts[total].role != 1 && accounts[total].role != 2)) {
            cout << "Invalid input. Please enter 1 for Admin or 2 for Customer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    if (accounts[total].role == 1) {
        accounts[total].roleName = "Admin";
    }
    else if (accounts[total].role == 2) {
        accounts[total].roleName = "Customer";
    }

    if (accounts[total].role == 2) {
        cout << "Total Cash: ";
        while (!(cin >> accounts[total].cash)) {
            cout << "Invalid input. Please enter a valid integer for Total Cash: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        Statement newStatement = createStatement(accounts[total].id, accounts[total].cash, true, false, false, "");
        addStatement(newStatement);
    }

    total++;
    cout << endl;
    cout << "Account created successfully!" << endl;
    cout << endl;

}
