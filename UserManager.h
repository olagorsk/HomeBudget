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


int getIdNewUser();
User getNewUserDetails();
bool checkLoginExistence(string login);
bool checkLoginPassword(string login);

public:
void userRegistration();
void printAllUsers();




};

#endif
