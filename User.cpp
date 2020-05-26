#include "User.h"

using namespace std;

void User::setId (int newId)
{
    if (newId >=0)
    userId = newId;
}
void User::setLogin (string newLogin)
{
    login = newLogin;
}
void User::setPassword (string newPassword)
{
    password = newPassword;
}

void User::setName (string newName)
{
    name = newName;
}
void User::setSurname (string newSurname)
{
    surname = newSurname;
}

int User::getId()
{
    return userId;
}
string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}
string User::getName()
{
    return name;
}
string User::getSurname()
{
    return surname;
}