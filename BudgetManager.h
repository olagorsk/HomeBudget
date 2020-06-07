#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>

#include "DateManager.h"
#include "Date.h"
#include "AuxiliaryMethods.h"
#include "Income.h"
#include "Expense.h"
#include "UserManager.h"



using namespace std;

class BudgetManager
{
    int ID_LOGGED_USER;
    DateManager dateManager;
    vector <Income> incomes;
vector <Expense> expenses;
   bool checkAmount (string amount);
    float  convertStringToFloat(string amount);
        Income getDetailsOfIncome();
     Expense getDetailsOfExpense();


public:
BudgetManager (int idLoggedUser): ID_LOGGED_USER(idLoggedUser)
{};
    void addIncome();
    void addExpense();




};

#endif
