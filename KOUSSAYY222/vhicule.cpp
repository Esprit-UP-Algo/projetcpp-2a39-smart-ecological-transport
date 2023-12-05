#include "vehicule.h"
#include "vhicule.h"
#include <QMessageBox>
#include "connection.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>

Vhicule::Vhicule()
{
    immatricule = "";
    marque = "";
    modele = "";
    puissance = "";
    type_de_recharge = "";
    reference = "";

}

Vhicule::Vhicule(QString immatricule, QString marque, QString modele, QString puissance, QString type_de_recharge ,  QString reference)
{
    this->immatricule = immatricule;
    this->marque = marque;
    this->modele = modele;
    this->puissance = puissance;
    this->type_de_recharge = type_de_recharge;
    this->reference = reference;
}

Vhicule::Vhicule(QString marque, QString modele, QString puissance, QString type_de_recharge ,  QString reference)
{

    this->marque = marque;
    this->modele = modele;
    this->puissance = puissance;
    this->type_de_recharge = type_de_recharge;
    this->reference = reference;
}


QString Vhicule::getimmatricule() { return immatricule; }
QString Vhicule::getimarque() { return marque; }
QString Vhicule::getmodele() { return modele; }
QString Vhicule::getpuissance() { return puissance; }
QString Vhicule::gettype_de_recharge() { return type_de_recharge; }
QString Vhicule::getreference() { return reference; }

// Setters
void Vhicule::setimmatricule(QString immatricule) { this->immatricule = immatricule; }
void Vhicule::setmarque(QString marque) { this->marque = marque; }
void Vhicule::setmodele(QString modele) { this->modele = modele; }
void Vhicule::setpuissance(QString puissance) { this->puissance = puissance; }
void Vhicule::settype_de_recharge(QString type_de_recharge) { this->type_de_recharge = type_de_recharge; }
void Vhicule::setreference(QString reference) { this->reference = reference; }

bool Vhicule::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO VEHICULE (IMMATRICULE, MARQUE, MODELE, PUISSANCE, TYPE_CHARGE, REFERENCE) "
                  "VALUES (:IMMATRICULE, :MARQUE, :MODELE, :PUISSANCE, :TYPE_CHARGE, :REFERENCE)");
    query.bindValue(":IMMATRICULE", immatricule);
    query.bindValue(":MARQUE", marque);
    query.bindValue(":MODELE", modele);
    query.bindValue(":PUISSANCE", puissance);
    query.bindValue(":TYPE_CHARGE", type_de_recharge);
    query.bindValue(":REFERENCE", reference);


    if (query.exec()) {
        QSqlQuery query;

                       historique h("me","ajouter une matrcuile de id : "+immatricule,QDateTime::currentDateTime());
                query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
                query.bindValue(":USERNAME", h.getuser());
                query.bindValue(":ACTION", h.getaction());
                query.bindValue(":DATEH", h.getdateh());
                query.exec();

        return true;
    } else {
        qDebug() << "Erreur SQL : " << query.lastError().text();
        return false;
    }

}





QSqlQueryModel *Vhicule::afiicher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM VEHICULE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("immatricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("puissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type_de_recharge"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("reference"));

    return model;
}
QSqlQueryModel *Vhicule::afiicherh()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM HISTORIQUE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("immatricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("puissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type_de_recharge"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("reference"));

    return model;
}
bool Vhicule::supprimer(QString matricule)
{
    QSqlQuery query;
    query.prepare("DELETE FROM VEHICULE WHERE immatricule = :IMMATRICULE");
    query.bindValue(":IMMATRICULE", matricule);

    if (query.exec()) {
        historique h("me","supprimer une matrcuile de id : "+immatricule,QDateTime::currentDateTime());
 query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
 query.bindValue(":USERNAME", h.getuser());
 query.bindValue(":ACTION", h.getaction());
 query.bindValue(":DATEH", h.getdateh());
 query.exec();
        return true;
    } else {
        return false;
    }
}

bool Vhicule::modifier(QString immatricule)
{
    QSqlQuery query;
    query.prepare("UPDATE VEHICULE"" SET MARQUE = :MARQUE, MODELE = :MODELE, PUISSANCE = :PUISSANCE, TYPE_CHARGE = :TYPE_CHARGE, REFERENCE = :REFERENCE WHERE IMMATRICULE = '"+immatricule+"' ");
    query.bindValue(":IMMATRICULE", immatricule); // Use the provided matricule parameter
    query.bindValue(":MARQUE", marque);
    query.bindValue(":MODELE", modele);
    query.bindValue(":PUISSANCE", puissance);
    query.bindValue(":TYPE_CHARGE", type_de_recharge);
    query.bindValue(":REFERENCE", reference);
    QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("MODIFICATION effectué:\n"
                                             "ID_LIV: %1\n"
                                             "Date_LIV: %2\n"
                                             "Produit_Livr&eacute;: %3\n"
                                             "Statut_LIV: %4\n"
                                              "Statut_LIV: %5\n"
                                              "Statut_LIV: %6\n"
                                             "Cliquez sur Annuler pour quitter.")
                                 .arg(immatricule)
                                 .arg(marque)  // Vous pouvez ajuster le format de date
                                 .arg(modele)
                                 .arg(puissance)
                             .arg(type_de_recharge)
                             .arg(reference),
                                 QMessageBox::Cancel);

    if (query.exec()) {
        historique h("me","modifier une matrcuile de id : "+immatricule,QDateTime::currentDateTime());
 query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
 query.bindValue(":USERNAME", h.getuser());
 query.bindValue(":ACTION", h.getaction());
 query.bindValue(":DATEH", h.getdateh());
 query.exec();
        return true;
    } else {
        qDebug() << "Erreur SQL : " << query.lastError().text();
        return false;
    }
}

//QSqlQueryModel* Vhicule::chercher(QString var)
//{
//    QSqlQueryModel* model = new QSqlQueryModel();
//    model->setQuery("SELECT * FROM VEHICULE WHERE IMMATRICULE = "+var);

//    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IMMATRICULE"));
//    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
//    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODELE"));
//    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PUISSANCE"));
//    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_CHARGE"));
//    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REFERENCE"));
//    return model;
//}

QSqlQueryModel* Vhicule::chercher(QString var)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM VEHICULE WHERE IMMATRICULE = :var");
    query.bindValue(":var", var);

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IMMATRICULE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODELE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PUISSANCE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_CHARGE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("REFERENCE"));
    } else {
        qDebug() << "Query error:" << query.lastError().text();
    }

    return model;
}



QSqlQueryModel* Vhicule::trier(QString var)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM VEHICULE ORDER BY MARQUE " + var);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IMMATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODELE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PUISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_CHARGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REFERENCE"));
    return model;
}


//bool immatriculeExi(QString immatricule) {
//    QSqlQuery query;
//    query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE immatricule = :immatricule");
//    query.bindValue(":immatricule", immatricule);

//    if (query.exec() && query.next()) {
//        int count = query.value(0).toInt();
//        return count > 0;
//    }

//    // Handle the case where the query fails or an error occurs
//    qDebug() << "Failed to check immatricule existence:" << query.lastError().text();
//    return false;
//}





