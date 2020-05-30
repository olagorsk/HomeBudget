#include "UserManager.h"


using namespace std;

void UserManager::userRegistration()
{
    User user = getNewUserDetails();

    users.push_back(user);
    usersXmlFile.addUserToFile(user);

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

int UserManager::userLogging()
{
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::getLine();

    for (int i=0; i<users.size(); ++i)
    {
        if (users[i].getLogin() == login)
        {
            for (int test = 3; test > 0; test--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << test << ": ";
                 password = AuxiliaryMethods::getLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return idLoggedUser = users[i].getId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UserManager::changePasswordOfLoggedUser()
{
     string newPassword = "";
   User user;
     do
    {
        cout << "Podaj nowe haslo: ";
        newPassword = AuxiliaryMethods::getLine();
    }
    while (checkLoginPassword(newPassword)==false);

    for (int i=0; i<users.size(); ++i)
    {
        if (users[i].getId() == idLoggedUser)
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            user = users[i];
            system("pause");
            break;

        }
    }
    usersXmlFile.changePasswordInXmlFile(user);

}

int UserManager::userLoggingOut()
{
       idLoggedUser = 0;
    cout<<endl<<"Wylogowales sie"<<endl;
    cout<<"Id zalogowanego uzytkownika "<<idLoggedUser<<endl;
    system("pause");
    return idLoggedUser;

}

