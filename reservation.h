<<<<<<< HEAD
#ifndef RESERVATION_H
#define RESERVATION_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QString>
#include <QPdfWriter>
#include <QPainter>
#include <QSystemTrayIcon>
#include<QMessageBox>


class reservation
{


public:
    reservation();
    reservation(QString,QString,int,QString,int,QString,QString,QString);

    QString getnom();
    QString getprenom();
    int getnum();
    QString getdatedebut();
    int getcin();
    QString getemail();
    QString getdatefin();
    QString getdurer();





    void setnom(QString);
    void setprenom(QString);
    void setnum(int);
    void setdatedebut(QString);
    void setcin(int);
    void setemail(QString);
    void setdatefin(QString);
    void setdurer(QString);
    bool ajouter();
    QSqlQueryModel * affichier();
    bool supprimer(int num);
    bool modifier(QString nom, QString prenom,int num,QString datedebut,int cin,QString email,QString datefin,QString durer);
    QSqlQueryModel* recherchecin(int cin );
    QSqlQueryModel* sortname();
    void exportpdf(QString s);
     bool retour(QString datedebut,QString datefin,QString durer);


private:
    int num,cin;
    QString nom,prenom,datedebut,email,datefin,durer;

};

#endif // RESERVATION_H
=======
#ifndef RESERVATION_H
#define RESERVATION_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QString>
#include <QPdfWriter>
#include <QPainter>
#include <QSystemTrayIcon>
#include<QMessageBox>


class reservation
{


public:
    reservation();
    reservation(QString,QString,int,QString,int,QString);

    QString getnom();
    QString getprenom();
    int getnum();
    QString getdatedebut();
    int getcin();
    QString getemail();





    void setnom(QString);
    void setprenom(QString);
    void setnum(int);
    void setdatedebut(QString);
    void setcin(int);
    void setemail(QString);
    bool ajouter();
    QSqlQueryModel * affichier();
    bool supprimer(int num);
    bool modifier(QString nom, QString prenom,int num,QString datedebut,int cin,QString email);
    QSqlQueryModel* recherchecin(int cin );
    QSqlQueryModel* sortname();
    void exportpdf(QString s);


private:
    int num,cin;
    QString nom,prenom,datedebut,email;

};

#endif // RESERVATION_H
>>>>>>> d8e75cc0f0e315cdd085192fe209afe4a45db9f0
