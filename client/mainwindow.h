#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<connection.h>
#include <QLineEdit>
#include <QPushButton>
#include <QDate>
#include <QSqlQuery>
#include <QTableWidget>
#include<QTableView>
#include <QMessageBox>
#include "client.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_17_clicked();
    void on_pushButton_50_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_58_clicked();
    void on_pushButton_6_clicked();
     void on_pushButton_supprimer_clicked();
      void on_pushButton_modifier_clicked();

private:
    Ui::MainWindow *ui;
    client ctmp;
};
#endif // MAINWINDOW_H
