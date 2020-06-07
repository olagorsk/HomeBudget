#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <windows.h>
#include <winbase.h>
#include <vector>
#include <sstream>

#include "Date.h"
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{

Date todayDate;

 vector<Date>dates;

string dateStr;

bool checkDateFormat();
bool checkMonth (Date oneDate);
bool checkYear(int year);
bool  checkLeapYear (int year);
bool  checkDay(Date oneDate, bool leapYear);
Date  convertDateStrToDate ();
bool  checkDate(Date oneDate);



public:
DateManager()
{
    todayDate = getTodayDate();
}

Date getTodayDate();
Date getDate();
string convertDateToStr(Date oneDate);





};

#endif