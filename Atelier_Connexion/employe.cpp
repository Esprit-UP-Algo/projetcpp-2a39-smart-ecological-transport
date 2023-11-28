#include "employe.h"

Employe::Employe(QString id, int salaire,  QDate datedebut, QString nom, QString prenom, QString poste)
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

        QString salaire_string = QString::number(salaire);
        QSqlQuery query;
            query.prepare("INSERT INTO EMPLOYE (ID,  NOM, PRENOM,SALAIRE, DATEDEBUT, POSTE) "
                          "VALUES (:ID, :NOM, :PRENOM, :SALAIRE, :DATEDEBUT, :POSTE)");
            query.bindValue(":ID", id);
            query.bindValue(":NOM", nom);
            query.bindValue(":PRENOM", prenom);
            query.bindValue(":SALAIRE", salaire_string);
            query.bindValue(":DATEDEBUT", datedebut);
            query.bindValue(":POSTE", poste);
            return query.exec();

    }
    bool Employe::supprimer(QString id)
    {
        QSqlQuery query;

        query.prepare("DELETE FROM EMPLOYE WHERE ID=:ID");
        query.bindValue(":ID",id);
        return query.exec();
    }

    QSqlQueryModel* Employe::afficher() {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT ID,NOM,PRENOM,SALAIRE,DATEDEBUT,POSTE  FROM employe");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALAIRE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEDEBUT"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("POSTE"));
        return model;
    }

    bool Employe::modifier()
    {

        QString salaire_string = QString::number(salaire);
        QSqlQuery query;
            query.prepare("UPDATE EMPLOYE SET ID= :ID, NOM= :NOM, PRENOM= :PRENOM, SALAIRE= :SALAIRE, DATEDEBUT= :DATEDEBUT, POSTE= :POSTE "
                          "WHERE ID = '"+id+"' ");
            query.bindValue(":ID", id);
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

    QSqlQueryModel * Employe::trier(QString test)
    {
        QSqlQueryModel * model=new QSqlQueryModel();
        if(test == "par défaut"){
            model->setQuery("SELECT * from EMPLOYE");
        }
        else if(test =="par NOM")
        {
            model->setQuery("SELECT * from EMPLOYE order by NOM asc ");
        }
        else if(test =="par PRENOM")
        {
            model->setQuery("SELECT * from EMPLOYE order by PRENOM desc ");
        }
        else if(test =="par SALAIRE")
        {
            model->setQuery("SELECT * from EMPLOYE order by SALAIRE asc ");
        }
        else if(test =="par POSTE")
        {
            model->setQuery("SELECT * from EMPLOYE order by POSTE asc ");
        }else if(test =="par ID")
        {
            model->setQuery("SELECT * from EMPLOYE order by ID asc ");
        }
        return model;
    }
    QSqlQueryModel * Employe::testCode(QString code)
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select NOM,PRENOM from agent where pass ='"+code+"'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("PASS"));

        return model;
    }


