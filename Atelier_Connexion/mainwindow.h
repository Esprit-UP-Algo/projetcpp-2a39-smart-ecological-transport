#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlQuery>
#include <QTableWidget>
#include<QTableView>
#include<QValidator>
#include "employe.h"
#include "conge.h"
#include "arduino.h"
#include"LoginWidget.h"
#include"pdf.h"
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
#include <QtSql>
#include <QDebug>
#include <QVector>
#include <algorithm>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QChartView *chartView ;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

void readSerialData();

    void on_pushButton_ajouter_clicked();
     void on_pushButton_supprimer_clicked();
      void on_pushButton_modifier_clicked();
      void on_pushButton_2_clicked();

      void on_confirmer_clicked();
      void on_supp_clicked();
      void on_pushButton_4_clicked();
      void on_pushButton_3_clicked();
      void on_pushButton_22_clicked();




/*void checkLogin(const QString &username, const QString &password);*/

void on_aff_clicked();

void on_lineEdit_6_textChanged(const QString &arg1);

void stat();

void on_tri_currentIndexChanged(const QString &arg1);
void update_label();
private:
    Ui::MainWindow *ui;
 QSerialPort *serial;
 Arduino A;
  QByteArray data;
    Employe Etmp;
    QTableView *T;
    int salaire;
    conge c;





};

#endif // MAINWINDOW_H
