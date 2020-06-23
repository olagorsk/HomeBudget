#include "HomeBudget.h"

using namespace std;


void HomeBudget::userRegistration()
{
      userManager.userRegistration();
}

int HomeBudget::userLogging()
{
       userManager.userLogging();
    if (userManager.isUserLogged())
    {
        budgetManager = new BudgetManager(userManager.getIdLoggedUser());
    }
}

bool HomeBudget::isUserLogged()
{
    userManager.isUserLogged();
}

void HomeBudget::addIncome()
{
    budgetManager->addIncome();
}

void HomeBudget::addExpense()
{
    budgetManager->addExpense();
}

void HomeBudget::changePasswordOfLoggedUser()
{
    userManager.changePasswordOfLoggedUser();
}

int HomeBudget::userLoggingOut()
{
    userManager.userLoggingOut();
}

void HomeBudget::createBalance()
{
    budgetManager->createBalance();
}


char HomeBudget::selectOptionFromUserMenu()
{
      char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}

char HomeBudget::selectOptionFromBudgetMenu()
{
       char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice =  AuxiliaryMethods::getChar();

    return choice;
}
