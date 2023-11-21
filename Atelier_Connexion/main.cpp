#include "mainwindow.h"
#include "Login.h" // Assuming you have a LoginWindow class
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

    bool test = c.createconnect();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
            QObject::tr("Connection successful.\n"
            "Click OK to proceed."), QMessageBox::Ok);

        // Create a login window
            Login loginwindow;
        if (loginwindow.exec() == QDialog::Accepted) { // If login is successful
            MainWindow w;
            w.show(); // Show the MainWindow
            return a.exec();
        } else {
            return 0; // Exit if login is canceled or failed
        }
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
            QObject::tr("Connection failed.\n"
            "Click Cancel to exit."), QMessageBox::Cancel);
        return 0; // Exit if database connection failed
    }
}





