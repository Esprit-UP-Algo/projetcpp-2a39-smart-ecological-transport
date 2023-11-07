#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(ctmp.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_17_clicked()
{
    QApplication::quit();

}void MainWindow::on_pushButton_50_clicked()
{
    QApplication::quit();

}void MainWindow::on_pushButton_26_clicked()
{
    QApplication::quit();

}void MainWindow::on_pushButton_58_clicked()
{
    QApplication::quit();

}


void MainWindow::on_pushButton_6_clicked()
{
    QString nom= ui->lineEdit->text();
     QString prenom= ui->lineEdit_2->text();
      QString mail= ui->lineEdit_3->text();
       QString permis= ui->lineEdit_5->text();
         int id= ui->lineEdit_4->text().toInt();

    client  c (nom,prenom,mail,permis, id);
    bool test = c.ajouter();
    if (test)
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué\n" "Click cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        ui->tableView_2->setModel(ctmp.afficher());

         QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("Ajout effectué\n" "Click cancel to exit."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_modifier_clicked() //MODIFIER
{

    int id = ui->lineEdit_4->text().toInt();
    QString nom = ui->lineEdit->text();
    QString prenom = ui->lineEdit_2->text();
    QString mail = ui->lineEdit_3->text();
    QString permis = ui->lineEdit_5->text();
    client c(nom,prenom,mail,permis,id);
   bool test = c.modifier();
    if (test)
    {
        ui->tableView_2->setModel(ctmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Modification effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                 QObject::tr("Modification non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_15->text().toInt();
    bool test = ctmp.supprimer(id);
    if (test)
    {
        ui->tableView_2->setModel(ctmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n" "Click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectuée\n" "Click cancel to exit."), QMessageBox::Cancel);
    }
}