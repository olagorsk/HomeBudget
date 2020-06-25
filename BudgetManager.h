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

#include "BalanceManager.h"
#include "DateManager.h"
#include "Date.h"
#include "AuxiliaryMethods.h"
#include "Income.h"
#include "Expense.h"
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

     BalanceManager *balanceManager;

    bool checkAmount (string amount);
    Income getDetailsOfIncome();
    Expense getDetailsOfExpense();

      bool checkFirstSecondDate(Date firstDate, Date secondDate);




public:
    BudgetManager (int idLoggedUser, string xmlIncomesFileName, string xmlExpensesFileName): ID_LOGGED_USER(idLoggedUser),incomesXmlFile(xmlIncomesFileName), expensesXmlFile(xmlExpensesFileName)
    {
    balanceManager = NULL;
    incomes = incomesXmlFile.loadIncomesFromFile(ID_LOGGED_USER);
    expenses = expensesXmlFile.loadExpensesFromFile(ID_LOGGED_USER);

    };

      ~BudgetManager()
    {
        delete balanceManager;
        balanceManager = NULL;
    };

    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void previousMonthBalance();
    void givenDatesBalance();


};

#endif
