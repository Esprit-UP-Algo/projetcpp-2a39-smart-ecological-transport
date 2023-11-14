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
