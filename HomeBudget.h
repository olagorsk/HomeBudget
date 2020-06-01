#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class HomeBudget
{
    UserManager userManager;
    BudgetManager budgetManager;




public:
    HomeBudget(string usersFileName):userManager(usersFileName) {};
    void userRegistration();
    int userLogging();



};

#endif
