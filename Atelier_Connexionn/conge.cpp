#include "conge.h"

conge::conge()
{
}
conge::conge(int id_c,QDate date_debut,QDate date_retour,QString etat)
{
    this->id_c=id_c;
    this->date_debut=date_debut;
    this->date_retour=date_retour;
    this->etat=etat;
}
int conge::getid_c()
{return id_c ;}

QDate conge::getdate_debut()
{return date_debut;}

QDate conge::getdate_retour()
{return date_retour;}

QString conge::getetat()
{return etat;}

void conge::setid_c(int id_c)
{this->id_c=id_c;}

void conge::setdate_debut(QDate date_debut)
{this->date_debut=date_debut;}

void conge::setdate_retour(QDate  date_retour)
{this->date_retour=date_retour;}

void conge::seteta(QString etat)
{this->etat=etat;}

bool conge::ajouter()
{
    QString date1 = date_debut.toString("dd-MM-yyyy");
    QString date2 = date_retour.toString("dd-MM-yyyy");

    bool test = false;
    int y1 = date1.mid(6, 4).toInt();
    int y2 = date2.mid(6, 4).toInt();
    int m1 = date1.mid(3, 2).toInt();
    int m2 = date2.mid(3, 2).toInt();
    int d1 = date1.mid(0, 2).toInt();
    int d2 = date2.mid(0, 2).toInt();

    if (y1 < y2)
    {
        test = true;
    }
    else if (y1 == y2)
    {
        if (m1 < m2)
        {
            test = true;
        }
        else if (m1 == m2)
        {
            if (d1 <= d2)
            {
                test = true;
            }
            else
            {
                test = false;
            }
        }
        else
        {
            test = false;
        }
    }
    else
    {
        test = false;
    }

    if (test)
    {
        QSqlQuery query;
        QString etat = "non confirmee";
        query.prepare("INSERT INTO CONGE (ID_C, DATE_DEBUT, DATE_RETOUR, ETAT) "
                      "VALUES (:ID_C, :DATE_DEBUT, :DATE_RETOUR, :ETAT)");
        query.bindValue(":ID_C", id_c);
        query.bindValue(":DATE_DEBUT", date_debut);
        query.bindValue(":DATE_RETOUR", date_retour);
        query.bindValue(":ETAT", etat);
        return query.exec();
    }
    else
    {
        return false;
    }
}

bool conge::supprimer(int id_c)
{
    QSqlQuery query;
    query.prepare("Delete from conge where id_c=:id_c");
    query.bindValue(":id_c",id_c);
    return query.exec();
}
bool conge::modifier(int id_c)
{
    QSqlQuery query;
    QString etat="confirmee";
       query.prepare("update conge set  etat=:etat where id_c=:id_c" );
       query.bindValue(":id_c",id_c);
       query.bindValue(":etat",etat);
       return query.exec();
}
QSqlQueryModel * conge::affiche()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * from CONGE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_C"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_DEBUT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_RETOUR"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));

    return model;
}
bool conge::refuser(int id_c)
{
    QSqlQuery query;
    QString etat="refuser";
       query.prepare("UPDATE CONGE SET  ETAT=:ETAT WHERE ID_C=:ID_C" );
       query.bindValue(":ID_c",id_c);
       query.bindValue(":ETAT",etat);
       return query.exec();
}
