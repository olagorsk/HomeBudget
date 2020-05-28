#include "UsersXmlFile.h"


using namespace std;

void UsersXmlFile::addUserToTile(User oneUser)
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

    xmlUsers.OutOfElem();
    xmlUsers.IntoElem();
    xmlUsers.AddElem( "details");

    xmlUsers.IntoElem();
    xmlUsers.AddElem( "login", oneUser.getLogin());
    xmlUsers.AddElem( "password",oneUser.getPassword());
    xmlUsers.AddElem( "name", oneUser.getName());
    xmlUsers.AddElem( "surname", oneUser.getSurname());

    xmlUsers.OutOfElem();
    xmlUsers.OutOfElem();
    xmlUsers.OutOfElem();

    xmlUsers.Save("d:/OLA/programowanie/KURS/20200429_program_HomeBudget/HomeBudget/users.xml");
}
