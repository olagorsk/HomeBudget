#include "DateManager.h"


using namespace std;

Date DateManager::getTodayDate()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    todayDate.setDay(st.wDay);
    todayDate.setMonth(st.wMonth);
    todayDate.setYear(st.wYear);

    return todayDate;

}

Date DateManager::getDate()
{

    Date oneDate;
    do
    {
        do
        {
            cout<<endl<<"Wpisz date: ";
            cin>>dateStr;
        }
        while  (checkDateFormat()==false);
        oneDate = AuxiliaryMethods::convertDateStrToDate(dateStr);
    }
    while (checkDate(oneDate)==false);

    return oneDate;
}

bool DateManager::checkDateFormat()
{

    if (dateStr[4]!='-'||dateStr[7]!='-')
    {
        cout<<"Niepoprawny format daty, wpisz date w formacie rrrr-mm-dd"<<endl;
        return false;
    }

    for (int i=0; i<10; i++)
    {
        if ((dateStr[i]>='0' && dateStr[i]<='9')||dateStr[i]=='-');
        else
        {
            cout<<"Niepoprawny format daty, wpisz date w formacie rrrr-mm-dd"<<endl;
            return false;
        }
    }
    return true;
}


bool  DateManager::checkMonth (Date oneDate)
{
    if(oneDate.getMonth() > 0 && oneDate.getMonth() < 13);
    else
    {
        cout<<"Niepoprawny miesiac w dacie, wpisz date w formacie rrrr-mm-dd"<<endl;
        return false;
    }
    if
    (oneDate.getYear()==todayDate.getYear())
    {
        if (oneDate.getMonth()<=todayDate.getMonth());
        else
        {
            cout<<"Niepoprawny miesiac w dacie, wpisz dane z biezacego miesiaca"<<endl;
            return false;
        }
        if (oneDate.getMonth()<=todayDate.getMonth());
        else
        {
            cout<<"Niepoprawny miesiac w dacie, wpisz dane z biezacego miesiaca"<<endl;
            return false;
        }
    }
    return true;
}


bool  DateManager::checkYear(int year)
{
    if ((year<=todayDate.getYear())&&(year>=2000))
        return true;
    else
    {
        cout<<"Niepoprawny rok"<<endl;
        return false;
    }
}


bool  DateManager::checkLeapYear (int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}

bool  DateManager::checkDay(Date oneDate, bool leapYear)
{
    if ((oneDate.getMonth())==1 || (oneDate.getMonth())==3 || (oneDate.getMonth())==5 || (oneDate.getMonth())==7 || (oneDate.getMonth())==8 || (oneDate.getMonth())==10 || (oneDate.getMonth())==12)
        if (oneDate.getDay()>0 && oneDate.getDay()<32);
        else
        {
            cout<<"Niepoprawna data"<<endl;
            return false;
        }

    if ((oneDate.getMonth())==4 || (oneDate.getMonth())==6 || (oneDate.getMonth())==9 || (oneDate.getMonth())==11 )
        if (oneDate.getDay()>0 && oneDate.getDay()<31);
        else
        {
            cout<<"Niepoprawna data"<<endl;
            return false;
        }

    if (oneDate.getMonth()==2)
    {
        if (leapYear == true)
            if(oneDate.getDay()>0 && oneDate.getDay()<30);
            else
            {
                cout<<"Niepoprawna data"<<endl;
                return false;
            }
        if(leapYear == false)
            if(oneDate.getDay()>0 && oneDate.getDay()<29);
            else
            {
                cout<<"Niepoprawna data"<<endl;
                return false;
            }
    }
    return true;
}




bool  DateManager::checkDate(Date oneDate)
{
    bool leapYear = checkLeapYear(oneDate.getYear());
    if ((checkYear(oneDate.getYear())==true)&&(checkMonth(oneDate)==true) &&  (checkDay(oneDate, leapYear))==true)
        return true;
    else
        return false;
}


