#include "Expense.h"


using namespace std;

void Expense::setUserId (int newUserId)
{
    userId = newUserId;
}
void Expense::setExpenseId (int newExpenseId)
{
    expenseId = newExpenseId;
}
void Expense::setExpenseDate (Date newExpenseDate)
{
    expenseDate = newExpenseDate;
}

void Expense::setItem (string newItem)
{
    item = newItem;
}

void Expense::setAmount (float newAmount)
{
    amount = newAmount;
}

int Expense::getUserId()
{
    return userId;
}
int Expense::getExpenseId()
{
    return expenseId;
}
Date Expense::getExpenseDate()
{
    return expenseDate;
}
string Expense::getItem()
{
    return item;
}

float Expense::getAmount()
{
    return amount;
}
