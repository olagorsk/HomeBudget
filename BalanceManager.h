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
#include "Date.h"


using namespace std;

class BalanceManager
{
    vector <Income> incomes;
    vector <Expense> expenses;
    Date todayDate, firstDate, secondDate;

    struct IncomesSortYear;
    struct IncomesSortMonth;
    struct IncomesSortDay;

    struct ExpensesSortYear;
    struct ExpensesSortMonth;
    struct ExpensesSortDay;

    bool firstDateExistance;
    bool secondDateExistance;
    void checkIncomesInGivenDates(int &k, int &m);
    void checkExpensesInGivenDates(int &k, int &m);


    vector<Income> sortIncomes();
    vector <Expense> sortExpenses();

    void printIncome(Income income);
    void printExpense(Expense expense);
    bool checkFirstDateIncomes(int i);
    bool checkSecondDateIncomes(int i);
    bool checkFirstDateExpenses(int i);
    bool checkSecondDateExpenses(int i);

public:

    BalanceManager (vector <Income> unsortedIncomes, vector <Expense> unsortedExpenses, Date date):incomes(unsortedIncomes), expenses(unsortedExpenses), todayDate(date)
    {
        incomes = sortIncomes();
        expenses = sortExpenses();
    };
    ~BalanceManager()
    {
        incomes.clear();
        expenses.clear();
    }
    void currentMonthBalance();
    void previousMonthBalance();
    void givenDatesBalance(Date firstDate, Date secondDate);
};
#endif
