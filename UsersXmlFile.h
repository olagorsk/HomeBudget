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
  const string USERS_FILE_NAME;
    CMarkup xmlUsers;

  public:
      UsersXmlFile (string usersFileName):USERS_FILE_NAME(usersFileName)
      {

      };

      void addUserToFile(User oneUser);
    vector <User> loadUsersFromFile();


};






#endif
