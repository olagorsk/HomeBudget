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


void BalanceManager::printIncome(Income income)
{
    cout<<"Wartosc: "<<AuxiliaryMethods::convertFloatToStr(income.getAmount())<<" zl"<<endl;
    cout << "Data: "<<AuxiliaryMethods::convertDateToStr(income.getIncomeDate())<<endl;
    cout<<"Rodzaj: "<<income.getItem()<<endl<<endl;
}

void BalanceManager::printExpense(Expense expense)
{
    cout<<"Wartosc: "<<AuxiliaryMethods::convertFloatToStr(expense.getAmount())<<" zl"<<endl;
    cout << "Data: "<<AuxiliaryMethods::convertDateToStr(expense.getExpenseDate())<<endl;
    cout<<"Rodzaj: "<<expense.getItem()<<endl<<endl;
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
                printIncome(incomes[i]);
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
                printExpense(expenses[i]);
                sumOfExpenses+=expenses[i].getAmount();
            }
        }
    }
    cout<<endl<<"Suma przychodow wynosi: "<<AuxiliaryMethods::convertFloatToStr(sumOfIncomes)<<" zl"<<endl;
    cout<<"Suma wydatkow wynosi: "<<AuxiliaryMethods::convertFloatToStr(sumOfExpenses)<<" zl"<<endl;
    cout<<"Roznica przychody - wydatki: "<<AuxiliaryMethods::convertFloatToStr(sumOfIncomes - sumOfExpenses)<< "zl"<<endl<<endl;

    system("pause");
}

void BalanceManager::previousMonthBalance()
{
    system("cls");
    float sumOfIncomes = 0, sumOfExpenses = 0;
    int previousMonth = 0;
    int year=0;

    if (todayDate.getMonth()==1)
    {
        previousMonth = 12;
        year = todayDate.getYear()-1;
    }
    else
    {
        previousMonth = todayDate.getMonth()-1;
        year = todayDate.getYear();
    }

    cout<<"Przychody w poprzednim miesiacu"<<endl<<"---------------------------"<<endl;
    if (incomes.empty() == false)
    {
        for (int i=0; i<incomes.size(); i++)
        {
            if ((incomes[i].getIncomeDate().getYear()==year&&(incomes[i].getIncomeDate().getMonth()==previousMonth)))
            {
                printIncome(incomes[i]);
                sumOfIncomes+=incomes[i].getAmount();
            }
        }
    }


    cout<<endl<<"Wydatki w poprzednim miesiacu"<<endl<<"---------------------------"<<endl;

    if (expenses.empty() == false)
    {
        for (int i=0; i<expenses.size(); i++)
        {
            if ((expenses[i].getExpenseDate().getYear()==year)&&(expenses[i].getExpenseDate().getMonth()==previousMonth))
            {
                printExpense(expenses[i]);
                sumOfExpenses+=expenses[i].getAmount();
            }
        }
    }
    cout<<endl<<"Suma przychodow wynosi: "<<AuxiliaryMethods::convertFloatToStr(sumOfIncomes)<<" zl"<<endl;
    cout<<"Suma wydatkow wynosi: "<<AuxiliaryMethods::convertFloatToStr(sumOfExpenses)<<" zl"<<endl;
    cout<<"Roznica przychody - wydatki: "<<AuxiliaryMethods::convertFloatToStr(sumOfIncomes - sumOfExpenses)<< "zl"<<endl<<endl;

    system("pause");
}

