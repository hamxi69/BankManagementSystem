#pragma once
#include <vector>
#include <string>
#include "Person.h"
#include "Statement.h"


class FileManager {
public:
    static void saveAccounts(std::vector<person> accounts);
    static int loadAccounts(std::vector<person>& accounts);


    static void saveStatements(std::vector<Statement>& statements);
    static int loadStatements(std::vector<Statement>& statements);
};
