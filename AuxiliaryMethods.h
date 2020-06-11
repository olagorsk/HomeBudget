#ifndef AUXILIATYMETHODS_H
#define AUXILIATYMETHODS_H

#include <iostream>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

class AuxiliaryMethods
{
public:
    static string replaceFirstLetterToUpperCaseRemainingToLowerCase(string text);
    static string getLine();
    static int convertStringToInt(string number);
    static string convertIntToStr(int number);


    static string convertFloatToStr(float amount);
    static float  convertStringToFloat(string amount);



};

#endif
