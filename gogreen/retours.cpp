#include "retours.h"
#include "ui_retours.h"
#include "station.h"
#include"espacepro.h"
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
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSeries>
#include <QPieSlice>
#include <QStandardPaths>
#include "sms.h"
#include <vector>
using namespace std;
retours::retours(QWidget *parent)
              : QWidget(parent)
    , ui(new Ui::retours)
{
    ui->setupUi(this);
    setFixedSize(1000, 500);

    ui->lineEdit_phone->setValidator(new QIntValidator(0,99999999,this));
    ui->tab_stations->setModel(s.afficher());

    ui->comboBox_trie->addItem("par référance");
    ui->comboBox_trie->addItem("par pointderecharge");
    ui->comboBox_trie->addItem("par type chargeur");
    ui->comboBox_trie->addItem("par temps de recharge");
    ui->comboBox_trie->addItem("par phone");
    QPushButton *returnButton = new QPushButton("Retour", this);
               returnButton->setStyleSheet(" color: white; background-color: green;");
               returnButton->setFont(QFont("Georgia", 12));

               // Set the button's position and size
               returnButton->setGeometry(30, 180, 100, 30); // Adjust position and size as needed

               // Connect the button's clicked signal to the appropriate slot or function
               connect(returnButton, &QPushButton::clicked, this, &retours::returnToHomepage);
    stat();

}

retours::~retours()
{
    delete ui;
}
void retours::updateQRImage()
{

//int scale=5;
    int levelIndex = 1;
    int versionIndex = 0;
    bool bExtent = true;
    int maskIndex = -1;
    QString encodeString = "ref station:"+ui->lineEdit_ref->text()+"\n num point :"+ui->lineEdit_point->text()+"\n type_charg :"+ui->lineEdit_type_chargeur->text()+"\n temps :"+ui->lineEdit_temps->text()+"\n phone :"+ui->lineEdit_phone->text();

    successfulEncoding = qrEncode.EncodeData( levelIndex, versionIndex, bExtent, maskIndex, encodeString.toUtf8().data() );
    if ( !successfulEncoding )
    {
        ui->qrcode->clear();
        ui->qrcode->setText( tr("QR Code...") );

        ui->save->setEnabled( successfulEncoding );
        return;
    }

    int qrImageSize = qrEncode.m_nSymbleSize;


    encodeImageSize = qrImageSize + ( QR_MARGIN * 2 );
    QImage encodeImage( encodeImageSize, encodeImageSize, QImage::Format_Mono );
    encodeImage.fill( 1 );


    for ( int i = 0; i < qrImageSize; i++ )
        for ( int j = 0; j < qrImageSize; j++ )
            if ( qrEncode.m_byModuleData[i][j] )
                encodeImage.setPixel( i + QR_MARGIN, j + QR_MARGIN, 0 );

    ui->qrcode->setPixmap( QPixmap::fromImage( encodeImage ) );
ui->qrcode->setScaledContents(true);


    ui->save->setEnabled( successfulEncoding );
}
void retours::on_ajouter_clicked()
{
    QString ref=ui->lineEdit_ref->text();
    QString point=ui->lineEdit_point->text();
    QString type_charg=ui->lineEdit_type_chargeur->text();
    QString temps=ui->lineEdit_temps->text();
    QString phone=ui->lineEdit_phone->text();
    station s(ref,point,type_charg,temps,phone);
    bool test=s.ajouter();
    if(test){
            ui->tab_stations->setModel(s.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
        QObject::tr("ajout successful.\n"
                    "click canel to exit."),QMessageBox::Cancel);
    }else{
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                  QObject::tr("ajout non effectué.\n"
                                              "click cancel to exit."),QMessageBox::Cancel);
    }

    ui->lineEdit_ref->clear();
    ui->lineEdit_point->clear();
    ui->lineEdit_type_chargeur->clear();
     ui->lineEdit_temps->clear();
      ui->lineEdit_phone->clear();
      stat();
}


void retours::on_comboBox_trie_currentIndexChanged(const QString &arg1)
{

     ui->tab_stations->setModel(s.trierStation(arg1));
}

void retours::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    if (arg1!="")
    {
        ui->tab_stations->setModel(s.rechercherStation(arg1));

   }else
        ui->tab_stations->setModel(s.trierStation(ui->comboBox_trie->currentText()));


}

void retours::on_generate_pdf_clicked()
{
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    filePath = QDir(filePath).filePath("gestionDesRetours/pdf/listePoints.pdf");
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




void retours::on_tab_stations_clicked(const QModelIndex &index)
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
     updateQRImage();
}



void retours::on_deleteBtn_clicked()
{
    int i;
    QModelIndex index=ui->tab_stations->currentIndex();
i=index.row();
QModelIndex in=index.sibling(i,0);

QString val=ui->tab_stations->model()->data(in).toString();
station c("","","","","");
         QSqlQuery stationInfo = c.afficher(val);
         stationInfo.next();

    bool test=s.supprimer(val);
    if (test)
    {
        ui->tab_stations->setModel(s.afficher());

        QMessageBox::information(nullptr,QObject::tr("DELETE"),
        QObject::tr(" successful.\n"
                    "click canel to exit."),QMessageBox::Cancel);







    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("DELETE"),
                              QObject::tr("failed.\n"
                                          "click cancel to exit."),QMessageBox::Cancel);

     }
    stat();
}

