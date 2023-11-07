#include "client.h"
#include <QDebug>
#include <QSqlError>
client::client(QString nom,QString prenom,QString mail,QString permis,int id)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
    this->permis=permis;

}
bool client::ajouter()
{
    QSqlQuery query;
        query.prepare("INSERT INTO clients (nom, prenom, mail, permis, id) VALUES (:nom, :prenom, :mail, :permis, :id)");
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":mail", mail);
        query.bindValue(":permis", permis);
        query.bindValue(":id", id);

        if (query.exec()) {
            qDebug() << "Client ajouté avec succès!";
            return true;
        } else {
            qDebug() << "Erreur lors de l'ajout du client:" << query.lastError().text();
            return false;
        }
}
/*QSqlQueryModel * client::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM clients");

        if (model->lastError().isValid()) {
            qDebug() << "Erreur lors de la récupération des clients:" << model->lastError().text();
        }

        return model;
}*/
bool client::supprimer(int id)
{
    QSqlQuery query;
        query.prepare("DELETE FROM clients WHERE id = :id");
        query.bindValue(":id", id);

        if (query.exec()) {
            qDebug() << "Client supprimé avec succès!";
            return true;
        } else {
            qDebug() << "Erreur lors de la suppression du client:" << query.lastError().text();
            return false;
        }
}
QSqlQueryModel * client::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
            model->setQuery("SELECT* FROM client");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("id"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("permis"));


      return model;
}
bool client::modifier()
{
   QSqlQuery query;


   query.bindValue(":nom", nom);
   query.bindValue(":prenom", prenom);
   query.bindValue(":mail", mail);
   query.bindValue(":id", id);
   query.bindValue(":permis", permis);
   if (query.exec() && query.next())
   {
       return true;
   }
   else
   {
       return false;
   }
}
bool client::chercherParId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM clients WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // Mettez à jour les attributs de l'objet client avec les données de la base de données
        this->nom = query.value(0).toString();
        this->prenom = query.value(1).toString();
        this->mail = query.value(2).toString();
        this->permis = query.value(3).toString();
        this->id = query.value(4).toInt();
        return true;
    } else {
        qDebug() << "Erreur lors de la recherche du client:" << query.lastError().text();
        return false;
    }
}
/*int idRecherche = 123; // Remplacez 123 par l'ID que vous recherchez
client clientTrouve;
 if (clientTrouve.chercherParId(idRecherche))
{
    // Le client a été trouvé, faites quelque chose avec le client
    qDebug() << "Client trouvé - Nom : " << clientTrouve.getNom() << ", Prénom : " << clientTrouve.getPrenom();
}  else {
    // Le client n'a pas été trouvé
    qDebug() << "Client non trouvé.";
}*/

