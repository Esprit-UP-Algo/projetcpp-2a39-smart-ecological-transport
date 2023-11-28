#ifndef VHICULE_H
#define VHICULE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Vhicule
{

public:
    Vhicule();
    Vhicule(QString,QString,QString,QString,QString);
    Vhicule(QString,QString,QString,QString,QString,QString);

    /*//Getters
    QString getimmatricule(){return immatricule;}
    QString getimarque(){return marque;}
    QString getmodele(){return modele;}
    QString getpuissance(){return puissance;}
    QString gettype_de_recharge(){return type_de_recharge;}
    QString getreference(){return reference;}

    //Setters
    void setimmatricule(QString i){immatricule=i;}
    void setmarque(QString ma){marque=ma;}
    void setmodele(QString mo){modele=mo;}
    void setpuissance(QString p){puissance=p;}
    void settype_de_recharge(QString t){type_de_recharge=t;}
    void setreference(QString r){reference=r;}
    */
    //Getters
    QString getimmatricule();
    QString getimarque();
    QString getmodele();
    QString getpuissance();
    QString gettype_de_recharge();
    QString getreference();

    //Setters
    void setimmatricule(QString);
    void setmarque(QString );
    void setmodele(QString );
    void setpuissance(QString );
    void settype_de_recharge(QString );
    void setreference(QString );
    //Fonctionalités de base relatives à l'entité véhicule
    bool ajouter();
    QSqlQueryModel *  afiicher();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel *  afiicherh();
    bool immatriculeExi( QString immatricule);
    QSqlQueryModel* chercher(QString var); // Declaration of the chercher function
    QSqlQueryModel* trier(QString var);

private:
    QString immatricule, marque, modele, puissance, type_de_recharge, reference;

};


#endif // VHICULE_H
