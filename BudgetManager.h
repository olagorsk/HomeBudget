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
#include "IncomesXmlFile.h"
#include "ExpensesXmlFile.h"





using namespace std;

class BudgetManager
{
    int ID_LOGGED_USER;
    DateManager dateManager;
    vector <Income> incomes;
    vector <Expense> expenses;
    ExpensesXmlFile expensesXmlFile;
    IncomesXmlFile incomesXmlFile;




    bool checkAmount (string amount);

    Income getDetailsOfIncome();
    Expense getDetailsOfExpense();

      struct IncomesSortYear;
      struct IncomesSortMonth;
       struct IncomesSortDay;

        struct ExpensesSortYear;
       struct ExpensesSortMonth;
       struct ExpensesSortDay;


       vector<Income> sortIncomes();
       vector <Expense> sortExpense();


public:
    BudgetManager (int idLoggedUser): ID_LOGGED_USER(idLoggedUser)
    {
    incomes = incomesXmlFile.loadIncomesFromFile(ID_LOGGED_USER);
    expenses = expensesXmlFile.loadExpensesFromFile(ID_LOGGED_USER);
    };
    void addIncome();
    void addExpense();
   void currentMonthBalance();



};

#endif
