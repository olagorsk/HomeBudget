#ifndef INCOME_H
#define INCOME_H

#include <iostream>
//#include "DateManager.h"
#include "Date.h"

using namespace std;

class Income
{
int userId, incomeId;
Date incomeDate;
string item;
float amount;

public:
    void setUserId(int newUserId);
    void setIncomeId (int newIncomeId);
    void setIncomeDate(Date newIncomeDate);
    void setItem (string newItem);
    void setAmount (float newAmount);

    int getUserId();
    int getIncomeId();
    Date getIncomeDate();
    string getItem();
    float getAmount();
};

#endif
