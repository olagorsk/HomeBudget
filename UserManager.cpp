#include "UserManager.h"


using namespace std;

void UserManager::userRegistration()
{
     User user = getNewUserDetails();

    users.push_back(user);
  //  plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl;
    system("pause");

}

User UserManager::getNewUserDetails()
{
    User user;
    user.setId(getIdNewUser());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin>> login;
       user.setLogin(login);
    }
    while (checkLoginExistence(user.getLogin()) == true);
    string password;
    cout << "Podaj haslo: ";
    cin>>password;
    user.setPassword(password);

    string name;
    cout<<"Podaj imie: ";
    name = AuxiliaryMethods::getLine();
    name = AuxiliaryMethods::replaceFirstLetterToUpperCaseRemainingToLowerCase(name);
    user.setName(name);

    string surname;
    cout<<"Podaj nazwisko: ";
    surname = AuxiliaryMethods::getLine();
    surname = AuxiliaryMethods::replaceFirstLetterToUpperCaseRemainingToLowerCase(name);
    user.setSurname(surname);

    return user;
}


int UserManager::getIdNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::checkLoginExistence(string login)
{
    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin()==login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::printAllUsers()
{
     for (int i=0; i<users.size(); i++)
    {
        cout << users[i].getId()<<endl;
        cout << users[i].getLogin()<<endl;
        cout << users[i].getPassword()<<endl;
    }
}
