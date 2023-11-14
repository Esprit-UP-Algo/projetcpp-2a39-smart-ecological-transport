#ifndef SPRIME_H
#define SPRIME_H
#include<QString>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>
#include<QDate>
#include"employe.h"

class sprime
{
public:
    sprime();
    sprime(int,QString,QString);
    int getid_p();
    bool ajout();
    float calcule_prime(float a, QString salaire);
    bool update_prime(int,float);
    QSqlQueryModel * afficher();



private:
    int id_p;
    QString salaire;
    QString prime;
};


#endif // SPRIME_H
