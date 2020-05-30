#include <iostream>

#include "HomeBudget.h"

using namespace std;

int _main()
{
   HomeBudget homeBudget ("users.xml");
   homeBudget.userRegistration();
   homeBudget.userRegistration();
 homeBudget.userRegistration();
   //homeBudget.userRegistration();
  // int idTEST = homeBudget.userLogging();
  // cout<<"Id zalogowanego uzytkownika "<< idTEST<<endl;
}

#include "UserManager.h"

int main()
{
    UserManager userManager("users.xml");
       //userManager.loadUsersFromFile();
     //  userManager.printAllUsers();


    userManager.userLogging();

    //userManager.printAllUsers();
    userManager.changePasswordOfLoggedUser();





}

