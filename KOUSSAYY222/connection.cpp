#include "connection.h"
Connection::Connection()
{

}

bool Connection::createconnection()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("koussay");//inserer nom de l'utilisateur
db.setPassword("koussay");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

return  test;
}

void Connection::closeconnection(){db.close();}