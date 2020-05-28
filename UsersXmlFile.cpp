#include "UsersXmlFile.h"


using namespace std;




vector <User> UsersXmlFile::loadUsersFromFile()
{
     User user;
    vector <User> users;

      xmlUsers.Load("d:/OLA/programowanie/KURS/20200429_program_HomeBudget/HomeBudget/users.xml");
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

void UsersXmlFile::addUserToFile(User oneUser)
{
    xmlUsers.Load("d:/OLA/programowanie/KURS/20200429_program_HomeBudget/HomeBudget/users.xml");
    //  xmlUsers.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");

    xmlUsers.ResetPos();
    xmlUsers.FindElem();
    while ( xmlUsers.FindElem("user") );

    xmlUsers.OutOfElem();

    xmlUsers.AddElem( "user");
    xmlUsers.IntoElem();
    xmlUsers.AddElem( "userId", oneUser.getId());
    xmlUsers.AddElem( "login", oneUser.getLogin());
    xmlUsers.AddElem( "password",oneUser.getPassword());
    xmlUsers.AddElem( "name", oneUser.getName());
    xmlUsers.AddElem( "surname", oneUser.getSurname());


    xmlUsers.OutOfElem();

    xmlUsers.Save("d:/OLA/programowanie/KURS/20200429_program_HomeBudget/HomeBudget/users.xml");
}
