#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class client
{
    QString nom,prenom,mail,permis;
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
    bool modifier();
    bool chercherParId(int);
};

#endif // CLIENT_H
