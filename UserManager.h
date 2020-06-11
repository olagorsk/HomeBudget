#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "UsersXmlFile.h"

using namespace std;

class UserManager
{
vector<User>users;

UsersXmlFile usersXmlFile;

int idLoggedUser;


int getIdNewUser();
User getNewUserDetails();
bool checkLoginExistence(string login);
bool checkLoginPassword(string login);

public:

 UserManager(string usersFileName):usersXmlFile(usersFileName)
{
        users = usersXmlFile.loadUsersFromFile();
    };

void userRegistration();
void printAllUsers();
int userLogging();
void changePasswordOfLoggedUser();
int userLoggingOut();
int getIdLoggedUser();
bool isUserLogged();





};

#endif
