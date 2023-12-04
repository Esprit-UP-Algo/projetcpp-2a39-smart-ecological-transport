#include "clients.h"
#include "ui_clients.h"
#include"espacepro.h"
#include<QIntValidator>

#include<QMessageBox>
#include<QSqlQueryModel>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include <fstream>
#include<QPushButton>
#include "client.h"
#include "qrcode.h"
#include<QBuffer>
#include <QImage>
#include<QFileDialog>
#include <QDebug>
#include <QStyledItemDelegate>
#include "arduinoc.h"
#include<QTimer>

clients::clients(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::clients)
{
    ui->setupUi(this);

    ui->lineEdit_13->setValidator(new QIntValidator(0, 999999, this));
    ui->tableView_2->setModel(ctmp.afficher());
    ui->tableView_1->setModel(ctmp.afficher());
    ui->tableView->setModel(ctmp.afficher());
    QString buttonStyle = "QPushButton {""border-radius: 25px;" "color: white;""background-color: white;"
      "background-image: url(C:/Users/MICRO-PC/Downloads/alg.png);""background-repeat: no-repeat;"
               "background-position: center;" "}"  "QPushButton:hover {"
                                 "background-color: white;"
                                   "color: green;"
                              "font-family: Georgia;"
                                 "font-size: 12px;"

                                 "}" "QPushButton:pressed {"
                                 "color: #45a049;";  // Change text color when pressed

            ui->pushButton_qr->setStyleSheet(buttonStyle);
    QPushButton *returnButton = new QPushButton("Retour", this);
               returnButton->setStyleSheet(" color: white; background-color: green;");
               returnButton->setFont(QFont("Georgia", 12));

               // Set the button's position and size
               returnButton->setGeometry(30, 180, 100, 30); // Adjust position and size as needed

               // Connect the button's clicked signal to the appropriate slot or function
               connect(returnButton, &QPushButton::clicked, this, &clients::returnToHomepage);
    int ret=ard.connect_arduinoc();
            // lancer la connexion à arduino
    {
     switch(ret){

     case(0):qDebug()<< "arduino is available and connected to : "<<
    ard.getarduino_port_name();

         break;


     case(1):qDebug() << "arduino is available but not connected to :"
    <<ard.getarduino_port_name();

        break;

     case(-1):qDebug() << "arduino is not available";

     }

     QObject::connect(ard.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}
}

clients::~clients()
{
    delete ui;
}
void clients::on_pushButton_17_clicked()
{
    QApplication::quit();

}
void clients::on_pushButton_10_clicked()
{
    QApplication::quit();

}void clients::on_pushButton_50_clicked()
{
    QApplication::quit();

}void clients::on_pushButton_26_clicked()
{
    QApplication::quit();

}void clients::on_pushButton_58_clicked()
{
    QApplication::quit();

}


void clients::on_pushButton_6_clicked()
{

    int id=ui->lineEdit_4->text().toInt();
   // int contact=ui->le_contact->text().toInt();
    QString nom=ui->lineEdit->text();
    QString prenom=ui->lineEdit_2->text();
    QString mail=ui->lineEdit_3->text();
    QString permis=ui->lineEdit_5->text();

    client ctmp (nom,prenom,mail,permis,id);

    bool test=ctmp.ajouter();
    if(test)
        {
             ui->tableView_2->setModel(ctmp.afficher());
             ui->tableView_1->setModel(ctmp.afficher());
             ui->tableView->setModel(ctmp.afficher());

            QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                              QObject::tr(" client ajouter.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ajouter un client"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
        }


}

void clients::on_pushButton_modifier_clicked() //MODIFIER
{
    client c;
    c.setId(ui->lineEdit_13->text().toInt());
    c.setNom(ui->lineEdit_10->text());
    c.setPrenom(ui->lineEdit_11->text());
    c.setMail(ui->lineEdit_12->text());
    c.setPermis(ui->lineEdit_14->text());

    bool test=c.modifier(c.getId());
    if(test)
        {
        QByteArray image;

        ui->tableView_2->setModel(ctmp.afficher());
        ui->tableView_1->setModel(ctmp.afficher());
        ui->tableView->setModel(ctmp.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifer un client"),
                              QObject::tr("client updated.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("modifier  un client "),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void clients::on_pushButton_supprimer_clicked()
{
    client c; c.setId(ui->lineEdit_15->text().toInt());
    bool test=c.supprimer(c.getId());
    if(test)
        {
        ui->tableView_2->setModel(ctmp.afficher());
        ui->tableView_1->setModel(ctmp.afficher());
        ui->tableView->setModel(ctmp.afficher());
            QMessageBox::information(nullptr, QObject::tr("supprimer un client"),
                              QObject::tr("client supprimer.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("supprimer un client"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
        }


}

void clients::on_rechercheID_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
                   QSqlQuery   *query= new QSqlQuery();
           if(ui->rechercheID->text()==arg1)
                   {
               query->prepare("SELECT * FROM CLIENT WHERE ID LIKE'"+arg1+"%'");//
       query->exec();
           model->setQuery(*query);
       ui->tableView_2->setModel(model);
}
}
void clients::on_Trie_botto_clicked()
{
    ui->tableView_2->setModel(ctmp.sortid_up());
}
void clients::on_Trie_botton_clicked()
{
    ui->tableView_2->setModel(ctmp.sortid_down());
}
void clients::on_pushButton_pdf_2_clicked()
{   QString s;
    s=ui->lineEdit_6->text();
    ctmp.exportpdf(s);
}


void clients::on_pushButton_qr_clicked() {
    QSerialPort serial;
    serial.setPortName("COM6");  // Set the appropriate COM port
    serial.setBaudRate(QSerialPort::Baud9600);  // Set the baud rate

    if (serial.open(QIODevice::ReadWrite)) {
        qDebug() << "Serial port opened successfully";

        QByteArray requestData("start");
        qint64 bytesWritten = serial.write(requestData); // Send data to Arduino

        if (bytesWritten == -1) {
            qDebug() << "Failed to write to serial port";
        } else if (bytesWritten != requestData.size()) {
            qDebug() << "Failed to write all data to serial port";
        } else {
            qDebug() << "Data sent successfully to Arduino";
        }

        serial.close();
    } else {
        qDebug() << "Error opening serial port!";
    }
}
void clients::returnToHomepage() {
    // Implement the logic to return to the homepage here
    // For example:
    espacepro *homepageWidget = new espacepro;
    homepageWidget->show();

    // Hide the current LoggedInWidget
    this->hide();
}

