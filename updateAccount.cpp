#include "Bank.h"
#include <regex> 
#include <limits> 

void Bank::updateAccountById() {

    LoggedInCustomer loggedInUser = getloggedInUser();
    if (loggedInUser.roleName == "Admin") {
        cout << "Enter id of an account: " << endl;
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < total; i++) {
            if (id == accounts[i].id) {
                cout << "Previous data" << endl;
                cout << "Data of accounts " << i + 1 << endl;
                cout << "Name: " << accounts[i].name << endl;
                cout << "ID: " << accounts[i].id << endl;
                cout << "Address: " << accounts[i].address << endl;
                cout << "Contact: " << accounts[i].contact << endl;
                cout << "Cash: " << accounts[i].cash << endl;

                cout << "Do you want to update this account? (y/n): ";
                string choice;
                getline(cin, choice);
                if (choice != "y" && choice != "Y") {
                    cout << "Update canceled." << endl;
                    cout << endl;
                    return;
                }


                cout << "Enter new data" << endl;

                cout << "Enter name: ";
                getline(cin, accounts[i].name);
                while (accounts[i].name.empty() || accounts[i].name.find_first_not_of(' ') == string::npos) {
                    cout << "Invalid input. Please enter a non-empty name: ";
                    getline(cin, accounts[i].name);
                }

                cout << "ID (format: XXX or XXX-XXX): ";
                while (true) {
                    getline(cin, accounts[i].id);
                    if (regex_match(accounts[i].id, regex("^\\d{3}(-\\d{3})?$"))) {
                        bool idExists = false;
                        for (int j = 0; j < total; ++j) {
                            if (i != j && accounts[i].id == accounts[j].id) { 
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
                getline(cin, accounts[i].password);
                while (accounts[i].password.empty() || accounts[i].password.find_first_not_of(' ') == string::npos) {
                    cout << "Invalid input. Please enter a non-empty password: ";
                    getline(cin, accounts[i].password);
                }

                cout << "Address: ";
                getline(cin, accounts[i].address);
                while (accounts[i].address.empty() || accounts[i].address.find_first_not_of(' ') == string::npos) {
                    cout << "Invalid input. Please enter a non-empty address: ";
                    getline(cin, accounts[i].address);
                }


                cout << "Contact (format: 03XX-XXXXXXX or +92XXXXXXXXXX): ";
                while (true) {
                    getline(cin, accounts[i].contact);
                    if (regex_match(accounts[i].contact, regex("^03\\d{9}$|^\\+923\\d{9}$"))) {
                        bool contactExists = false;
                        for (int j = 0; j < total; ++j) {
                            if (i != j && accounts[i].contact == accounts[j].contact) {
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
                    if (!(cin >> accounts[i].role) || (accounts[i].role != 1 && accounts[i].role != 2)) {
                        cout << "Invalid input. Please enter 1 for Admin or 2 for Customer: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else {
                        break;
                    }
                }

                if (accounts[i].role == 1) {
                    accounts[i].roleName = "Admin";
                }
                else if (accounts[i].role == 2) {
                    accounts[i].roleName = "Customer";
                }

                accounts[i].cash = accounts[i].cash;
                cout << endl;
                cout << "Account Updated successfully!" << endl;
                cout << endl;

                break;

            }
            if (i == i - 1) {
                cout << endl;
                cout << "No such record found" << endl;
            }
        }
    }
    else {
        string id = loggedInUser.id;

        for (int i = 0; i < total; i++) {
            if (id == accounts[i].id) {
                cout << "Previous data" << endl;
                cout << "Data of accounts " << i + 1 << endl;
                cout << "Name: " << accounts[i].name << endl;
                cout << "ID: " << accounts[i].id << endl;
                cout << "Address: " << accounts[i].address << endl;
                cout << "Contact: " << accounts[i].contact << endl;
                cout << "Cash: " << accounts[i].cash << endl;

                cout << "Enter new data" << endl;

                cout << "Do you want to update this account? (y/n): ";
                string choice;
                getline(cin, choice);
                if (choice != "y" && choice != "Y") {
                    cout << "Update canceled." << endl;
                    cout << endl;
                    return;
                }


                cout << "Enter name: ";
                getline(cin, accounts[i].name);
                while (accounts[i].name.empty() || accounts[i].name.find_first_not_of(' ') == string::npos) {
                    cout << "Invalid input. Please enter a non-empty name: ";
                    getline(cin, accounts[i].name);
                }

                if (loggedInUser.roleName == "Customer") {
                    accounts[i].id = accounts[i].id;
                }


                cout << "Enter Password: ";
                getline(cin, accounts[i].password);
                while (accounts[i].password.empty() || accounts[i].password.find_first_not_of(' ') == string::npos) {
                    cout << "Invalid input. Please enter a non-empty password: ";
                    getline(cin, accounts[i].password);
                }

                cout << "Address: ";
                getline(cin, accounts[i].address);
                while (accounts[i].address.empty() || accounts[i].address.find_first_not_of(' ') == string::npos) {
                    cout << "Invalid input. Please enter a non-empty address: ";
                    getline(cin, accounts[i].address);
                }


                cout << "Contact (format: 03XX-XXXXXXX or +92XXXXXXXXXX): ";
                while (true) {
                    getline(cin, accounts[i].contact);
                    if (regex_match(accounts[i].contact, regex("^03\\d{9}$|^\\+923\\d{9}$"))) {
                        bool contactExists = false;
                        for (int j = 0; j < total; ++j) {
                            if (i != j && accounts[i].contact == accounts[j].contact) {
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


                if (loggedInUser.roleName == "Customer") {
                    accounts[i].roleName = accounts[i].roleName;
                }


                if (loggedInUser.roleName == "Customer") {
                    accounts[i].cash = accounts[i].cash;
                }
                cout << endl;

                cout << "Account Updated successfully!" << endl;

                cout << endl;

                if (i == i - 1) {
                    cout << endl;
                    cout << "No such record found" << endl;
                }
            }
        }
    }
    
}