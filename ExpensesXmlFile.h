#ifndef EXPENSESXMLFILE_H
#define  EXPENSESXMLFILE_H

#include <iostream>
#include <cstdlib>
#include "Markup.h"
#include <vector>
#include <sstream>


#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"
#include "Expense.h"


using namespace std;

class ExpensesXmlFile
{
  string expensesFileName;
    CMarkup xmlExpenses;
   void pushOneExpenseToXml(Expense expense);


  public:

ExpensesXmlFile (string xmlExpensesFileName): expensesFileName(xmlExpensesFileName){}
      void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int idLoggedUser);

};






#endif
