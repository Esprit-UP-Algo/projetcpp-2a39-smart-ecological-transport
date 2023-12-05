<<<<<<< HEAD
#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>


class Connection
{
    QSqlDatabase db;

public:

    Connection();
    bool createconnect();
    void closeConnection();


};

#endif // CONNECTION_H



=======
#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>


class Connection
{
    QSqlDatabase db;

public:

    Connection();
    bool createconnect();
    void closeConnection();


};

#endif // CONNECTION_H



>>>>>>> d8e75cc0f0e315cdd085192fe209afe4a45db9f0
