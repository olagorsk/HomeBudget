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
    string XML_INCOMES_FILENAME, XML_EXPENSES_FILENAME;

public:
    HomeBudget(string usersFileName, string incomesXmlFileName, string expensesXmlFileName):userManager(usersFileName),  XML_INCOMES_FILENAME(incomesXmlFileName),  XML_EXPENSES_FILENAME(expensesXmlFileName)
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
void currentMonthBalance();
void previousMonthBalance();
void givenDatesBalance();


};

#endif
