#include "UserManager.h"


using namespace std;

void UserManager::userRegistration()
{
    User oneUser = getNewUserDetails();

    users.push_back(oneUser);
    usersXmlFile.addUserToTile(oneUser);
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
        do
        {
            cout << "Podaj login: ";
            login = AuxiliaryMethods::getLine();
        }
        while (checkLoginPassword(login)==false);
        user.setLogin(login);
    }
    while (checkLoginExistence(user.getLogin()) == true);
    string password;
    do
    {
        cout << "Podaj haslo: ";
        password = AuxiliaryMethods::getLine();
    }
    while (checkLoginPassword(password)==false);
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


bool UserManager::checkLoginPassword(string login)
{

    for (int i=0; i<login.length(); i++)
    {
        if (login[i]==32)
        {
            cout<<"Login/haslo nie moga zawierac spacji"<<endl;
            return false;
        }
        if ((login[i]>='0' && login[i]<='9')||(login[i]>='A'&& login[i]<='Z')||(login[i]>='a'&& login[i]<='z'));

        else
        {
            cout<<"Login/haslo moze zawierac tylko cyfry i litery"<<endl;
            return false;
        }
        if (i==login.length()-1)
            return true;
    }
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
