#include "Bank.h"
#include <regex> 
#include <limits> 

void Bank::createAccount() {
    cout << "Do you want to create account? (y/n): ";
    string choice;
    getline(cin, choice);
    if (choice != "y" && choice != "Y") {
        cout << "Create canceled." << endl << endl;
        return;
    }

    person newAccount;

    cout << "Enter data of account: " << total + 1 << endl;

    cout << "Enter name: ";
    getline(cin, newAccount.name);
    while (newAccount.name.empty() || newAccount.name.find_first_not_of(' ') == string::npos) {
        cout << "Invalid input. Please enter a non-empty name: ";
        getline(cin, newAccount.name);
    }

    cout << "ID (format: XXX or XXX-XXX): ";
    while (true) {
        getline(cin, newAccount.id);
        if (regex_match(newAccount.id, regex("^\\d{3}(-\\d{3})?$"))) {
            bool idExists = false;
            for (const auto& acc : accounts) {
                if (acc.id == newAccount.id) {
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
    getline(cin, newAccount.password);
    while (newAccount.password.empty() || newAccount.password.find_first_not_of(' ') == string::npos) {
        cout << "Invalid input. Please enter a non-empty password: ";
        getline(cin, newAccount.password);
    }

    cout << "Address: ";
    getline(cin, newAccount.address);
    while (newAccount.address.empty() || newAccount.address.find_first_not_of(' ') == string::npos) {
        cout << "Invalid input. Please enter a non-empty address: ";
        getline(cin, newAccount.address);
    }

    cout << "Contact (format: 03XX-XXXXXXX or +92XXXXXXXXXX): ";
    while (true) {
        getline(cin, newAccount.contact);
        if (regex_match(newAccount.contact, regex("^03\\d{9}$|^\\+923\\d{9}$"))) {
            bool contactExists = false;
            for (const auto& acc : accounts) {
                if (acc.contact == newAccount.contact) {
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
        cout << "Role:\nPress 1 For Admin\nPress 2 For Customer\n";
        if (!(cin >> newAccount.role) || (newAccount.role != 1 && newAccount.role != 2)) {
            cout << "Invalid input. Please enter 1 for Admin or 2 for Customer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore();
            break;
        }
    }

    newAccount.roleName = (newAccount.role == 1) ? "Admin" : "Customer";

    if (newAccount.role == 2) {
        cout << "Total Cash: ";
        while (!(cin >> newAccount.cash)) {
            cout << "Invalid input. Please enter a valid integer for Total Cash: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();
        Statement newStatement = createStatement(newAccount.id, newAccount.cash, true, false, false, "");
        addStatement(newStatement);
    }

    accounts.push_back(newAccount); 
    total++;
    FileManager::saveAccounts(accounts);

    cout << "\nAccount created successfully!\n\n";
}

