#ifndef USERSXMLFILE_H
#define USERSXMLFILE_H

#include <iostream>
#include <cstdlib>
#include "Markup.h"
#include <vector>
#include <sstream>

#include "User.h"
#include "AuxiliaryMethods.h"


using namespace std;

class UsersXmlFile
{
  string usersFileName;
    CMarkup xmlUsers;

  public:

      void addUserToFile(User oneUser);
    vector <User> loadUsersFromFile();


};






#endif
