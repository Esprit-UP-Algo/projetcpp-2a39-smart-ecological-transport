#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("SourceProjet2A");
db.setUserName("meriembd");//inserer nom de l'utilisateur
db.setPassword("meriem12");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
void Connection::closeconnect(){db.close();}


