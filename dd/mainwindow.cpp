#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_ajouter_clicked()
{
    QString caracteristiques= ui->lineEdit_9->text();
     QString sexe= ui->lineEdit_6->text();
      QString reproduction= ui->lineEdit_7->text();
       QString race= ui->lineEdit_3->text();
        QString vaccination= ui->lineEdit_8->text();
         QString sante= ui->lineEdit_4->text();
         int identifiant= ui->lineEdit_5->text().toInt();
         int poids= ui->lineEdit_2->text().toInt();
         int age= ui->lineEdit->text().toInt();
         int date= ui->dateEdit->text().toInt();

    Animal E (identifiant, poids, age, date, caracteristiques, sexe,reproduction,race,vaccination,sante);
    bool test = E.ajouter();
    if (test)
    {
        ui->tableView->setModel(Etmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n" "Click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué\n" "Click cancel to exit."), QMessageBox::Cancel);
    }
}
/*
void MainWindow::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_16->text().toInt();
    bool test = Etmp.supprimer(id);
    if (test)
    {
        ui->tableView->setModel(Etmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n" "Click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectuée\n" "Click cancel to exit."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_modifier_clicked() //MODIFIER
{
    int ID = ui->lineEdit_11->text().toInt();
    int salaire = ui->lineEdit_14->text().toInt();
    QString nom = ui->lineEdit_12->text();
    QString prenom = ui->lineEdit_13->text();
    QString poste = ui->lineEdit_15->text();
    QDate datedebut = ui->dateEdit_3->date();
   Employe E(ID, salaire, datedebut, nom, prenom, poste);
     bool test = E.modifier();
    if (test)
    {
        ui->tableView->setModel(Etmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Modification effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                 QObject::tr("Modification non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pushButton_modifier_clicked()
{

}*/
