#include "AuxiliaryMethods.h"

using namespace std;

string AuxiliaryMethods::replaceFirstLetterToUpperCaseRemainingToLowerCase(string text)
{
     if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AuxiliaryMethods::getLine()
{
    string input = "";
    //cin.ignore();
    getline(cin, input);
    return input;
}


int AuxiliaryMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}

string AuxiliaryMethods::convertIntToStr(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

float  AuxiliaryMethods::convertStringToFloat(string amount)
{
    float amountF;
    char* endChar;

    for (int i=0; i<amount.length(); i++)
    {
        if (amount[i]==',')
            amount[i] = '.';
    }
    const char * amountChar = amount.c_str();
    amountF = strtof(amountChar, &endChar);
    return amountF;

}

string AuxiliaryMethods::convertFloatToStr(float amount)
{
stringstream stream;
stream << fixed << setprecision(2) << amount;
string amountStr = stream.str();
return amountStr;
}

char AuxiliaryMethods::getChar()
{
    string input = "";
    char sign = {0};

    while (true)
    {
        cin.sync();
        getline (cin, input);
        {
            sign = input[0];
            break;
        }
        cout<<"To nie jest znak"<<endl;
    }
    return sign;
}

Date  AuxiliaryMethods::convertDateStrToDate(string dateStr)
{
    Date oneDate;

    string dayFromDate = "", monthFromDate = "", yearFromDate = "";

    if (dateStr[8] == '0')
        dayFromDate = dateStr[9];
    else
        dayFromDate = string() + dateStr[8] + dateStr[9];

    if (dateStr[5] == '0')
        monthFromDate = dateStr[6];
    else
        monthFromDate = string() + dateStr[5] + dateStr[6];

    yearFromDate = string() + dateStr[0] + dateStr[1]+dateStr[2] + dateStr[3];

    oneDate.setDay(atoi(dayFromDate.c_str()));
    oneDate.setMonth(atoi(monthFromDate.c_str()));
    oneDate.setYear(atoi(yearFromDate.c_str()));

    return oneDate;
}

string AuxiliaryMethods::convertDateToStr(Date oneDate)
{
    string year, month, day, dateStr;
    year = AuxiliaryMethods::convertIntToStr(oneDate.getYear());
    month = AuxiliaryMethods::convertIntToStr(oneDate.getMonth());
    day = AuxiliaryMethods::convertIntToStr(oneDate.getDay());
    if (month.length()==1)
        month = '0'+ month;

    if (day.length()==1)
        day = '0'+ day;

    dateStr = year + "-" + month + "-" + day;

    return dateStr;
}
