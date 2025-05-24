#include "FileManager.h"
#include <fstream>
#include <iostream>

using namespace std;

string accountFileName = "accounts.txt";
string statementFileName = "statements.txt";

void FileManager::saveAccounts(vector<person> accounts) {
    ofstream outFile(accountFileName, ios::trunc);
    if (!outFile) {
        cerr << "Error opening file for saving accounts.\n";
        return;
    }
    outFile << accounts.size() << "\n";
    for (const auto& acc : accounts) {
        outFile << acc.name << "\n"
            << acc.id << "\n"
            << acc.password << "\n"
            << acc.address << "\n"
            << acc.contact << "\n"
            << acc.role << "\n"
            << acc.cash << "\n"
            << acc.roleName << "\n";
    }
}
int FileManager::loadAccounts(vector<person>& accounts) {
    ifstream inFile(accountFileName);
    if (!inFile) return 0;

    int total = 0;
    inFile >> total;
    inFile.ignore();

    accounts.clear();
    for (int i = 0; i < total; i++) {
        person p;
        getline(inFile, p.name);
        getline(inFile, p.id);
        getline(inFile, p.password);
        getline(inFile, p.address);
        getline(inFile, p.contact);
        inFile >> p.role;
        inFile >> p.cash;
        inFile.ignore();
        getline(inFile, p.roleName);
        accounts.push_back(p);
    }

    return total;
}


void FileManager::saveStatements(vector<Statement>& statements) {
    ofstream outFile(statementFileName, ios::trunc);
    if (!outFile) {
        cerr << "Error opening file for saving statements.\n";
        return;
    }
    outFile << statements.size() << "\n";
    for (const auto& stmt : statements) {
        outFile << stmt.id << "\n"
            << stmt.accId << "\n"
            << stmt.transferTo << "\n"
            << stmt.depositFrom << "\n"
            << stmt.isWithdraw << "\n"
            << stmt.isDeposit << "\n"
            << stmt.isTransfer << "\n"
            << stmt.CreatedOn << "\n"
            << stmt.cash << "\n";
    }
}
int FileManager::loadStatements(vector<Statement>& statements) {
    ifstream inFile(statementFileName);
    if (!inFile) return 0;

    int total = 0;
    inFile >> total;
    inFile.ignore();

    statements.clear();
    for (int i = 0; i < total; i++) {
        Statement stmt;
        getline(inFile, stmt.id);
        getline(inFile, stmt.accId);
        getline(inFile, stmt.transferTo);
        getline(inFile, stmt.depositFrom);
        inFile >> stmt.isWithdraw;
        inFile >> stmt.isDeposit;
        inFile >> stmt.isTransfer;
        inFile >> stmt.CreatedOn;
        inFile >> stmt.cash;
        inFile.ignore();
        statements.push_back(stmt);
    }
    return total;
}