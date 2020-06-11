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

