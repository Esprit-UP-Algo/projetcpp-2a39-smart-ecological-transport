#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QSqlQueryModel>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include <fstream>
#include "client.h"
#include "qrcode.h"
#include<QBuffer>
#include <QImage>
#include<QFileDialog>
#include <QDebug>
#include <QStyledItemDelegate>
#include "arduino.h"
#include<QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startButton = new QPushButton("Start", this);
        connect(startButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_qr_clicked);
    ui->lineEdit_13->setValidator(new QIntValidator(0, 999999, this));
    //ui->le_contact->setValidator(new QIntValidator(0, 99999999, this));
    ui->tableView_2->setModel(ctmp.afficher());
    ui->tableView_1->setModel(ctmp.afficher());
    ui->tableView->setModel(ctmp.afficher());
    //ui->tableView->setItemDelegateForColumn(5, new ImageDelegate(this));
    int ret=ard.connect_arduino();
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

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_17_clicked()
{
    QApplication::quit();

}
void MainWindow::on_pushButton_10_clicked()
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

    /*QString classe=ui->le_classe->currentText();
        QString imagePath = QFileDialog::getOpenFileName(this, "Sélectionnez une image", QString(), "Images (*.png *.xpm *.jpg)");
        if (imagePath.isEmpty())
        {
            QMessageBox::warning(this, "Avertissement", "Aucune image sélectionnée.");
            return;

        }

        QImage image(imagePath);
        if (image.isNull()) {
            QMessageBox::warning(this, "Avertissement", "Impossible de charger l'image sélectionnée.");
            return;
        }

        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        image.save(&buffer, "JPG");*/

}

void MainWindow::on_pushButton_modifier_clicked() //MODIFIER
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

void MainWindow::on_pushButton_supprimer_clicked()
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
/*void MainWindow::on_pushButton_pdf_2_clicked()
{
    QPrinter printer;
    printer.setPrinterName("client");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected)
        return;
    ui->PDF->print(&printer);
}
*/
void MainWindow::on_rechercheID_textChanged(const QString &arg1)
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
void MainWindow::on_Trie_botto_clicked()
{
    ui->tableView_2->setModel(ctmp.sortid_up());
}
void MainWindow::on_Trie_botton_clicked()
{
    ui->tableView_2->setModel(ctmp.sortid_down());
}
void MainWindow::on_pushButton_pdf_2_clicked()
{   QString s;
    s=ui->lineEdit_6->text();
    ctmp.exportpdf(s);
}

/*void MainWindow::on_pushButton_qr_clicked()
{
    using namespace std;

    if(ui->tableView->currentIndex().row()==-1)
                        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                                 QObject::tr("Veuillez Choisir un client du Tableau.\n"
                                                             "Click Ok to exit."), QMessageBox::Ok);
                    else
                    {
                         int  Code=ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0)).toInt();
                         const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(std::to_string(Code).c_str(), qrcodegen::QrCode::Ecc::LOW);
                         std::ofstream myfile;
                         myfile.open ("qrcode.svg") ;
                         myfile << qr.toSvgString(1);
                         myfile.close();
                         QSvgRenderer svgRenderer(QString("qrcode.svg"));
                         QPixmap pix( QSize(90, 90) );
                         QPainter pixPainter( &pix );
                         svgRenderer.render(&pixPainter);
                         ui->label_15->setPixmap(pix);
                    }
}
*/

void MainWindow::on_pushButton_qr_clicked() {
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
