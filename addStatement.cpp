#include "Bank.h"
#include <iostream>

void Bank::addStatement(const Statement& statement) {
        statements.push_back(statement); 
        statementCount++;
        FileManager::saveStatements(statements);
}