void BalanceManager::givenDatesBalance (Date firstDate, Date secondDate)
{
    system("cls");
    float sumOfIncomes = 0, sumOfExpenses = 0;

    int i=0;
    int k=0;
    int m=0;

    if (incomes.empty() == false)
    {
        for  (i=0; i<incomes.size(); i++)
        {
            if ((incomes[i].getIncomeDate().getYear()==firstDate.getYear())
                    && (incomes[i].getIncomeDate().getMonth()==firstDate.getMonth())
                    &&(incomes[i].getIncomeDate().getDay()>=firstDate.getDay()))
            {
                k=i;
                break;
            }

            if ((incomes[i].getIncomeDate().getYear()==firstDate.getYear())
                    && incomes[i].getIncomeDate().getMonth()>(firstDate.getMonth()))
            {
                k=i;
                break;
            }

            if (incomes[i].getIncomeDate().getYear()>firstDate.getYear())
            {
                k=i;
                break;
            }
        }

        for  (i=incomes.size()-1; i>=0; i--)
        {
            if ((incomes[i].getIncomeDate().getYear()==secondDate.getYear())
                    && (incomes[i].getIncomeDate().getMonth()==secondDate.getMonth())
                    &&(incomes[i].getIncomeDate().getDay()<=secondDate.getDay()))
            {
                m=i;
                break;
            }

            if ((incomes[i].getIncomeDate().getYear()==secondDate.getYear())
                    && incomes[i].getIncomeDate().getMonth()<(secondDate.getMonth()))
            {
                m=i;
                break;
            }

            if (incomes[i].getIncomeDate().getYear()<secondDate.getYear())
            {
                m=i;
                break;
            }
        }
    }

    cout<<"Przychody i wydatki w okresie od "<<AuxiliaryMethods::convertDateToStr(firstDate)<<" do "<<AuxiliaryMethods::convertDateToStr(secondDate)<<endl<<endl;
    cout<<"PRZYCHODY "<<endl<<"---------------------------"<<endl;

    for ( i=k; i<=m; i++)
    {
        printIncome(incomes[i]);
        sumOfIncomes+=incomes[i].getAmount();
    }
    if (expenses.empty() == false)
    {
        k=0;
        m=0;
        for  (i=0; i<expenses.size(); i++)
        {
            if ((expenses[i].getExpenseDate().getYear()==secondDate.getYear())
                    && (expenses[i].getExpenseDate().getMonth()==secondDate.getMonth())
                    &&(expenses[i].getExpenseDate().getDay()>=secondDate.getDay()))
            {
                k=i;
                break;
            }

            if ((expenses[i].getExpenseDate().getYear()==secondDate.getYear())
                    && expenses[i].getExpenseDate().getMonth()>(secondDate.getMonth()))
            {
                k=i;
                break;
            }

            if (expenses[i].getExpenseDate().getYear()>secondDate.getYear())
            {
                k=i;
                break;
            }
        }

        for  (i=expenses.size()-1; i>=0; i--)
        {
            if ((expenses[i].getExpenseDate().getYear()==secondDate.getYear())
                    && (expenses[i].getExpenseDate().getMonth()==secondDate.getMonth())
                    &&(expenses[i].getExpenseDate().getDay()<=secondDate.getDay()))
            {
                m=i;
                break;
            }

            if ((expenses[i].getExpenseDate().getYear()==secondDate.getYear())
                    && expenses[i].getExpenseDate().getMonth()<(secondDate.getMonth()))
            {
                m=i;
                break;
            }

            if (expenses[i].getExpenseDate().getYear()<secondDate.getYear())
            {
                m=i;
                break;
            }
        }
    }

    cout<<"WYDATKI "<<endl<<"---------------------------"<<endl;
    for ( i=k; i<=m; i++)
    {
        printExpense(expenses[i]);
        sumOfExpenses+=expenses[i].getAmount();
    }

    cout<<endl<<"Suma przychodow wynosi: "<<AuxiliaryMethods::convertFloatToStr(sumOfIncomes)<<" zl"<<endl;
    cout<<"Suma wydatkow wynosi: "<<AuxiliaryMethods::convertFloatToStr(sumOfExpenses)<<" zl"<<endl;
    cout<<"Roznica przychody - wydatki: "<<AuxiliaryMethods::convertFloatToStr(sumOfIncomes - sumOfExpenses)<< "zl"<<endl<<endl;
    system("pause");
}

