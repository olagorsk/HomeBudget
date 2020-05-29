#include <iostream>

#include "HomeBudget.h"

using namespace std;

int main()
{
   HomeBudget homeBudget ("users.xml");
   homeBudget.userRegistration();
}
/*
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
*/
