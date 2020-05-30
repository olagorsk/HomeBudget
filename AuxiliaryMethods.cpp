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


int AuxiliaryMethods::conversionStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}

string AuxiliaryMethods::conversionIntToStr(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
