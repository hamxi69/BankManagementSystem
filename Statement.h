#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>

struct Statement {
    std::string id, accId, transferTo, depositFrom;
    bool isWithdraw = false;
    bool isDeposit = false;
    bool isTransfer = false;
    time_t CreatedOn = {};
    int cash = 0;
};

#endif
#pragma once
