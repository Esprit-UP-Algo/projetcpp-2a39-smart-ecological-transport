#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPainter>
#include <QPdfWriter>
#include<QBuffer>
#include <QImage>
#include<QFileDialog>
#include <QDebug>
#include <QStyledItemDelegate>


class client
{
    QString nom,prenom,mail,permis,imagePath;
    int id;

public:
    client(){}
    client(QString,QString,QString,QString,int);
    /*-----------------------------------*/
    QString getNom(){return nom;}
     QString getPrenom(){return prenom;}
      QString getMail(){return mail;}
     QString getPermis(){return permis;}
    int getId(){return id;}

    /*_________________*/
    void setNom(QString n){nom=n;}
     void setPrenom(QString p){prenom=p;}
      void setMail(QString m){mail=m;}
    void setPermis(QString per){permis=per;}
    void setId(int id){this->id=id;}
    /*__________________________*/
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    bool chercherParId(int);
    QSqlQueryModel* rechercheID(int id );
    QSqlQueryModel* sortid_up();
    QSqlQueryModel* sortid_down();
    void exportpdf(QString s);

};

#endif // CLIENT_H
