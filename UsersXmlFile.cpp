#include "UsersXmlFile.h"


using namespace std;


vector <User> UsersXmlFile::loadUsersFromFile()
{
    User user;
    vector <User> users;

    xmlUsers.Load(USERS_FILE_NAME);


    xmlUsers.ResetPos();
//  xmlUsers.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    while ( xmlUsers.FindElem("user") )
    {
        xmlUsers.IntoElem();
        xmlUsers.FindElem("userId");
        user.setId(AuxiliaryMethods::conversionStringToInt(xmlUsers.GetData()));

        xmlUsers.FindElem("login");
        user.setLogin(xmlUsers.GetData());

        xmlUsers.FindElem("password");
        user.setPassword(xmlUsers.GetData());

        xmlUsers.FindElem("name");
        user.setName(xmlUsers.GetData());

        xmlUsers.FindElem("surname");
        user.setSurname(xmlUsers.GetData());

        xmlUsers.OutOfElem();
        users.push_back(user);
    }
    return users;
}

void UsersXmlFile::addUserToFile(User oneUser)
{
   if (xmlUsers.Load(USERS_FILE_NAME)==false)
    xmlUsers.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");

    xmlUsers.ResetPos();
    xmlUsers.FindElem();
    while (xmlUsers.FindElem("user") );

    xmlUsers.OutOfElem();

    xmlUsers.AddElem("user");
    xmlUsers.IntoElem();
    xmlUsers.AddElem("userId", oneUser.getId());
    xmlUsers.AddElem("login", oneUser.getLogin());
    xmlUsers.AddElem("password",oneUser.getPassword());
    xmlUsers.AddElem("name", oneUser.getName());
    xmlUsers.AddElem("surname", oneUser.getSurname());
    xmlUsers.OutOfElem();

    xmlUsers.Save(USERS_FILE_NAME);
}
