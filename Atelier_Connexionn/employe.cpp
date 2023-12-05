#include "employe.h"

Employe::Employe(int id, int salaire,  QDate datedebut, QString nom, QString prenom, QString poste)
{
    this->id = id;
    this->salaire = salaire;
    this->datedebut = datedebut;
    this->nom = nom;
    this->prenom = prenom;
    this->poste = poste;

}

    bool Employe::ajouter()
    {
        QString id_string = QString::number(id);
        QString salaire_string = QString::number(salaire);
        QSqlQuery query;
            query.prepare("INSERT INTO EMPLOYE (ID,  NOM, PRENOM,SALAIRE, DATEDEBUT, POSTE) "
                          "VALUES (:ID, :NOM, :PRENOM, :SALAIRE, :DATEDEBUT, :POSTE)");
            query.bindValue(":ID", id_string);
            query.bindValue(":NOM", nom);
            query.bindValue(":PRENOM", prenom);
            query.bindValue(":SALAIRE", salaire_string);
            query.bindValue(":DATEDEBUT", datedebut);
            query.bindValue(":POSTE", poste);
            return query.exec();

    }
    bool Employe::supprimer(int id)
    {
        QSqlQuery query;
        QString id_string = QString::number(id);
        query.prepare("DELETE FROM EMPLOYE WHERE ID=:ID");
        query.bindValue(":ID",id_string);
        return query.exec();
    }

    QSqlQueryModel * Employe::afficher()
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from employe");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("SALAIRE"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEDEBUT"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("POSTE"));
        return model;
    }
    bool Employe::modifier()
    {
        QString id_string = QString::number(id);
        QString salaire_string = QString::number(salaire);
        QSqlQuery query;
            query.prepare("UPDATE EMPLOYE SET ID= :ID, NOM= :NOM, PRENOM= :PRENOM, SALAIRE= :SALAIRE, DATEDEBUT= :DATEDEBUT, POSTE= :POSTE "
                          "WHERE ID = '"+id_string+"' ");
            query.bindValue(":ID", id_string);
            query.bindValue(":NOM", nom);
            query.bindValue(":PRENOM", prenom);
            query.bindValue(":SALAIRE", salaire_string);
            query.bindValue(":DATEDEBUT", datedebut);
            query.bindValue(":POSTE", poste);
            return query.exec();
    }

    QSqlQueryModel * Employe::recherche(QString ar)
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * from Employe where ID like '%"+ar+"%' or PRENOM like '%"+ar+"%' or NOM like '%"+ar+"%' or SALAIRE like '%"+ar+"%' or DATEDEBUT like '%"+ar+"%' or POSTE like '%"+ar+"%' ");
        return model;
    }
