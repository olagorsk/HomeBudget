#include "IncomesXmlFile.h"


using namespace std;


vector <Income> IncomesXmlFile::loadIncomesFromFile(int idLoggedUser)
{
    Income income;
    vector <Income> incomes;
    int userIdFromXmlFile;

    xmlIncomes.Load(incomesFileName);
    xmlIncomes.ResetPos();

    while ( xmlIncomes.FindElem("income") )
    {
        xmlIncomes.IntoElem();

        xmlIncomes.FindElem("userId");
        userIdFromXmlFile = AuxiliaryMethods::convertStringToInt(xmlIncomes.GetData());

        xmlIncomes.FindElem("incomeId");
        lastIncomeId = AuxiliaryMethods::convertStringToInt(xmlIncomes.GetData());

        if (userIdFromXmlFile == idLoggedUser)
        {
            income.setUserId(idLoggedUser);

            xmlIncomes.FindElem("incomeId");
            income.setIncomeId(AuxiliaryMethods::convertStringToInt(xmlIncomes.GetData()));

            xmlIncomes.FindElem("date");
            income.setIncomeDate(AuxiliaryMethods::convertDateStrToDate(xmlIncomes.GetData()));

            xmlIncomes.FindElem("item");
            income.setItem(xmlIncomes.GetData());

            xmlIncomes.FindElem("amount");
            income.setAmount(AuxiliaryMethods::convertStringToFloat(xmlIncomes.GetData()));

            xmlIncomes.OutOfElem();
            incomes.push_back(income);
        }
        else
            xmlIncomes.OutOfElem();

    }
    return incomes;
}

void IncomesXmlFile::addIncomeToFile(Income income)
{
    xmlIncomes.Load(incomesFileName);

    if (xmlIncomes.FindElem("income")==false)
    {
        xmlIncomes.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }
    xmlIncomes.ResetPos();
    xmlIncomes.FindElem();
    while (xmlIncomes.FindElem("income") );
    xmlIncomes.OutOfElem();

    pushOneIncomeToXml(income);
    xmlIncomes.Save(incomesFileName);
    lastIncomeId++;
}

int IncomesXmlFile::getLastIncomeId()
{
    return lastIncomeId;
}

void IncomesXmlFile::pushOneIncomeToXml(Income income)
{
    xmlIncomes.AddElem("income");
    xmlIncomes.IntoElem();
    xmlIncomes.AddElem("userId", income.getUserId());
    xmlIncomes.AddElem("incomeId", income.getIncomeId());
    xmlIncomes.AddElem("date",AuxiliaryMethods::convertDateToStr(income.getIncomeDate()));
    xmlIncomes.AddElem("item", income.getItem());
    xmlIncomes.AddElem("amount", AuxiliaryMethods::convertFloatToStr(income.getAmount()));
    xmlIncomes.OutOfElem();
}
