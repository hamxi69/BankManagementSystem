#include "Bank.h"

void Bank::addStatement(const Statement& statement) {
    if (statementCount < 200) {
        statements[statementCount++] = statement;
    }
    else {
        cout << "Error: Statement array is full!" << endl;
    }
}
