#include "BalanceManager.h"



struct BalanceManager::IncomesSortYear
{
    inline bool operator() (Income income1, Income income2)
    {
        return (income1.getIncomeDate().getYear()< income2.getIncomeDate().getYear());
    }
};
struct BalanceManager::IncomesSortMonth
{
    inline bool operator() (Income income1, Income income2)
    {
        if (income1.getIncomeDate().getYear()==income2.getIncomeDate().getYear())
            return (income1.getIncomeDate().getMonth()< income2.getIncomeDate().getMonth());
        return false;
    }
};

struct BalanceManager::IncomesSortDay
{
    inline bool operator() (Income income1, Income income2)
    {
        if ((income1.getIncomeDate().getYear()==income2.getIncomeDate().getYear())&&(income1.getIncomeDate().getMonth()==income2.getIncomeDate().getMonth()))
            return income1.getIncomeDate().getDay()< income2.getIncomeDate().getDay();
        return false;
    }
};

struct BalanceManager::ExpensesSortYear
{
    inline bool operator() (Expense expense1, Expense expense2)
    {
        return (expense1.getExpenseDate().getYear()< expense2.getExpenseDate().getYear());
    }
};
struct BalanceManager::ExpensesSortMonth
{
    inline bool operator() (Expense expense1, Expense expense2)
    {
        if (expense1.getExpenseDate().getYear()==expense2.getExpenseDate().getYear())
            return (expense1.getExpenseDate().getMonth()< expense2.getExpenseDate().getMonth());
        return false;
    }
};

struct BalanceManager::ExpensesSortDay
{
    inline bool operator() (Expense expense1, Expense expense2)
    {
        if ((expense1.getExpenseDate().getYear()==expense2.getExpenseDate().getYear())&&(expense1.getExpenseDate().getMonth()==expense2.getExpenseDate().getMonth()))
            return expense1.getExpenseDate().getDay()< expense2.getExpenseDate().getDay();
        return false;
    }
};


vector <Income> BalanceManager::sortIncomes()
{
    sort(incomes.begin(), incomes.end(), IncomesSortYear());
    sort(incomes.begin(), incomes.end(), IncomesSortMonth());
    sort(incomes.begin(), incomes.end(), IncomesSortDay());
    return incomes;
}

vector <Expense> BalanceManager::sortExpenses()
{
    sort(expenses.begin(), expenses.end(), ExpensesSortYear());
    sort(expenses.begin(), expenses.end(), ExpensesSortMonth());
    sort(expenses.begin(), expenses.end(), ExpensesSortDay());
    return expenses;
}


void BalanceManager::currentMonthBalance()
{
    system("cls");
    float sumOfIncomes = 0, sumOfExpenses = 0;

    cout<<"Przychody w biezacym miesiacu"<<endl<<"---------------------------"<<endl;
    if (incomes.empty() == false)
    {
        for (int i=0; i<incomes.size(); i++)
        {
            if ((incomes[i].getIncomeDate().getYear()==todayDate.getYear()&&(incomes[i].getIncomeDate().getMonth()==todayDate.getMonth())))
        {
             cout<<"Wartosc: "<<AuxiliaryMethods::convertFloatToStr(incomes[i].getAmount())<<" zl"<<endl;
            cout << "Data: "<<AuxiliaryMethods::convertDateToStr(incomes[i].getIncomeDate())<<endl;
                cout<<"Rodzaj: "<<incomes[i].getItem()<<endl<<endl;

                sumOfIncomes+=incomes[i].getAmount();
            }

        }
    }


    cout<<endl<<"Wydatki w biezacym miesiacu"<<endl<<"---------------------------"<<endl;

    if (expenses.empty() == false)
    {
        for (int i=0; i<expenses.size(); i++)
        {
            if ((expenses[i].getExpenseDate().getYear()==todayDate.getYear())&&(expenses[i].getExpenseDate().getMonth()==todayDate.getMonth()))
            {
                cout<<"Wartosc: "<<AuxiliaryMethods::convertFloatToStr(expenses[i].getAmount())<<" zl"<<endl;
                cout << "Data: "<<AuxiliaryMethods::convertDateToStr(expenses[i].getExpenseDate())<<endl;
                cout<<"Rodzaj: "<<expenses[i].getItem()<<endl<<endl;

                sumOfExpenses+=expenses[i].getAmount();
            }

        }
    }
    cout<<endl<<"Suma przychodow wynosi: "<<AuxiliaryMethods::convertFloatToStr(sumOfIncomes)<<" zl"<<endl;
    cout<<"Suma wydatkow wynosi: "<<AuxiliaryMethods::convertFloatToStr(sumOfExpenses)<<" zl"<<endl;
    cout<<"Roznica przychody - wydatki: "<<AuxiliaryMethods::convertFloatToStr(sumOfIncomes - sumOfExpenses)<< "zl"<<endl;


    system("pause");
}

