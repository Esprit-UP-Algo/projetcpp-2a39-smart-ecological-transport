#include "login.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Connection c;

    bool test = c.createconnect();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
            QObject::tr("Connection successful.\n"
                        "Click OK to proceed."), QMessageBox::Ok);

    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
            QObject::tr("Connection failed.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        return 0; // Exit if database connection failed
    }



    Login *otherWidget = new Login;
        otherWidget->show();
         return a.exec();
}
