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
    Employe(int, int, QDate, QString, QString, QString);


    int getID(){return id;}
   int getsalaire();
     QDate getDatedebut();
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getposte();

    void setID(int id){this->id=id;}
    void setsalaire(int);

    void setdatedebut(QDate);
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setposte(QString);
    bool ajouter();
    bool supprimer(int);


 QSqlQueryModel* trier_nom();

    QSqlQueryModel * afficher();
    bool modifier();
    QSqlQueryModel *recherche (QString);
private:
    int id, salaire;
    QDate datedebut;
    QString nom, prenom,poste;


};

#endif // EMPLOYE_H
