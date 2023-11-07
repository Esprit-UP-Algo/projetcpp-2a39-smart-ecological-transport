#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include<QMessageBox>
#include<QDebug>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("Unable to estabilish a database connection.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}