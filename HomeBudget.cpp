#include "HomeBudget.h"

using namespace std;


void HomeBudget::userRegistration()
{
      userManager.userRegistration();
}

int HomeBudget::userLogging()
{
       userManager.userLogging();
    if (userManager.isUserLogged())
    {
        budgetManager = new BudgetManager(userManager.getIdLoggedUser());
    }
}
