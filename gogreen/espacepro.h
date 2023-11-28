#ifndef ESPACEPRO_H
#define ESPACEPRO_H


#include <QMessageBox>
#include <QMainWindow>
#include <QSqlQuery>
#include <QTableWidget>
#include<QTableView>
#include <QWidget>
#include <QPushButton>
#include<QHBoxLayout>
#include"ui_espacepro.h"
namespace Ui {
class espacepro;
}

class espacepro : public QWidget
{
    Q_OBJECT

public:
    espacepro(QWidget *parent = nullptr);
    ~espacepro();

private slots:
void on_pushButton_4_clicked();
void on_pushButton_clicked();
void returnToHomepage();

private:

     Ui::espacepro *ui;
   // Button to navigate to another widget
    // Add any other UI elements or private members needed for the logged-in interface
};


#endif // ESPACEPRO_H
