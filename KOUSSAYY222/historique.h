#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDateTime>

class historique
{
    QString user,action;
    QDateTime dateh;
public:
    QString getuser(){return user;}
    QString getaction(){return action;}
    QDateTime getdateh(){return dateh;}


    historique();
    historique(QString,QString,QDateTime);
    QSqlQueryModel * afficher();
};

#endif // HISTORIQUE_H
