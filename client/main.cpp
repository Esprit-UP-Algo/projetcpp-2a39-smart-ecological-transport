#include "mainwindow.h"
#include<QDebug>
#include<QMessageBox>
#include <QApplication>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if (test)
    {


    w.show();
    QMessageBox::information(nullptr,QObject::tr("database is open"),
    QObject::tr("connection successful.\n"
                "click canel to exit."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connectionfailed.\n"
                                          "click cancel to exit."),QMessageBox::Cancel);
    return a.exec();

}
