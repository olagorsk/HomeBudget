#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class HomeBudget
{
    UserManager userManager;
    BudgetManager *budgetManager;




public:
    HomeBudget(string usersFileName):userManager(usersFileName)
     {
     budgetManager = NULL;
     };

    ~HomeBudget()
    {
        delete budgetManager;
        budgetManager = NULL;
    };
    void userRegistration();
    int userLogging();
bool isUserLogged();
char selectOptionFromUserMenu();
char selectOptionFromBudgetMenu();
void addIncome();
void addExpense();
void changePasswordOfLoggedUser();
int userLoggingOut();


};

#endif
