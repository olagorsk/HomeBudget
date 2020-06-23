#include <iostream>

#include "HomeBudget.h"

using namespace std;

int main()
{

   HomeBudget homeBudget("users.xml");
    char choice;

    while(true)
    {
        if (homeBudget.isUserLogged()==false)
        {

           choice = homeBudget.selectOptionFromUserMenu();
            switch(choice)
            {
            case '1':
                homeBudget.userRegistration();
                break;
            case '2':
                homeBudget.userLogging();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout<<endl<<"Nie ma takiej opcji w menu"<<endl;
                system("pause");
                break;
            }
        }

        else
        {
            choice = homeBudget.selectOptionFromBudgetMenu();
            switch(choice)
            {
            case '1':
                homeBudget.addIncome();
                break;
            case '2':
               homeBudget.addExpense();
                break;
            case '3':
                homeBudget.createBalance();
                break;
                /*
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;*/
            case '6':
                homeBudget.changePasswordOfLoggedUser();
                break;
            case '7':
                homeBudget.userLoggingOut();
                break;

            }
        }

    }

    return 0;
}
