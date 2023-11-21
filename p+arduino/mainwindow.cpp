#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "station.h"
#include <QTabWidget>
#include <QMessageBox>
#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QTableView>
//#include <QIntValidator>
#include <QSqlQueryModel>
#include "QPdfWriter"
#include "QPainter"
#include "QDate"
#include "QFileDialog"
#include "QSettings"
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardPaths>
#include "sms.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_phone->setValidator(new QIntValidator(0,99999999,this));
    ui->tab_stations->setModel(s.afficher());

    ui->comboBox_trie->addItem("par référance");
    ui->comboBox_trie->addItem("par pointderecharge");
    ui->comboBox_trie->addItem("par type chargeur");
    ui->comboBox_trie->addItem("par temps de recharge");
    ui->comboBox_trie->addItem("par phone");

    int ret=A.connect_arduino(); // lancer la connexion à arduino
                switch(ret){
                case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                    break;
                case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                   break;
                case(-1):qDebug() << "arduino is not available";
                }
                 QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(input()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::input(){
    data=A.read_from_arduino();
    ref= data;
    qDebug()<<ref.left(ref.length()-2);
    ui->rfid->setText(ref.left(ref.length()-2));
}
void MainWindow::on_ajouter_clicked()
{
    QString ref=ui->lineEdit_ref->text();
    QString point=ui->lineEdit_point->text();
    QString type_charg=ui->lineEdit_type_chargeur->text();
    QString temps=ui->lineEdit_temps->text();
    QString phone=ui->lineEdit_phone->text();
    station s(ref,point,type_charg,temps,phone);
    bool stut=false;
    qDebug()<<"far7"<<ui->rfid->text();

    if (ui->rfid->text() != "") {
        QSqlQuery query;
        if (query.prepare("select type from accesss where rfid=:ref ")) {
            query.bindValue(":ref", ui->rfid->text());
            if (query.exec()) {
                while (query.next()) {
                    stut = true;
                    qDebug() << "rue";
                }

                if (stut) {
                    bool test = s.ajouter();
                    if (test) {
                        ui->tab_stations->setModel(s.afficher());
                        QMessageBox::information(nullptr, QObject::tr("OK"),
                                                 QObject::tr("ajout successful.\n"
                                                             "click canel to exit."),
                                                 QMessageBox::Cancel);
                    }
                }
            } else {
                qDebug() << "Query execution failed:" << query.lastError().text();
            }
        } else {
            qDebug() << "Query preparation failed:" << query.lastError().text();
        }
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("RFID is empty."),
                              QMessageBox::Cancel);
    }

ui->rfid->setText("");
    ui->lineEdit_ref->clear();
    ui->lineEdit_point->clear();
    ui->lineEdit_type_chargeur->clear();
     ui->lineEdit_temps->clear();
      ui->lineEdit_phone->clear();
}


void MainWindow::on_comboBox_trie_currentIndexChanged(const QString &arg1)
{

     ui->tab_stations->setModel(s.trierStation(arg1));
}

void MainWindow::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    if (arg1!="")
    {
        ui->tab_stations->setModel(s.rechercherStation(arg1));

   }else
        ui->tab_stations->setModel(s.trierStation(ui->comboBox_trie->currentText()));


}

void MainWindow::on_generate_pdf_clicked()
{
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    filePath = QDir(filePath).filePath("gestionDesRetours/gestionDesRetours/pdf/listePoints.pdf");
    QPdfWriter pdf(filePath);

       QPainter painter(&pdf);
       int i = 4100;
   /*const QImage image("C:/Users/pc/Desktop/1.png");
                   const QPoint imageCoordinates(155,0);
                   int width1 = 1600;
                   int height1 = 1600;
                   QImage img=image.scaled(width1,height1);
                   painter.drawImage(imageCoordinates, img );*/


              QColor dateColor(0x4a5bcf);
              painter.setPen(dateColor);

              painter.setFont(QFont("Montserrat SemiBold", 11));
              QDate cd = QDate::currentDate();
              painter.drawText(8400,250,cd.toString("Tunis"));
              painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

              QColor titleColor(0x341763);
              painter.setPen(titleColor);
              painter.setFont(QFont("Montserrat SemiBold", 25));

              painter.drawText(3000,2700,"Liste des stations");

              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              //painter.drawRect(100,100,9400,2500);
              painter.drawRect(100,3300,9400,500);

              painter.setFont(QFont("Montserrat SemiBold", 10));

              painter.drawText(500,3600,"référance");
              painter.drawText(2000,3600,"pointderecharge");
              painter.drawText(3700,3600,"type chargeur");
              painter.drawText(5500,3600,"temps de recharge");
              painter.drawText(7500,3600,"Phone Number");
              painter.setFont(QFont("Montserrat", 10));
              painter.drawRect(100,3300,9400,9000);

              QSqlQuery query;
              query.prepare("select * from station");
              query.exec();
              int y=4300;
              while (query.next())
              {
                  painter.drawLine(100,y,9490,y);
                  y+=500;
                  painter.drawText(500,i,query.value(0).toString());
                  painter.drawText(2000,i,query.value(1).toString());
                  painter.drawText(3700,i,query.value(2).toString());
                  painter.drawText(5500,i,query.value(3).toString());
                  painter.drawText(7500,i,query.value(4).toString());

                 i = i + 500;
              }
              QMessageBox::information(nullptr,QObject::tr("Pdf created"),
              QObject::tr("File created with seccess.\n"
                          ""),QMessageBox::Ok);

}






