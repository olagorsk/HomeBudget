#include "Income.h"


using namespace std;

void Income::setUserId (int newUserId)
{
    userId = newUserId;
}
void Income::setIncomeId (int newIncomeId)
{
    incomeId = newIncomeId;
}
void Income::setIncomeDate (Date newIncomeDate)
{
    incomeDate = newIncomeDate;
}

void Income::setItem (string newItem)
{
    item = newItem;
}

void Income::setAmount (float newAmount)
{
    amount = newAmount;
}

int Income::getUserId()
{
    return userId;
}
int Income::getIncomeId()
{
    return incomeId;
}
Date Income::getIncomeDate()
{
    return incomeDate;
}
string Income::getItem()
{
    return item;
}

float Income::getAmount()
{
    return amount;
}
