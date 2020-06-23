#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdlib>

#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"


using namespace std;

class BalanceManager
{

    vector <Income> incomes;
    vector <Expense> expenses;

    struct IncomesSortYear;
    struct IncomesSortMonth;
    struct IncomesSortDay;

    struct ExpensesSortYear;
    struct ExpensesSortMonth;
    struct ExpensesSortDay;


    vector<Income> sortIncomes();
    vector <Expense> sortExpenses();

    DateManager dateManager;

public:

    BalanceManager (vector <Income> unsortedIncomes, vector <Expense> unsortedExpenses):incomes(unsortedIncomes), expenses(unsortedExpenses)
    {
        incomes = sortIncomes();
        expenses = sortExpenses();
    };

    void currentMonthBalance();

};










#endif
