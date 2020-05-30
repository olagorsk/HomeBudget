#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class HomeBudget
{
    UserManager userManager;




public:
    HomeBudget(string usersFileName):userManager(usersFileName) {};
    void userRegistration();
    int userLogging();


};

#endif
