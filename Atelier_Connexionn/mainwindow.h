#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlQuery>
#include <QTableWidget>
#include<QTableView>
#include "employe.h"
#include "conge.h"
#include"stats.h"
#include"login.h"
#include <QLineEdit>
#include <QPushButton>
#include <QDate>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include<QComboBox>
#include<QStackedWidget>
#include<QPrinter>
#include <QPrintDialog>
#include<QPainter>
#include <QSortFilterProxyModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loginButton();

private slots:

void on_tri_Clicked();
    void on_pushButton_ajouter_clicked();
     void on_pushButton_supprimer_clicked();
      void on_pushButton_modifier_clicked();
      void on_pushButton_2_clicked();
      void on_pushButton_clicked();
      void on_confirmer_clicked();
      void on_supp_clicked();
      void on_pushButton_4_clicked();
      void on_pushButton_3_clicked();
      void on_pushButton_22_clicked();
     void on_LoginButton_Clicked();
     void Validation();
void showMainWindow();
void on_pushButton_7_clicked();




void on_tableView_3_activated();

void on_lineEdit_6_textChanged(const QString &arg1);

void on_pushButton_clicked(bool checked);

void on_pushButton_windowIconTextChanged(const QString &iconText);

void on_tableView_3_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
Login *login;
    Employe Etmp;
    int salaire;
    conge c;
     stats *s;

};

#endif // MAINWINDOW_H
