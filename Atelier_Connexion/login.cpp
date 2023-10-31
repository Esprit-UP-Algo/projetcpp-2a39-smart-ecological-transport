#include "login.h"
#include"login.ui"
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlQuery>
#include <QTableWidget>
#include<QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QDate>
    login::login(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
    {
        ui->setupUi(this);


    }

   login::~login()
    {
        delete ui;
    }

