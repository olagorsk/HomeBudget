#ifndef EXPENSESXMLFILE_H
#define  EXPENSESXMLFILE_H

#include <iostream>
#include <cstdlib>
#include "Markup.h"
#include <vector>
#include <sstream>


#include "AuxiliaryMethods.h"
#include "Expense.h"


using namespace std;

class ExpensesXmlFile
{
  string expensesXmlFileName;
    CMarkup xmlExpenses;


  //  void pushOneUserToXml(User oneUser);

  public:


      void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int idLoggedUser);



};






#endif
