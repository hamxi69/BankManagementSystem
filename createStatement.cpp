#include "Bank.h"

Bank::Statement Bank::createStatement(const string& accId, int cash, bool isDeposit, bool isTransfer, bool isWithdraw, const string& transferTo) {
    Statement newStatement;
    newStatement.id = generateId();
    newStatement.accId = accId;
    newStatement.isDeposit = isDeposit;
    newStatement.isTransfer = isTransfer;
    newStatement.isWithdraw = isWithdraw;
    newStatement.transferTo = transferTo;
    newStatement.CreatedOn = time(nullptr);
    newStatement.cash = cash;
    newStatement.depositFrom = isDeposit ? transferTo : "";
    return newStatement;
}