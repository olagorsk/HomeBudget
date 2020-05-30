#include "UsersXmlFile.h"


using namespace std;


vector <User> UsersXmlFile::loadUsersFromFile()
{
    User user;
    vector <User> users;

    xmlUsers.Load(USERS_FILE_NAME);
    xmlUsers.ResetPos();

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

void UsersXmlFile::addUserToFile(User user)
{

    xmlUsers.Load(USERS_FILE_NAME);

    if (xmlUsers.FindElem("user")==false)
    {
        xmlUsers.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }
    xmlUsers.ResetPos();
    xmlUsers.FindElem();
    while (xmlUsers.FindElem("user") );
    xmlUsers.OutOfElem();

    pushOneUserToXml(user);
    xmlUsers.Save(USERS_FILE_NAME);
}


void UsersXmlFile::pushOneUserToXml(User user)
{
    xmlUsers.AddElem("user");
    xmlUsers.IntoElem();
    xmlUsers.AddElem("userId", user.getId());
    xmlUsers.AddElem("login", user.getLogin());
    xmlUsers.AddElem("password",user.getPassword());
    xmlUsers.AddElem("name", user.getName());
    xmlUsers.AddElem("surname", user.getSurname());
    xmlUsers.OutOfElem();
}




void UsersXmlFile::changePasswordInXmlFile(User user)
{
    string idLoggedUserStr;
    idLoggedUserStr = AuxiliaryMethods::conversionIntToStr(user.getId());

    xmlUsers.Load(USERS_FILE_NAME);
    xmlUsers.ResetPos();
    while (xmlUsers.FindElem("user") )
    {
        xmlUsers.FindChildElem();
        if (xmlUsers.GetChildData()==idLoggedUserStr)
        {
            xmlUsers.FindChildElem("password");

            xmlUsers.RemoveChildElem();
            xmlUsers.AddChildElem("password", user.getPassword());
            break;
        }
    }
    xmlUsers.Save(USERS_FILE_NAME);
}
