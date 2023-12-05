#ifndef OTHERWIDGET_H
#define OTHERWIDGET_H
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlQuery>
#include <QTableWidget>
#include<QTableView>
#include<QValidator>
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
#include"employe.h"
#include"conge.h"

namespace Ui {
class employes;
}
class employes : public QWidget
{
    Q_OBJECT

public:
    employes(QWidget *parent = nullptr);
    ~employes();


private slots:

    void enrollFingerprintButtonClicked();
       void verifyFingerprintButtonClicked();
       void handleEnrollmentResult(bool success);
       void handleVerificationResult(bool success);

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

void on_pushButton_9_clicked();
void returnToHomepage();


void on_tri_clicked();
/*void checkLogin(const QString &username, const QString &password);*/

void on_aff_clicked();

void on_lineEdit_6_textChanged(const QString &arg1);

private:

Ui::employes *ui;
    // Add any UI elements or private members needed for this widget
Employe Etmp;
QTableView *T;
int salaire;
conge c;
};

#endif // OTHERWIDGET_H
