#include "ExpensesXmlFile.h"


using namespace std;


vector <Expense> ExpensesXmlFile::loadExpensesFromFile(int idLoggedUser)
{
    Expense expense;
    vector <Expense> expenses;
    int userIdFromXmlFile;

    xmlExpenses.Load("d:/OLA/programowanie/KURS/20200429_program_HomeBudget/HomeBudget/expenses.xml");
    xmlExpenses.ResetPos();

    while ( xmlExpenses.FindElem("expense") )
    {

         xmlExpenses.IntoElem();

        xmlExpenses.FindElem("userId");
        userIdFromXmlFile = AuxiliaryMethods::convertStringToInt(xmlExpenses.GetData());
        if (userIdFromXmlFile == idLoggedUser)
        {
        expense.setUserId(idLoggedUser);

        xmlExpenses.FindElem("expenseId");
        expense.setExpenseId(AuxiliaryMethods::convertStringToInt(xmlExpenses.GetData()));

        xmlExpenses.FindElem("date");
        expense.setExpenseDate(DateManager::convertDateStrToDate(xmlExpenses.GetData()));

        xmlExpenses.FindElem("item");
        expense.setItem(xmlExpenses.GetData());

        xmlExpenses.FindElem("amount");
        expense.setAmount(AuxiliaryMethods::convertStringToFloat(xmlExpenses.GetData()));

        xmlExpenses.OutOfElem();
        expenses.push_back(expense);
        }
             else
        xmlExpenses.OutOfElem();

    }
    return expenses;
}

void ExpensesXmlFile::addExpenseToFile(Expense expense)
{

    xmlExpenses.Load("d:/OLA/programowanie/KURS/20200429_program_HomeBudget/HomeBudget/expenses.xml");

    if (xmlExpenses.FindElem("expense")==false)
    {
        xmlExpenses.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }
    xmlExpenses.ResetPos();
    xmlExpenses.FindElem();
    while (xmlExpenses.FindElem("expense") );
    xmlExpenses.OutOfElem();

    pushOneExpenseToXml(expense);
    xmlExpenses.Save("d:/OLA/programowanie/KURS/20200429_program_HomeBudget/HomeBudget/expenses.xml");
}


void ExpensesXmlFile::pushOneExpenseToXml(Expense expense)
{
    xmlExpenses.AddElem("expense");
    xmlExpenses.IntoElem();
    xmlExpenses.AddElem("userId", expense.getUserId());
    xmlExpenses.AddElem("expenseId", expense.getExpenseId());
    xmlExpenses.AddElem("date",DateManager::convertDateToStr(expense.getExpenseDate()));
    xmlExpenses.AddElem("item", expense.getItem());
    xmlExpenses.AddElem("amount", AuxiliaryMethods::convertFloatToStr(expense.getAmount()));
    xmlExpenses.OutOfElem();
}

