#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlQuery>
#include <QTableWidget>
#include<QTableView>
#include "employe.h"
#include <QLineEdit>
#include <QPushButton>
#include <QDate>
#include<QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_ajouter_clicked();
     void on_pushButton_supprimer_clicked();
      void on_pushButton_modifier_clicked();



private:
    Ui::MainWindow *ui;
    Employe Etmp;
    int salaire;

};

#endif // MAINWINDOW_H
