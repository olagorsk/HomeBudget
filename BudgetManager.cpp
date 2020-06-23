#include "BudgetManager.h"


using namespace std;

void BudgetManager::addIncome()
{
    Income income;
    income = getDetailsOfIncome();
    incomesXmlFile.addIncomeToFile(income);
    incomes.push_back(income);

}

void BudgetManager::addExpense()
{
    Expense expense;
    expense = getDetailsOfExpense();
    expensesXmlFile.addExpenseToFile(expense);
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

    expense.setAmount(AuxiliaryMethods::convertStringToFloat(amountStr));
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

    income.setAmount(AuxiliaryMethods::convertStringToFloat(amountStr));
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

struct BudgetManager::IncomesSortYear
{
    inline bool operator() (Income income1, Income income2)
    {
        return (income1.getIncomeDate().getYear()< income2.getIncomeDate().getYear());
    }
};
struct BudgetManager::IncomesSortMonth
{
    inline bool operator() (Income income1, Income income2)
    {
        if (income1.getIncomeDate().getYear()==income2.getIncomeDate().getYear())
            return (income1.getIncomeDate().getMonth()< income2.getIncomeDate().getMonth());
        return false;
    }
};

struct BudgetManager::IncomesSortDay
{
    inline bool operator() (Income income1, Income income2)
    {
        if ((income1.getIncomeDate().getYear()==income2.getIncomeDate().getYear())&&(income1.getIncomeDate().getMonth()==income2.getIncomeDate().getMonth()))
            return income1.getIncomeDate().getDay()< income2.getIncomeDate().getDay();
        return false;
    }
};

struct BudgetManager::ExpensesSortYear
{
    inline bool operator() (Expense expense1, Expense expense2)
    {
        return (expense1.getExpenseDate().getYear()< expense2.getExpenseDate().getYear());
    }
};
struct BudgetManager::ExpensesSortMonth
{
    inline bool operator() (Expense expense1, Expense expense2)
    {
        if (expense1.getExpenseDate().getYear()==expense2.getExpenseDate().getYear())
            return (expense1.getExpenseDate().getMonth()< expense2.getExpenseDate().getMonth());
        return false;
    }
};

struct BudgetManager::ExpensesSortDay
{
    inline bool operator() (Expense expense1, Expense expense2)
    {
        if ((expense1.getExpenseDate().getYear()==expense2.getExpenseDate().getYear())&&(expense1.getExpenseDate().getMonth()==expense2.getExpenseDate().getMonth()))
            return expense1.getExpenseDate().getDay()< expense2.getExpenseDate().getDay();
        return false;
    }
};


vector <Income> BudgetManager::sortIncomes()
{
    sort(incomes.begin(), incomes.end(), IncomesSortYear());
    sort(incomes.begin(), incomes.end(), IncomesSortMonth());
    sort(incomes.begin(), incomes.end(), IncomesSortDay());
    return incomes;
}

vector <Expense> BudgetManager::sortExpense()
{
    sort(expenses.begin(), expenses.end(), ExpensesSortYear());
    sort(expenses.begin(), expenses.end(), ExpensesSortMonth());
    sort(expenses.begin(), expenses.end(), ExpensesSortDay());
    return expenses;
}


void BudgetManager::currentMonthBalance()
{
    system("cls");
    incomes = sortIncomes();
    expenses = sortExpense();
    float sumOfIncomes, sumOfExpenses;

    cout<<"Przychody w biezacym miesiacu"<<endl<<"---------------------------"<<endl;
    for (int i=0; i<incomes.size(); i++)
    {
        if ((incomes[i].getIncomeDate().getYear()==dateManager.getTodayDate().getYear())&&(incomes[i].getIncomeDate().getMonth()==dateManager.getTodayDate().getMonth()))
        {
            cout << "Data: "<<AuxiliaryMethods::convertDateToStr(incomes[i].getIncomeDate())<<endl;
            cout<<"Rodzaj: "<<incomes[i].getItem()<<endl;
            cout<<"Wartosc: "<<AuxiliaryMethods::convertFloatToStr(incomes[i].getAmount())<<" zl"<<endl;
            sumOfIncomes+=incomes[i].getAmount();
        }

    }

    cout<<endl<<"Wydatki w biezacym miesiacu"<<endl<<"---------------------------"<<endl;

    for (int i=0; i<incomes.size(); i++)
    {
        if ((expenses[i].getExpenseDate().getYear()==dateManager.getTodayDate().getYear())&&(expenses[i].getExpenseDate().getMonth()==dateManager.getTodayDate().getMonth()))
        {
            //   cout << "UserId: "<<expenses[i].getUserId()<<endl;
            //     cout << "Wydatek Id: "<<expenses[i].getExpenseId()<<endl;
            cout << "Data: "<<AuxiliaryMethods::convertDateToStr(expenses[i].getExpenseDate())<<endl;
            cout<<"Rodzaj: "<<expenses[i].getItem()<<endl;
            cout<<"Wartosc: "<<AuxiliaryMethods::convertFloatToStr(expenses[i].getAmount())<<" zl"<<endl;
            sumOfExpenses+=expenses[i].getAmount();
        }

    }

    cout<<endl<<"Suma przychodow wynosi: "<<AuxiliaryMethods::convertFloatToStr(sumOfIncomes)<<" zl"<<endl;
    cout<<"Suma wydatkow wynosi: "<<AuxiliaryMethods::convertFloatToStr(sumOfExpenses)<<" zl"<<endl;
    cout<<"Roznica przychody - wydatki: "<<AuxiliaryMethods::convertFloatToStr(sumOfIncomes - sumOfExpenses)<< "zl"<<endl;


    system("pause");
}




