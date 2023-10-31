#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
    QString IDText = ui->lineEdit->text();
    QString salaireText = ui->lineEdit_4->text();
    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();
    QString poste = ui->lineEdit_5->text();
    QDate datedebut = ui->dateEdit->date();

    // Check if any required fields are empty
        if (IDText.isEmpty() || salaireText.isEmpty() || nom.isEmpty() || prenom.isEmpty() || poste.isEmpty()) {
            QMessageBox::critical(nullptr, QObject::tr("Error"),
                                  QObject::tr("Please fill in all the required fields."), QMessageBox::Ok);
            return;
        }

        // Validate the format of numeric input fields
        bool ok;
        int ID = IDText.toInt(&ok);
        if (!ok) {
            QMessageBox::critical(nullptr, QObject::tr("Error"),
                                  QObject::tr("Invalid value for ID."), QMessageBox::Ok);
            return;
        }

        int salaire = salaireText.toInt(&ok);
        if (!ok) {
            QMessageBox::critical(nullptr, QObject::tr("Error"),
                                  QObject::tr("Invalid value for salaire."), QMessageBox::Ok);
            return;
        }

        Employe E(ID, salaire, datedebut, nom, prenom, poste);
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


void MainWindow::on_pushButton_supprimer_clicked()
{
    QString idText = ui->lineEdit_16->text();

        // Check if the ID field is empty
        if (idText.isEmpty()) {
            QMessageBox::critical(nullptr, QObject::tr("Error"),
                                  QObject::tr("Please enter an ID."), QMessageBox::Ok);
            return;
        }

        // Validate the format of the ID field
        bool ok;
        int id = idText.toInt(&ok);
        if (!ok) {
            QMessageBox::critical(nullptr, QObject::tr("Error"),
                                  QObject::tr("Invalid value for ID."), QMessageBox::Ok);
            return;
        }

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


void MainWindow::on_pushButton_modifier_clicked()
{
    QString IDText = ui->lineEdit_11->text();
    QString salaireText = ui->lineEdit_14->text();
    QString nom = ui->lineEdit_12->text();
    QString prenom = ui->lineEdit_13->text();
    QString poste = ui->lineEdit_15->text();
    QDate datedebut = ui->dateEdit_3->date();

    // Check if any required fields are empty
    if (IDText.isEmpty() || salaireText.isEmpty() || nom.isEmpty() || prenom.isEmpty() || poste.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Please fill in all the required fields."), QMessageBox::Ok);
        return;
    }

    // Validate the format of numeric input fields
    bool ok;
    int ID = IDText.toInt(&ok);
    if (!ok) {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Invalid value for ID."), QMessageBox::Ok);
        return;
    }

    /*Check if the ID already exists (excluding the current record being modified)
    if (Etmp.IDExists(ID) && !Etmp.isCurrentRecord(ID)) {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("ID already exists."), QMessageBox::Ok);
        return;
    }*/

    int salaire = salaireText.toInt(&ok);
    if (!ok) {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Invalid value for salaire."), QMessageBox::Ok);
        return;
    }

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
