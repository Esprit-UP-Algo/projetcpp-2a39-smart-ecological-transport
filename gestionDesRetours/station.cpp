#include "station.h"
#include <QDebug>
#include <QSqlError>
station::station  (QString ref,QString point,QString type_charg,QString temps)
{
    this->ref=ref;
    this->point=point;
    this->type_charg=type_charg;
    this->temps=temps;

}
bool station::ajouter()
{
    QSqlQuery query;
        query.prepare("INSERT INTO stations (ref,point,type_charg,temps) VALUES (:ref, :point, :type_charg, :temps)");
        query.bindValue(":reference", ref);
        query.bindValue(":point de recharge", point);
        query.bindValue(":type de chargeur", type_charg);
        query.bindValue(":temps", temps);

        if (query.exec()) {
            qDebug() << "station ajouté avec succès!";
            return true;
        } else {
            qDebug() << "Erreur lors de l'ajout du station:" << query.lastError().text();
            return false;
        }
}

QSqlQueryModel * station ::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM stations");

        if (model->lastError().isValid()) {
            qDebug() << "Erreur lors de la récupération des stations:" << model->lastError().text();
        }

        return model;
}
bool station::supprimer(QString ref)
{
    QSqlQuery query;
        query.prepare("DELETE FROM station WHERE ref = :ref");
        query.bindValue(":ref", ref);

        if (query.exec()) {
            qDebug() << "station supprimé avec succès!";
            return true;
        } else {
            qDebug() << "Erreur lors de la suppression du station:" << query.lastError().text();
            return false;
        }
}