void retours::on_modifierBtn_clicked()
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
    bool test=s.modifier(ref);
    ui->tab_stations->setModel(s.afficher());
 if(test){
     QMessageBox::information(nullptr,QObject::tr("MODIFIER"),
     QObject::tr(" successful.\n"
                 "click canel to exit."),QMessageBox::Cancel);

}else{
     QMessageBox::critical(nullptr, QObject::tr("MODIFIER"),
                           QObject::tr("failed.\n"
                                       "click cancel to exit."),QMessageBox::Cancel);


 }

 ui->lineEdit_ref->clear();
 ui->lineEdit_point->clear();
 ui->lineEdit_type_chargeur->clear();
  ui->lineEdit_temps->clear();
    ui->lineEdit_phone->clear();
    stat();
}

void retours::on_send_clicked()
{
    sms s;
     const QString msg = ui->sms->toPlainText();

    const QString recipient_phone_number = "+216"+ ui->phone->text();

   s.sendSMS(recipient_phone_number, msg);
}

void retours::on_save_clicked()
{
    const QString &path = QFileDialog::getSaveFileName(this, QString::null, "qrcodestation", "JPEG (*.jpg *.jpeg)");
       if (path.isNull())
           return;

       // Assuming ui->qrcode->pixmap() returns a QPixmap
       ui->qrcode->pixmap()->save(path, "JPG");
}
void retours::stat(){

    vector<statt> v1,v11,v2,v3,v4;
    QSqlQuery qry,qry1,qry2,qry3;
statt s0,s1,s2,s3;

    qry.prepare("select RÉFÉRANCE,POINTDERECHARGE from station" );


    qry.exec();

        while(qry.next())
        {
            s0.ref=qry.value(0).toString();
            s0.point=qry.value(1).toString();
            v1.push_back(s0);
        }
        int occ0=0,occ01=0,occ02=0,occ03=0,occ1=0,occ2=0,occ3=0,occ4=0;
        QString pointocc="",pointocc1="",pointocc2="",pointocc3="",ref="",ref1="",ref2="",ref3="";
for( int i=0;i<v1.size();i++){
    occ0=0;
    for( int j=0;j<v1.size();j++){
        if (v1[i].point==v1[j].point)
            occ0++;
    }
    if(occ0>occ1){
        occ1=occ0;
    pointocc=v1[i].point;
    ref=v1[i].ref;}
}
qry1.prepare("select RÉFÉRANCE,POINTDERECHARGE from station where POINTDERECHARGE!='"+pointocc+"'" );


qry1.exec();

    while(qry1.next())
    {
        s1.ref=qry1.value(0).toInt();
        s1.point=qry1.value(1).toString();
        v2.push_back(s1);
    }
    for( int i=0;i<v2.size();i++){
        occ01=0;

        for( int j=0;j<v2.size();j++){
            if (v2[i].point==v2[j].point)
                occ01++;
        }
        if(occ01>occ2){
            occ2=occ01;
        pointocc1=v2[i].point;
        ref1=v2[i].ref;}
    }
    qry2.prepare("select RÉFÉRANCE,POINTDERECHARGE from station where POINTDERECHARGE!='"+pointocc+"' and POINTDERECHARGE!='"+pointocc1+"' " );


    qry2.exec();

        while(qry2.next())
        {
            s2.ref=qry2.value(0).toInt();
            s2.point=qry2.value(1).toString();

            v3.push_back(s2);
        }
        for(unsigned int i=0;i<v3.size();i++){
            occ02=0;

            for(unsigned int j=0;j<v3.size();j++){
                if (v3[i].point==v3[j].point)
                    occ02++;
            }
            if(occ02>occ3){
                occ3=occ02;
            pointocc2=v3[i].point;
            ref2=v3[i].ref;}
        }
        qry3.prepare("select RÉFÉRANCE,POINTDERECHARGE from station where POINTDERECHARGE!='"+pointocc+"' and POINTDERECHARGE!='"+pointocc1+"' and POINTDERECHARGE!='"+pointocc2+"'" );


        qry3.exec();

            while(qry3.next())
            {
                s3.ref=qry3.value(0).toInt();
                s3.point=qry3.value(1).toString();

                v4.push_back(s3);
            }
            for(unsigned int i=0;i<v4.size();i++){
                occ03=0;

                for(unsigned int j=0;j<v4.size();j++){
                    if (v4[i].point==v4[j].point)
                        occ03++;
                }
                if(occ03>occ4){
                    occ4=occ03;
                pointocc3=v4[i].point;
                ref3=v4[i].ref;}
            }

QPieSeries *series = new QPieSeries();
series->append(pointocc,occ1);
series->append(pointocc1,occ2);
series->append(pointocc2,occ3);
series->append(pointocc3,occ4);
QPieSlice *slice0 = series->slices().at(0);
slice0->setLabelVisible();
QPieSlice *slice1 = series->slices().at(1);
QPieSlice *slice2 = series->slices().at(2);
slice2->setLabelVisible();
slice2->setExploded();
slice2->setPen(QPen(Qt::darkBlue, 2));
slice2->setBrush(Qt::blue);
QPieSlice *slice3 = series->slices().at(3);
slice3->setLabelVisible();
slice3->setExploded();
slice3->setPen(QPen(Qt::darkGray, 2));
slice3->setBrush(Qt::gray);
slice1->setExploded();
slice1->setLabelVisible();
slice1->setPen(QPen(Qt::darkGreen, 2));
slice1->setBrush(Qt::green);
QChart *chart = new QChart();
 chart->addSeries(series);
 chart->setTitle("Les points le plus populair");

    chart->setAnimationOptions(QChart::AllAnimations);

    chart->legend()->hide();

    chartView = new QChartView(chart,ui->chartview);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(551,291);

    chartView->show();


}
void retours::returnToHomepage() {
    // Implement the logic to return to the homepage here
    // For example:
    espacepro *homepageWidget = new espacepro;
    homepageWidget->show();

    // Hide the current LoggedInWidget
    this->hide();
}
