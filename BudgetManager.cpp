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
    int lastExpenseId = (expensesXmlFile.getLastExpenseId()+1);

    expense.setUserId(ID_LOGGED_USER);
    expense.setExpenseId(lastExpenseId);

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
    int lastIncomeId = (incomesXmlFile.getLastIncomeId()+1);

    income.setUserId(ID_LOGGED_USER);
    income.setIncomeId(lastIncomeId);

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

void BudgetManager::currentMonthBalance()
{
    if ((incomes.empty() == false)|| (expenses.empty() == false))
    {
        balanceManager = new BalanceManager(incomes, expenses, dateManager.getTodayDate());
        balanceManager->currentMonthBalance();
    }
    else
    {
        cout<<"Nie wprowadziles jeszcze zadnych przychodow i wydatkow"<<endl;
        Sleep(1500);
    }
}

void BudgetManager::previousMonthBalance()
{
    if ((incomes.empty() == false)|| (expenses.empty() == false))
    {
        balanceManager = new BalanceManager(incomes, expenses, dateManager.getTodayDate());
        balanceManager->previousMonthBalance();
    }
    else
    {
        cout<<"Nie wprowadziles jeszcze zadnych przychodow i wydatkow"<<endl;
        Sleep(1500);
    }
}

void BudgetManager::givenDatesBalance()
{
    Date firstDateBalance, secondDateBalance;
    if ((incomes.empty() == false)|| (expenses.empty() == false))
    {
        system("cls");
        do
        {
            cout<<"Podaj pierwsza date (od kiedy) ";
            firstDateBalance = dateManager.getDate();
            cout<<"Podaj druga date (do kiedy) ";
            secondDateBalance = dateManager.getDate();
        }
        while (checkFirstSecondDate(firstDateBalance, secondDateBalance)==false);

        balanceManager = new BalanceManager(incomes, expenses, dateManager.getTodayDate());
        balanceManager->givenDatesBalance(firstDateBalance, secondDateBalance);
    }
    else
    {
        cout<<"Nie wprowadziles jeszcze zadnych przychodow i wydatkow"<<endl;
        Sleep(1500);
    }
}

bool BudgetManager::checkFirstSecondDate(Date firstDate, Date secondDate)
{
    if (firstDate.getYear()>secondDate.getYear())
    {
        cout<<"Niepoprawna kolejnosc dat"<<endl;
        return false;
    }

    if (firstDate.getYear()==secondDate.getYear()&&firstDate.getMonth()>secondDate.getMonth())
    {
        cout<<"Niepoprawna kolejnosc dat"<<endl;
        return false;
    }
    if ((firstDate.getYear()==secondDate.getYear())&&(firstDate.getMonth()==secondDate.getMonth())&&(firstDate.getDay()>secondDate.getDay()))
    {
        cout<<"Niepoprawna kolejnosc dat"<<endl;
        return false;
    }
    return true;
}

void BudgetManager::printIncomes()
{
    for (int i=0; i<incomes.size(); i++)
    {
        cout<<"IncomeId: "<<  incomes[i].getIncomeId()<<endl;
    }
}

