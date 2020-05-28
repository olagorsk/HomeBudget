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
