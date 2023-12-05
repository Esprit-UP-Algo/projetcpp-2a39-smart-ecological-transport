#ifndef CONGE_H
#define CONGE_H
#include<QString>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>
#include<QDate>
#include <QStandardItemModel>
#include <QStringRef>
class conge
{
public:
    conge();
    conge(int,QDate,QDate,QString);
    int getid_c();
    QDate getdate_debut();
     QDate getdate_retour();
    QString getetat();
    void setid_c(int);
    void setdate_debut(QDate);
    void setdate_retour(QDate);
    void seteta(QString);
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
       QStandardItemModel  * affiche();
    bool refuser(int);
private:
 int id_c;
 QDate date_debut, date_retour;
 QString etat;
};

#endif // CONGE_H
