#pragma once
#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime> 
#include "Person.h"
#include "Statement.h"
#include "FileManager.h"
#include "vector"

using namespace std;

class Bank {
private:
    int total;
    string id;
    bool isAdmin;
    bool loggedIn;
    string RoleName;

    struct LoggedInCustomer {
        string id, roleName;
    } loggedInCustomer;

    static int idCounter;
    int statementCount;

public:
    Bank() {
        isAdmin = false;
        loggedIn = false;
        total = 0;
        statementCount = 0;
        total = FileManager::loadAccounts(accounts);
        statementCount = FileManager::loadStatements(statements);

        if (accounts.empty()) {
            person admin;
            admin.name = "System Admin";
            admin.id = "admin";
            admin.address = "No Address";
            admin.contact = "+923452990865";
            admin.password = "admin123";
            admin.role = 1;
            admin.roleName = "Admin";
            admin.cash = 0;
            accounts.push_back(admin);
            total = 1;
            FileManager::saveAccounts(accounts);
        }
    }

    vector<person> accounts;

    vector<Statement> statements;

    string generateId() {
        ostringstream oss;
        oss << setfill('0') << setw(3) << idCounter++;
        return oss.str();
    }

    // Menu
    void displayMenu(bool isAdmin);
    void processAdminMenu(char ch);
    void processUserMenu(char ch);
    void choice(bool isAdmin);
    // Menu end

    // Account CRUD
    void createAccount();
    void getAccountById();
    void getAccountList();
    void updateAccountById();
    void delAccount();
    // Account CRUD end

    // Transaction 
    void transaction();
    void deposit(person& account, int cash); 
    void handleAdminTransaction();
    void handleUserTransaction(person& account);
    void withDraw(person& account, int cash);
    void transfer(person& sender, person& recipient, int cash);

    // Transaction end 

    // Statement
    void accStatement();
    Statement createStatement(const string& accId, int cash, bool isDeposit, bool isTransfer, bool isWithdraw, const string& transferTo);
    void addStatement(const Statement& statement);


    string getAccountName(const string& accountId);
    string formatTime(const time_t* time, char* buffer);

    bool getIsAdmin() const { return isAdmin; }
    void setIsAdmin(bool isAdmin) { this->isAdmin = isAdmin; }

    bool getLoggedIn() const { return loggedIn; }
    void setLoggedIn(bool loggedIn) { this->loggedIn = loggedIn; }

    vector<person> getAccounts() {
        return accounts;
    }

    int getTotal() const { return total; }

    void setLoggedInCustomer(const string& id, const string& roleName) {
        loggedInCustomer.id = id;
        loggedInCustomer.roleName = roleName;
    }

    LoggedInCustomer getloggedInUser() {
        return loggedInCustomer;
    }

  
    };

#endif
