#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

#include "Date.h"
#include "DateManager.h"


using namespace std;

class Expense
{

int userId, expenseId;
Date expenseDate;
string item;
float amount;



public:

   void setUserId(int newUserId);
    void setExpenseId (int newExpenseId);
    void setExpenseDate(Date newExpenseDate);
    void setItem (string newItem);
    void setAmount (float newAmount);

    int getUserId();
    int getExpenseId();
    Date getExpenseDate();
    string getItem();
    float getAmount();

};

#endif
