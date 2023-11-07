#include "animal.h"

Animal::Animal(int identifiant,int poids,int age,int date,QString caracteristiques,QString sexe,QString reproduction ,QString race,QString vaccination,QString sante)
{
 this->identifiant=identifiant;
    this->poids= poids;
    this->age=age;
    this->date=date;
    this->caracteristiques=caracteristiques;
    this->sexe=sexe;
    this->reproduction=reproduction;
    this->race=race;
    this->vaccination=vaccination;
    this->sante=sante;

}
bool Animal::ajouter()
{
    QSqlQuery query;

        query.prepare("INSERT INTO Animal (identifiant,poids,age,date,caracteristiques,sexe,reproduction,race,vaccination,sante) "
                      "VALUES (:identifiant,:poids,:age,:date, :caracteristiques,:sexe, :reproduction, :race, :vaccination, :sante)");

        query.bindValue(":identifiant", identifiant);
        query.bindValue(":poids", poids);
        query.bindValue(":age", age);
        query.bindValue(":date", date);
        query.bindValue(":caracteristiques", caracteristiques);
        query.bindValue(":sexe", sexe);
        query.bindValue(":reproduction", reproduction);
        query.bindValue(":race", race);
          query.bindValue(":vaccination", vaccination);
            query.bindValue(":sante", sante);

        return query.exec();
}
 bool Animal::modifier()
{
    QSqlQuery query;

    query.prepare("UPDATE animal set identfiant=:identifiant WHERE poids=:poids,reproduction=:reproduction,sante=:sante,vaccination=:vaccination");
    query.bindValue(":poids", poids);
    query.bindValue(":reproduction", reproduction);
    query.bindValue(":sante", sante);
    query.bindValue(":vaccination", vaccination);

    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        return false;
    }
}
QSqlQueryModel * Animal::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
            model->setQuery("SELECT* FROM animal");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("poids"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("caracteristiques"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("sexe"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("reproduction"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("race"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("sante"));

      return model;
}
bool Animal::supprimer(int identifiant)
{
        QSqlQuery query;

        query.prepare("DELETE FROM animal WHERE identifiant=:identifiant");

        query.bindValue(":identifiant", identifiant);

        return query.exec();
}
bool Animal::rechercher(int identifiant)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM animal WHERE identifiant=:identifiant");
    query.bindValue(":idnetifiant", identifiant);

    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        return false;
    }
}

