#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QDate>
#include<QPieSeries>
#include<QPieSlice>
#include<QtCharts>

class Employe
{
public:
    Employe(){};
    Employe(QString, int, QDate, QString, QString, QString);


   QString getID(){return id;}
   int getsalaire();
     QDate getDatedebut();
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getposte();

    void setID(QString);
    void setsalaire(int);

    void setdatedebut(QDate);
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setposte(QString);
    bool ajouter();
    bool supprimer(QString);
   QSqlQueryModel * testCode(QString code);
QSqlQueryModel * trier(QString );

    QSqlQueryModel * afficher();
    bool modifier();
    QSqlQueryModel *recherche (QString);
private:
    int  salaire;
    QDate datedebut;
    QString id,nom, prenom,poste;


};

#endif // EMPLOYE_H
