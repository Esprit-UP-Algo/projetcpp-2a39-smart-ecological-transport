#include "station.h"
#include <QtDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QObject>

station::station (QString ref,QString point,QString type_charg,QString temps,QString phone)
{
    this->ref=ref;
    this->point=point;
    this->type_charg=type_charg;
    this->temps=temps;
     this->phone=phone;

}


bool station::ajouter()
{
    QSqlQuery query;
        query.prepare("INSERT INTO station (référance,pointderecharge,type_charg,temps,phone) VALUES (:ref , :point, :type_charg , :temps , :phone)");
        query.bindValue(":ref", ref);
        query.bindValue(":point", point);
        query.bindValue(":type_charg", type_charg);
        query.bindValue(":temps", temps);
          query.bindValue(":phone", phone);

        return query.exec();
}

QSqlQueryModel * station ::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM station");
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("référance"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("pointderecharge"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("type_charg"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("temps"));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr("phone"));


        return model;
}
bool station::supprimer(QString ref)
{
    QSqlQuery query;
        query.prepare("DELETE FROM station WHERE RÉFÉRANCE = :ref");
        query.bindValue(":ref", ref);

       return query.exec();
}

bool station::modifier(QString ref){

    QSqlQuery query;


          query.prepare("UPDATE station  SET  pointderecharge=:point, type_charg=:type , temps=:temps , phone=:phone where RÉFÉRANCE='"+ref+"' ");



                query.bindValue(":point", point);
                query.bindValue(":type", type_charg);
                query.bindValue(":temps", temps);
                query.bindValue(":phone", phone);


            return query.exec();

}


QSqlQuery station::afficher(QString ref)
{
    QSqlQuery query;
        query.prepare("select * from station where RÉFÉRANCE=:ref ");
        query.bindValue(":ref",ref);

        query.exec();
        return query;

}



QSqlQueryModel * station::trierStation(QString test)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if(test == "par défaut"){
        model->setQuery("SELECT * from station");
    }
    else if(test =="par référance")
    {
        model->setQuery("SELECT * from station order by référance asc ");
    }
    else if(test =="par pointderecharge")
    {
        model->setQuery("SELECT * from station order by pointderecharge desc ");
    }
    else if(test =="par type chargeur")
    {
        model->setQuery("SELECT * from station order by type_charg asc ");
    }
    else if(test =="par temps de recharge")
    {
        model->setQuery("SELECT * from station order by temps asc ");
    }else if(test =="par phone")
    {
        model->setQuery("SELECT * from station order by phone asc ");
    }
    return model;
}
/*============================*/
    QSqlQueryModel * station::rechercherStation(QString chaine)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from station where ( référance LIKE'%"+chaine+"%' OR pointderecharge LIKE'%"+chaine+"%' OR type_charg LIKE'%"+chaine+"%' OR temps LIKE'%"+chaine+"%' OR phone LIKE'%"+chaine+"%') ");


    return model ;
}
