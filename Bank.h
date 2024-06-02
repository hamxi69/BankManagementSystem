#pragma once
#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime> 

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
    }

    struct person {
        string name, id, address, contact, password, roleName;
        int cash = 0;
        int role = 0;
    } accounts[100];

    struct Statement {
        string id, accId, transferTo, depositFrom;
        bool isWithdraw = false;
        bool isDeposit = false;
        bool isTransfer = false;
        time_t CreatedOn = {};
        int cash = 0;
    };

    Statement statements[200];

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
    Bank::Statement createStatement(const string& accId, int cash, bool isDeposit, bool isTransfer, bool isWithdraw, const string& transferTo);
    void addStatement(const Statement& statement);


    string getAccountName(const string& accountId);
    string formatTime(const time_t* time, char* buffer);

    bool getIsAdmin() const { return isAdmin; }
    void setIsAdmin(bool isAdmin) { this->isAdmin = isAdmin; }

    bool getLoggedIn() const { return loggedIn; }
    void setLoggedIn(bool loggedIn) { this->loggedIn = loggedIn; }

    person* getAccounts() {
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
