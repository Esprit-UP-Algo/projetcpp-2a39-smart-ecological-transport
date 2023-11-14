#include "reservation.h"
#include "connection.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QObject>



reservation::reservation()
{
     nom=""; prenom="";num=0 ;datedebut=""; cin=0 ;email="";

}
reservation::reservation(QString nom ,QString prenom,int num,QString datedebut , int cin,QString email)
{

    this->nom=nom;
    this->prenom=prenom;
    this->num=num;
    this->datedebut=datedebut;
    this->cin=cin;
    this->email=email;
}


QString reservation ::getnom()
{return nom;}
QString reservation ::getprenom()
{return prenom;}
int reservation :: getnum()
{return num;}
QString reservation ::getdatedebut()
{return datedebut;}
int reservation ::getcin()
{return cin;}
QString reservation ::getemail()
{return email;}

///////////////////////////////////////////////


void reservation ::setnom(QString nom)
{this->nom=nom;}
void reservation ::setprenom(QString prenom)
{this->prenom=prenom;}
void reservation ::setnum(int num)
{this->num=num;}
void reservation ::setdatedebut(QString datedebut)
{this->datedebut=datedebut;}
void reservation ::setcin(int cin)
{this->cin=cin;}
void reservation ::setemail(QString email)
{this->email=email;}


bool reservation::ajouter()
{
    QSqlQuery query;
    QString num_string=QString::number(num);
    QString cin_string=QString::number(cin);

          query.prepare("insert into RESERVATION (NOM ,PRENOM,NUM,DATEDEBUT,CIN,EMAIL) "
                        "VALUES ( :nom,:prenom,:num,:datedebut,:cin,:email )");



          query.bindValue(0,nom);
          query.bindValue(1,prenom);
          query.bindValue(2,num);
          query.bindValue(3,datedebut);
          query.bindValue(4,cin);
          query.bindValue(5,email);


          return query.exec();
}
QSqlQueryModel * reservation::affichier()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * from RESERVATION");



    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NUM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEDEBUT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMAIL"));


    return model;
}
bool reservation::supprimer(int num)
{
    QSqlQuery query;
    query.prepare("DELETE FROM reservation where NUM = :num");
    query.bindValue(":num",num);
    return query.exec();
}

bool reservation::modifier ( QString nom, QString prenom,int num, QString datedebut ,int cin, QString email) {
    QSqlQuery query;
    qDebug() << query.lastQuery();

    query.prepare("UPDATE reservation SET  NOM=:nom, PRENOM=:prenom,NUM=:num, DATEDEBUT=:datedebut, CIN=:cin, EMAIL=:email WHERE NUM=:num");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":num", num);
    query.bindValue(":datedebut", datedebut);
    query.bindValue(":cin", cin);
     query.bindValue(":email", email);

    return query.exec();
}

QSqlQueryModel* reservation::recherchecin(int cin )
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString cin1=QString::number(cin);
    model->setQuery("select * from RESERVATION where CIN like '"+cin1+"%' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEDEBUT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
        return model;

}

QSqlQueryModel* reservation::sortname()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from RESERVATION ORDER BY NOM");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedebut"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

        return model;
}

void reservation::exportpdf(QString s) {
    QString s1 = "C:/Users/nacef/Downloads/" + s + ".pdf";
    QPdfWriter pdf(s1);

    QPainter painter(&pdf);

    int i = 4000;
    QImage logoImage("C:/Users/nacef/Downloads/4_lg.jpg");
    if (!logoImage.isNull()) {
        painter.drawImage(QRect(100, 100, 2000, 500), logoImage); }

    int squareWidth = 4000;
    int squareX = (pdf.width() - squareWidth) / 2;

    painter.setFont(QFont("Century Gothic", 50, QFont::Bold));
    painter.setPen(Qt::blue);

    int titleX = squareX + (squareWidth - painter.fontMetrics().width("LISTE DES RESERVATIONS")) / 2;

    painter.drawText(titleX, 1200, "LISTE DES RESERVATIONS");
    painter.setFont(QFont("Century Gothic", 9));
    painter.setPen(Qt::black);
    painter.drawText(500, 3300, "NOM");
    painter.drawText(1500, 3300, "PRENOM");
    painter.drawText(3000, 3300, "NUM");
    painter.drawText(4200, 3300, "DATEDEBUT");
    painter.drawText(5700, 3300, "CIN");
    painter.drawText(7000, 3300, "EMAIL");

    QSqlQuery query;
    query.prepare("SELECT * FROM RESERVATION");
    query.exec();
    while (query.next()) {
        painter.drawText(500, i, query.value(0).toString());
        painter.drawText(1500, i, query.value(1).toString());
        painter.drawText(3000, i, query.value(2).toString());
        painter.drawText(4200, i, query.value(3).toString());
        painter.drawText(5700, i, query.value(4).toString());
        painter.drawText(7000, i, query.value(5).toString());





        i = i + 500;
    }
}


