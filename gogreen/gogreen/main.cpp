#include "gogreen.h"

#include <QApplication>

#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

    bool test = c.createconnect();



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
    gogreen w;
    w.show();
    return a.exec();
}
