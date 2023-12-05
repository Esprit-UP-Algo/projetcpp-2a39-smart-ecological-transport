#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehicule.h"
#include "vhicule.h"
#include <QMessageBox>
#include "connection.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_19_clicked()
{
    Vehicule *VehiculeWindow= new Vehicule;
    VehiculeWindow->show();
}
