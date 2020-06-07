#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
{

    int day, month, year;
    // Date(int day, int month, int year) : y(year), m(month), d(day) {}

public:

void setDay(int newDay);
void setMonth (int newMonth);
void setYear(int newYear);

int getDay();
int getMonth();
int getYear();

};

#endif
