#include <iostream>

#include "HomeBudget.h"

using namespace std;

int _main()
{
   HomeBudget homeBudget;
   homeBudget.userRegistration();
}

#include "UserManager.h"

int main()
{
    UserManager userManager;
       //userManager.loadUsersFromFile();
     //  userManager.printAllUsers();

    userManager.userRegistration();
    userManager.userRegistration();
    userManager.userRegistration();
    userManager.userRegistration();
    userManager.printAllUsers();




}
