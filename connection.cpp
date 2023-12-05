<<<<<<< HEAD
#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Nacef");
    db.setPassword("nacef");

    if (db.open())
        test = true;

    return test;
}

void Connection::closeConnection()
{
    db.close();
}


=======
#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Nacef");
    db.setPassword("nacef");

    if (db.open())
        test = true;

    return test;
}

void Connection::closeConnection()
{
    db.close();
}


>>>>>>> d8e75cc0f0e315cdd085192fe209afe4a45db9f0