void MainWindow::on_tab_stations_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tab_stations->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select * from station where RÉFÉRANCE='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_ref->setText(qry.value(0).toString());
            ui->lineEdit_point->setText(qry.value(1).toString());
            ui->lineEdit_type_chargeur->setText(qry.value(2).toString());
            ui->lineEdit_temps->setText(qry.value(3).toString());
            ui->lineEdit_phone->setText(qry.value(4).toString());
             ui->phone->setText(qry.value(4).toString());


}}
}



void MainWindow::on_deleteBtn_clicked()
{
    int i;
    QModelIndex index=ui->tab_stations->currentIndex();
i=index.row();
QModelIndex in=index.sibling(i,0);

QString val=ui->tab_stations->model()->data(in).toString();
station c("","","","","");
         QSqlQuery stationInfo = c.afficher(val);
         stationInfo.next();

         bool stut=false;
             if (ui->rfid->text()!=""){
                 QSqlQuery query;
                     query.prepare("SELECT type FROM accesss WHERE rfid = :ref AND type = :type ");
                     query.bindValue(":ref",ui->rfid->text());
                     query.bindValue(":type","primary");

                     if(query.exec())
                     {
                         while(query.next())
                         {
                             stut=true;


                 }}
                     if (stut==true){
                 bool test=s.supprimer(val);
             if(test){
                     ui->tab_stations->setModel(s.afficher());
                 QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("ajout successful.\n"
                             "click canel to exit."),QMessageBox::Cancel);
             }}}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("DELETE"),
                              QObject::tr("failed.\n"
                                          "click cancel to exit."),QMessageBox::Cancel);

     }
             ui->rfid->setText("");
}

void MainWindow::on_modifierBtn_clicked()
{
    QString ref=ui->lineEdit_ref->text();
    QString point=ui->lineEdit_point->text();
    QString type=ui->lineEdit_type_chargeur->text();
   QString temps=ui->lineEdit_temps->text();
   QString phone=ui->lineEdit_phone->text();

   station c("","","","","");
            QSqlQuery stationInfo = c.afficher(ref);
            stationInfo.next();

   station s(ref,point,type,temps,phone);
   bool stut=false;
       if (ui->rfid->text()!=""){
           QSqlQuery query;
               query.prepare("select type from accesss where rfid=:ref ");
               query.bindValue(":ref",ui->rfid->text());
               if(query.exec())
               {
                   while(query.next())
                   {
                       stut=true;


           }}
               if (stut==true){
           bool test=s.modifier(ref);
       if(test){
               ui->tab_stations->setModel(s.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),
           QObject::tr("ajout successful.\n"
                       "click canel to exit."),QMessageBox::Cancel);

       }}}else{
     QMessageBox::critical(nullptr, QObject::tr("MODIFIER"),
                           QObject::tr("failed.\n"
                                       "click cancel to exit."),QMessageBox::Cancel);


 }

 ui->lineEdit_ref->clear();
 ui->lineEdit_point->clear();
 ui->lineEdit_type_chargeur->clear();
  ui->lineEdit_temps->clear();
    ui->lineEdit_phone->clear();
    ui->rfid->setText("");
}

void MainWindow::on_send_clicked()
{
    sms s;
     const QString msg = ui->sms->toPlainText();

    const QString recipient_phone_number = "+216"+ ui->phone->text();

   s.sendSMS(recipient_phone_number, msg);
}
