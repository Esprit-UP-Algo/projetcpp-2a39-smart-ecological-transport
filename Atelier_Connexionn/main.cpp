#include "mainwindow.h"
#include"login.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDesktopWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

        bool test=c.createconnect();

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("connection successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        MainWindow w;
        Login loginWidget;
        loginWidget.resize(400, 300);
            QRect screenGeometry = QApplication::desktop()->screenGeometry();
            int x = (screenGeometry.width() - loginWidget.width()) / 2;
            int y = (screenGeometry.height() - loginWidget.height()) / 2;
            loginWidget.move(x, y);
            loginWidget.show();


            QObject::connect(&loginWidget, &Login::loginSuccessful, [&]() {
                loginWidget.hide();
                w.show();  // Show the existing instance of MainWindow
            });


          return a.exec();


}






