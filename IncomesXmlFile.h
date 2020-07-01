#ifndef INCOMESXMLFILE_H
#define INCOMESXMLFILE_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>

#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"
#include "Income.h"



using namespace std;

class IncomesXmlFile
{
    string incomesFileName;
    CMarkup xmlIncomes;
    void pushOneIncomeToXml(Income income);
    int lastIncomeId;

public:
    IncomesXmlFile (string xmlIncomesFileName): incomesFileName(xmlIncomesFileName)
    {
        lastIncomeId = 0;
    }

    void addIncomeToFile(Income income);
    vector <Income> loadIncomesFromFile(int idLoggedUser);
    int getLastIncomeId();

};


#endif
