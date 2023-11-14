#include "historique.h"
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardPaths>

Historiques::Historiques()
{

}


Historiques::Historiques(QString ref, QString point, QString type, QString temp,QString phone){
    this->Reference = ref;
    this->Point = point;
    this->Type = type;
    this->Temp = temp;
    this->Phone = phone;

}


void Historiques::savePoint(){
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    filePath = QDir(filePath).filePath("gestionDesRetours/gestionDesRetours/historique.txt");

    QFile file (filePath);
    if (!file.open(QIODevice::WriteOnly|  QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out.setCodec("UTF-8");
    QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
    out << "\n reference: "+ Reference + ", piont de recharge: " +Point+ ", type de chargeur: " +Type+ ", temp de recharge: " +Temp+ ", phone number: " +Phone << "\n" "un nouveau piont de charge a ete ajouter le " +sDate << "\n";
}

void Historiques::saveUpdatePoint(QString ref, QString point, QString type, QString temp,QString phone){
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    filePath = QDir(filePath).filePath("gestionDesRetours/gestionDesRetours/historique.txt");

    QFile file (filePath);
    if (!file.open(QIODevice::WriteOnly|  QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out.setCodec("UTF-8");
    QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
    out << "\n""*****************************************Update********************************";
    out << "\n Referance: "+Reference + ", piont de charge: " +Point+ ", type de chargeur: " +Type+ ", temp de recharge: " + Temp+ ", phone number: " + Phone ;
    out << "\n Referance: "+ref + ", piont de charge: " +point+ ", type de chargeur: " +type+ ", temp de recharge: " +temp+ ", phone number: " + phone << "\n" "Cet point de charge a été modifié le " +sDate << "\n";
    out <<"*****************************************Update********************************" "\n";

}


void Historiques::saveDeletePoint(){
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    filePath = QDir(filePath).filePath("gestionDesRetours/gestionDesRetours/historique.txt");

    QFile file (filePath);
    if (!file.open(QIODevice::WriteOnly|  QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out.setCodec("UTF-8");
    QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
    out << "\n reference: "+Reference + ", Point de charge: " +Point+ ", Type de chargeur: " +Type+ ", temp de recharge: " +Temp+ ", phone number: " +Phone << "\n" "Cet point de recharge a été supprimé le " +sDate << "\n";

}


