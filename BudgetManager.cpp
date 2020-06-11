#include "BudgetManager.h"


using namespace std;

void BudgetManager::addIncome()
{
    Income income;
    income = getDetailsOfIncome();
    incomes.push_back(income);

}

void BudgetManager::addExpense()
{
    Expense expense;
    expense = getDetailsOfExpense();
    expenses.push_back(expense);
}

Expense BudgetManager::getDetailsOfExpense()
{
     Expense expense;
    char sign;
    string amountStr;
    float amount;

    expense.setUserId(ID_LOGGED_USER);

    if (expenses.empty() == true)
      expense.setExpenseId(1);
    else
       expense.setExpenseId(expenses.back().getExpenseId() + 1);

    system("cls");
    cout<<"Czy wydatek dotyczy dnia dzisiejszego? Jezeli tak wpisz 't', jezeli nie wcisnij dowolny klawisz"<<endl;
    sign = getchar();
    if (sign == 't')
        expense.setExpenseDate(dateManager.getTodayDate());
    else
    {
        expense.setExpenseDate(dateManager.getDate());
    }
    cin.ignore();

    cout<<"Podaj czego dotyczy wydatek"<<endl;
    expense.setItem(AuxiliaryMethods::getLine());

    do
    {
        cout<<"Podaj wysokosc wydatku"<<endl;
        amountStr = AuxiliaryMethods::getLine();
    }
    while ((checkAmount (amountStr))==false);

    expense.setAmount(convertStringToFloat(amountStr));
    return expense;

}


Income BudgetManager::getDetailsOfIncome()
{
    Income income;
    char sign;
    string amountStr;
    float amount;

    income.setUserId(ID_LOGGED_USER);

    if (incomes.empty() == true)
      income.setIncomeId(1);
    else
       income.setIncomeId(incomes.back().getIncomeId() + 1);

    system("cls");
    cout<<"Czy przychod dotyczy dnia dzisiejszego? Jezeli tak wpisz 't', jezeli nie wcisnij dowolny klawisz"<<endl;
    sign = getchar();
    if (sign == 't')
        income.setIncomeDate(dateManager.getTodayDate());
    else
    {
        income.setIncomeDate(dateManager.getDate());
    }
    cin.ignore();

    cout<<"Podaj czego dotyczy przychod"<<endl;
    income.setItem(AuxiliaryMethods::getLine());

    do
    {
        cout<<"Podaj wysokosc przychodu"<<endl;
        amountStr = AuxiliaryMethods::getLine();
    }
    while ((checkAmount (amountStr))==false);

    income.setAmount(convertStringToFloat(amountStr));
    return income;

}

bool BudgetManager::checkAmount (string amount)
{
    for (int i=0; i<amount.length(); i++)
    {
        if (((amount[i]<='9')&&(amount[i]>='0'))|| ((amount[i]=='.') || (amount [i] == ',')));
        else
        {
            cout<<"Nieprawidlowa wartosc"<<endl;
            return false;
        }
    }
    return true;
}

float  BudgetManager::convertStringToFloat(string amount)
{
    float amountF;
    char* endChar;

    for (int i=0; i<amount.length(); i++)
    {
        if (amount[i]==',')
            amount[i] = '.';
    }
    const char * amountChar = amount.c_str();
    amountF = strtof(amountChar, &endChar);
    return amountF;

}

