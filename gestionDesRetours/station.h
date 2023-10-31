#ifndef STATION_H
#define STATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class station
{
    QString ref,point,type_charg,temps;
public:
    station(){}
    station(QString,QString,QString,QString);
    /*-----------------------------------*/
    QString getRef(){return ref;}
    QString getPoint(){return point;}
    QString getType_charg(){return type_charg;}
    QString getPTemps(){return temps;}
    /*_________________*/
    void setRef(QString r){ref=r;}
    void setPoint(QString p){point=p;}
    void setType_charg(QString t){type_charg=t;}
    void setTemps(QString tmp){temps=tmp;}

    /*__________________________*/
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
};
#endif // STATION_H
