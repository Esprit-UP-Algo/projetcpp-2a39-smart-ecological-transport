#ifndef HISTORIQUES_H
#define HISTORIQUES_H

#include<QString>
#include<QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>


class Historiques
{
    QString Reference;
    QString Point;
    QString Type;
    QString Temp;
    QString Phone;

public:
    Historiques();
    Historiques(QString , QString , QString , QString,QString );

    void savePoint();
    QString loadPoint();
    void saveUpdatePoint(QString , QString , QString , QString,QString);
    void saveDeletePoint();
};

#endif // HISTORIQUES_H
