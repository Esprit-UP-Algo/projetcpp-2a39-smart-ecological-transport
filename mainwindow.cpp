<<<<<<< HEAD
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include "connection.h"
#include <QObject>
#include <QMessageBox>
#include <QIntValidator>
#include "smtp.h"
#include <QFileDialog>
#include <QDebug>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include <QtCharts/QBarSet>
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(r.affichier());
    ui->num ->setValidator( new QIntValidator(0,99999999, this));//8 chiffre only
    ui->cin->setValidator( new QIntValidator(0,99999999, this));//8chifre only
    ui->tableView->setModel(r.affichier());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{


    QString nom=ui->nom ->text();
    QString prenom=ui->prenom ->text();
    int num=ui->num ->text().toInt();
    QString datedebut=ui->date  ->text();
    int cin=ui->cin  ->text().toInt();
    QString email=ui->email  ->text();
    QString datefin=ui->datef ->text();
    QString durer=ui->lineEdit ->text();

    reservation r(nom,prenom,num,datedebut,cin,email,datefin,durer);
    bool test=r.ajouter();
    if (test)
    {
        ui->tableView->setModel(r.affichier());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        //mise a jour du tableau appres ajout
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("ajout failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }


void MainWindow::on_supprimer_clicked()
{
    int num=ui->num_2->text().toInt();
    bool test=r.supprimer(num);
    if (test)
    {
         ui->tableView->setModel(r.affichier());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supprission effectuer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

       //mise a jour du tableau appres supprision
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suprission failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_modifier_clicked()
{
    bool  test;
    QString nom= ui->nom_2->text();
    QString prenom = ui->prenom_2->text();
    int num = ui->num_4->text().toInt();
    QString datedebut = ui->date_2->text();
    int cin = ui->cin_2->text().toInt();
    QString email = ui->email_2->text();
    QString datefin = ui->datef->text();
    QString durer = ui->lineEdit->text();

     test =  r.modifier (nom , prenom , num , datedebut , cin, email,datefin,durer);

          if (test)
          {

              ui->tableView->setModel(r.affichier());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void MainWindow::on_recherchecin_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
                   QSqlQuery   *query= new QSqlQuery();
           if(ui->recherchecin->text()==arg1)
                   {
               query->prepare("SELECT * FROM RESERVATION WHERE CIN LIKE'"+arg1+"%'");//
       query->exec();
           model->setQuery(*query);
       ui->tableView->setModel(model);
}
}

void MainWindow::on_Trie_name_clicked()
{
    ui->tableView->setModel(r.sortname());

}

void MainWindow::on_pb_pdf_clicked()
{   QString s;
    s=ui->PDF->text();
    r.exportpdf(s);
}

/*void MainWindow::on_sendMail_clicked()
{QString mail=ui->from->text();
QString password=ui->paswd->text();
QString recpt=ui->to->text();
QString objet=ui->subject->text();
QString description=ui->msg->toPlainText();
//Smtp *smtp= new Smtp(mail,password,"smtp.gmail.com");
//smtp->sendMail(mail,recpt ,objet,description);
}*/



void MainWindow::on_export_button_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                                  tr("Excel Files (*.xls)"));
                  if (fileName.isEmpty())
                      return;

                  ExportExcel obj(fileName, "Taches", ui->tableView);

                  //colums to export
                  obj.addField(0, "NOM", "char(20)");
                  obj.addField(1, "PRENOM", "char(20)");
                  obj.addField(2, "NUM", "char(20)");
                  obj.addField(3, "DATEDEBUT", "char(20)");
                  obj.addField(4, "CIN", "char(20)");
                  obj.addField(5, "EMAIL", "char(20)");
                  obj.addField(6, "DATEFIN", "char(20)");
                  obj.addField(7, "DURER", "char(20)");






                  int retVal = obj.export2Excel();
                  if( retVal > 0)
                  {
                      QMessageBox::information(this, tr("Done"),
                                               tr("Toutes les informations ont été enregistrée"));
                  }

}



=======
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include "connection.h"
#include <QObject>
#include <QMessageBox>
#include <QIntValidator>
#include"mailing.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(r.affichier());
    ui->num ->setValidator( new QIntValidator(0,99999999, this));//8 chiffre only
    ui->cin->setValidator( new QIntValidator(0,99999999, this));//8chifre only
    ui->tableView->setModel(r.affichier());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{


    QString nom=ui->nom ->text();
    QString prenom=ui->prenom ->text();
    int num=ui->num ->text().toInt();
    QString datedebut=ui->date  ->text();
    int cin=ui->cin  ->text().toInt();
    QString email=ui->email  ->text();

    reservation r(nom,prenom,num,datedebut,cin,email);
    bool test=r.ajouter();
    if (test)
    {
        ui->tableView->setModel(r.affichier());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        //mise a jour du tableau appres ajout
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("ajout failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }


void MainWindow::on_supprimer_clicked()
{
    int num=ui->num_2->text().toInt();
    bool test=r.supprimer(num);
    if (test)
    {
         ui->tableView->setModel(r.affichier());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supprission effectuer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

       //mise a jour du tableau appres supprision
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suprission failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_modifier_clicked()
{
    bool  test;
    QString nom= ui->nom_2->text();
    QString prenom = ui->prenom_2->text();
    int num = ui->num_4->text().toInt();
    QString datedebut = ui->date_2->text();
    int cin = ui->cin_2->text().toInt();
    QString email = ui->email_2->text();

     test =  r.modifier (nom , prenom , num , datedebut , cin, email);

          if (test)
          {

              ui->tableView->setModel(r.affichier());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void MainWindow::on_recherchecin_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
                   QSqlQuery   *query= new QSqlQuery();
           if(ui->recherchecin->text()==arg1)
                   {
               query->prepare("SELECT * FROM RESERVATION WHERE CIN LIKE'"+arg1+"%'");//
       query->exec();
           model->setQuery(*query);
       ui->tableView->setModel(model);
}
}

void MainWindow::on_Trie_name_clicked()
{
    ui->tableView->setModel(r.sortname());

}

void MainWindow::on_pb_pdf_clicked()
{   QString s;
    s=ui->PDF->text();
    r.exportpdf(s);
}

void MainWindow::on_send_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("STMP is open"),
                          QObject::tr("Message envoyé"),
                          QMessageBox::Ok
                          );
    Mailing* mailing = new Mailing("mannai.dhia.1@gmail.com", "mannai123456987dhiamannai123456", "smtp.gmail.com", 465);
    QString adresse = ui->mail->text();
    QString Subject = ui->mail_2->text();
    QString Message = ui->mail_3->text();
    mailing->sendMail("mannai.dhia.1@gmail.com", adresse, Subject ,Message);
}

void MainWindow::on_export_button_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                                  tr("Excel Files (*.xls)"));
                  if (fileName.isEmpty())
                      return;

                  ExportExcel obj(fileName, "Taches", ui->tableView);

                  //colums to export
                  obj.addField(0, "NOM", "char(20)");
                  obj.addField(1, "PRENOM", "char(20)");
                  obj.addField(2, "NUM", "char(20)");
                  obj.addField(3, "DATEDEBUT", "char(20)");
                  obj.addField(4, "CIN", "char(20)");
                  obj.addField(5, "EMAIL", "char(20)");





                  int retVal = obj.export2Excel();
                  if( retVal > 0)
                  {
                      QMessageBox::information(this, tr("Done"),
                                               tr("Toutes les informations ont été enregistrée"));
                  }

}
>>>>>>> d8e75cc0f0e315cdd085192fe209afe4a45db9f0
