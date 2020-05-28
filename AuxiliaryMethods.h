#ifndef AUXILIATYMETHODS_H
#define AUXILIATYMETHODS_H

#include <iostream>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class AuxiliaryMethods
{
public:
    static string replaceFirstLetterToUpperCaseRemainingToLowerCase(string text);
    static string getLine();
    static int conversionStringToInt(string number);
};

#endif
