#include "client.h"
#include <QDebug>
#include <QSqlError>
#include <QFile>


client::client(QString nom,QString prenom,QString mail,QString permis,int id)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
    this->permis=permis;

}
bool client::ajouter ()
{

    QSqlQuery query;


    QString id_string=QString::number(id);
         query.prepare("INSERT INTO client (ID, NOM, PRENOM , mail,permis) "
                       "VALUES (:id, :nom, :prenom, :mail, :permis)");
         query.bindValue(":id", id_string);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":mail", mail);
         query.bindValue(":permis", permis);


        return query.exec();


}
bool client:: supprimer(int)
{

    QSqlQuery query;

         query.prepare("DELETE FROM client WHERE id=:id");
         query.bindValue(":id", id);
        return query.exec();

      }
bool client::modifier(int)
{

    QSqlQuery query;
    QString id_string=QString::number(id);

             query.prepare("UPDATE client SET id=:id, mail=:mail,nom=:nom,prenom=:prenom,permis=:permis WHERE id=:id");
             query.bindValue(":id", id_string);
             query.bindValue(":mail", mail);
             query.bindValue(":nom",nom);
             query.bindValue(":prenom",prenom);
             query.bindValue(":permis", permis);


            return query.exec();

}
QSqlQueryModel * client::afficher(){

    QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("SELECT * FROM client");
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("mail"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("permis"));

    return model;

}
QSqlQueryModel* client::rechercheID(int id )
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString id1=QString::number(id);
    model->setQuery("select * from CLIENT WHERE ID like '"+id1+"%' ");
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("permis"));



        return model;

}
QSqlQueryModel* client::sortid_up()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY ID ASC ");
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("permis"));

        return model;
}

QSqlQueryModel* client::sortid_down()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from CLIENT ORDER BY ID DESC ");
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("permis"));

        return model;
}
void client::exportpdf(QString s) {
    QString s1 = "C:/Users/molo1/Downloads/" + s + ".pdf";
    QPdfWriter pdf(s1);

    QPainter painter(&pdf);

    int i = 4000;
    QImage logoImage("C:/Users/molo1/Downloads/4_lg.jpg");
    if (!logoImage.isNull()) {
        painter.drawImage(QRect(100, 100, 2000, 500), logoImage); }

    int squareWidth = 4000;
    int squareX = (pdf.width() - squareWidth) / 2;

    painter.setFont(QFont("Century Gothic", 50, QFont::Bold));
    painter.setPen(Qt::blue);

    int titleX = squareX + (squareWidth - painter.fontMetrics().width("LISTE DES CLIENT")) / 2;

    painter.drawText(titleX, 1200, "LISTE DES CLIENT");
    painter.setFont(QFont("Century Gothic", 9));
    painter.setPen(Qt::black);
    painter.drawText(500, 3300, "nom");
    painter.drawText(1500, 3300, "prenom");
    painter.drawText(3000, 3300, "mail");
    painter.drawText(3700, 3300, "id");
    painter.drawText(4100, 3300, "permis");

    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENT");
    query.exec();
    while (query.next()) {
        painter.drawText(500, i, query.value(0).toString());
        painter.drawText(1500, i, query.value(1).toString());
        painter.drawText(3000, i, query.value(2).toString());
        painter.drawText(3700, i, query.value(3).toString());
        painter.drawText(4100, i, query.value(4).toString());



        i = i + 500;
    }
}
