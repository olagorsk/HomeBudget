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

bool BalanceManager::checkFirstDateIncomes(int i)
{
    if ((incomes[i].getIncomeDate().getYear())>(firstDate.getYear()))
        return true;
    if ((incomes[i].getIncomeDate().getYear()==firstDate.getYear())
            && incomes[i].getIncomeDate().getMonth()>(firstDate.getMonth()))
        return true;
    if ((incomes[i].getIncomeDate().getYear()==firstDate.getYear())
            && (incomes[i].getIncomeDate().getMonth()==firstDate.getMonth())
            &&(incomes[i].getIncomeDate().getDay()>=firstDate.getDay()))
        return true;
    else
        return false;
}

bool BalanceManager::checkFirstDateExpenses( int i)
{
    if ((expenses[i].getExpenseDate().getYear()==firstDate.getYear())
            && (expenses[i].getExpenseDate().getMonth()==firstDate.getMonth())
            &&(expenses[i].getExpenseDate().getDay()>=firstDate.getDay()))
        return true;
    if ((expenses[i].getExpenseDate().getYear()==firstDate.getYear())
            && expenses[i].getExpenseDate().getMonth()>(firstDate.getMonth()))
        return true;
    if (expenses[i].getExpenseDate().getYear()>firstDate.getYear())
        return true;
    else
        return false;
}

bool BalanceManager::checkSecondDateIncomes( int i)
{
    if ((incomes[i].getIncomeDate().getYear()==secondDate.getYear())
            && (incomes[i].getIncomeDate().getMonth()==secondDate.getMonth())
            &&(incomes[i].getIncomeDate().getDay()<=secondDate.getDay()))
        return true;
    if ((incomes[i].getIncomeDate().getYear()==secondDate.getYear())
            && incomes[i].getIncomeDate().getMonth()<(secondDate.getMonth()))
        return true;
    if (incomes[i].getIncomeDate().getYear()<secondDate.getYear())
        return true;
    else
        return false;
}

bool BalanceManager::checkSecondDateExpenses(int i)
{
    if ((expenses[i].getExpenseDate().getYear()==secondDate.getYear())
            && (expenses[i].getExpenseDate().getMonth()==secondDate.getMonth())
            &&(expenses[i].getExpenseDate().getDay()<=secondDate.getDay()))
        return true;
    if ((expenses[i].getExpenseDate().getYear()==secondDate.getYear())
            && expenses[i].getExpenseDate().getMonth()<(secondDate.getMonth()))
        return true;
    if (expenses[i].getExpenseDate().getYear()<secondDate.getYear())
        return true;
    else
        return false;

}

void BalanceManager::givenDatesBalance(Date firstDateBalance, Date secondDateBalance)
{
    firstDate = firstDateBalance, secondDate = secondDateBalance;
    float sumOfIncomes = 0, sumOfExpenses = 0;
    int k=0, m=0;
    firstDateExistance==false, secondDateExistance==false;

    system("cls");
    if (incomes.empty() == false)
        checkIncomesInGivenDates(k, m);

    cout<<"Przychody i wydatki w okresie od "<<AuxiliaryMethods::convertDateToStr(firstDate)<<" do "<<AuxiliaryMethods::convertDateToStr(secondDate)<<endl<<endl;

    if ((firstDateExistance==true)&&(secondDateExistance==true)&&(k<=m))
    {
        cout<<"PRZYCHODY "<<endl<<"---------------------------"<<endl;
        for ( int i=k; i<=m; i++)
        {
            printIncome(incomes[i]);
            sumOfIncomes+=incomes[i].getAmount();
        }
    }
    else
    {
        cout<<"W tym okresie nie masz zadnych przychodow"<<endl;
        Sleep(1500);
    }

    k=0, m=0;
    firstDateExistance=false, secondDateExistance=false;
    if (expenses.empty() == false)
        checkExpensesInGivenDates(k, m);

    if ((firstDateExistance==true)&&(secondDateExistance==true)&&(k<=m))
    {
        cout<<"WYDATKI "<<endl<<"---------------------------"<<endl;
        for ( int i=k; i<=m; i++)
        {
            printExpense(expenses[i]);
            sumOfExpenses+=expenses[i].getAmount();
        }
    }
    else
    {
        cout<<"W tym okresie nie masz zadnych wydatkow"<<endl;
        Sleep(1500);
    }
    cout<<endl<<"Suma przychodow wynosi: "<<AuxiliaryMethods::convertFloatToStr(sumOfIncomes)<<" zl"<<endl;
    cout<<"Suma wydatkow wynosi: "<<AuxiliaryMethods::convertFloatToStr(sumOfExpenses)<<" zl"<<endl;
    cout<<"Roznica przychody - wydatki: "<<AuxiliaryMethods::convertFloatToStr(sumOfIncomes - sumOfExpenses)<< "zl"<<endl<<endl;
    system("pause");
}

void BalanceManager::checkIncomesInGivenDates(int &k, int &m)
{
    for  (int i=0; i<incomes.size(); i++)
    {
        if (checkFirstDateIncomes(i))
        {
            k=i;
            firstDateExistance = true;
            break;
        }
    }
    if (firstDateExistance==true)
    {
        for  (int i=incomes.size()-1; i>=0; i--)
        {
            if (checkSecondDateIncomes(i))
            {
                m=i;
                secondDateExistance=true;
                break;
            }
        }
    }
}

void BalanceManager::checkExpensesInGivenDates(int &k, int &m)
{
    for  (int i=0; i<expenses.size(); i++)
    {

        if (checkFirstDateExpenses(i))
        {
            k=i;
            firstDateExistance = true;
            break;
        }
    }
    if (firstDateExistance==true)
    {
        for  (int i=expenses.size()-1; i>=0; i--)
        {
            if (checkSecondDateExpenses(i))
            {
                m=i;
                secondDateExistance=true;
                break;
            }
        }
    }
}

