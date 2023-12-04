#include "vehicule.h"
#include "ui_Vehicule.h"
#include "vhicule.h"
#include <QMessageBox>
#include "connection.h"
#include <QDebug>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QMessageBox>
#include <QFileDialog>
#include "QDateTime"
#include <memory>
#include<espacepro.h>
#include <QFile>
#include <QTextStream>

QChart *chart; // Add this member variable
    QWidget *chartWidget;
Vehicule::Vehicule(QWidget *parent) :
         QWidget(parent),
    ui(new Ui::Vehicule)
{
    ui->setupUi(this);
    ui->tab_v->setModel(V.afiicher());
    ui->tab_v_3->setModel(V.afiicherh());
    int ret=A.connect_arduino(); // lancer la connexion à arduino
                switch(ret){
                case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                    break;
                case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                   break;
                case(-1):qDebug() << "arduino is not available";
                }
                ui->tab_v->setModel(V.afiicher());
                ui->tab_v_3->setModel(V.afiicherh());
              /*  QPushButton *returnButton = new QPushButton("Retour", this);
                           returnButton->setStyleSheet(" color: white; background-color: green;");
                           returnButton->setFont(QFont("Georgia", 12));

                           // Set the button's position and size
                           returnButton->setGeometry(30, 180, 100, 30); // Adjust position and size as needed

                           // Connect the button's clicked signal to the appropriate slot or function
                           connect(returnButton, &QPushButton::clicked, this, &Vehicule::returnToHomepage);*/

}

Vehicule::~Vehicule()
{
    delete ui;
}

//ajouter fonction
void Vehicule::on_ajout_clicked()
{
    QString immatricule = ui->imm->text();
    QString marque = ui->marq->currentText();
    QString modele = ui->mode->currentText();
    QString puissance = ui->pui->currentText();
    QString type_de_recharge = ui->ty->currentText();
    QString reference = ui->ref->text();

    // Validate immatricule with a regular expression
    QRegularExpression immatriculeRegex("^[a-zA-Z0-9]{8}$");
    // Validate reference with a regular expression
    QRegularExpression referenceRegex("^[a-zA-Z]{1,10}$");

    if (!immatriculeRegex.match(immatricule).hasMatch()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Immatricule doit contenir  8 caractères avec des lettres et des chiffres seulement."), QMessageBox::Ok);
    } else if (!referenceRegex.match(reference).hasMatch()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Référence doit contenir maximum 10 caractères alphabétiques."), QMessageBox::Ok);
    } else if (immatricule.isEmpty() || marque.isEmpty() || modele.isEmpty() || puissance.isEmpty() || type_de_recharge.isEmpty() || reference.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Tous les champs doivent être remplis."), QMessageBox::Ok);
    } else {
        // Additional validation checks for other input fields can be added here.

        // If all input is valid, proceed with the database insertion.
        Vhicule V(immatricule, marque, modele, puissance, type_de_recharge, reference);

        bool test = V.ajouter();

        if (test) {
            ui->tab_v->setModel(V.afiicher());
            ui->tab_v_3->setModel(V.afiicherh());
            statistiques();
            // Si l'ajout est réussi, affichez un message de succès.
            QMessageBox::information(nullptr, QObject::tr("Succès"),
                                     QObject::tr("Ajout effectué avec succès."),
                                     QMessageBox::Ok);
            A.write_to_arduino("ajout de "+immatricule);
            QSqlQuery query;
            query.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
            query.bindValue(":message", "ajout de "+immatricule);
            query.bindValue(":datemess", QDateTime::currentDateTime());
            query.exec();
            notification("New vehicle created!");

            // Save the vehicle information to a file
            QString vehicleInfo = QString("%1, %2, %3, %4, %5, %6")
                                      .arg(immatricule, marque, modele, puissance, type_de_recharge, reference);
            saveToFile("vehicle_history.txt", vehicleInfo);
        } else {
            // En cas d'échec, affichez un message d'erreur.
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Ajout non effectué."),
                                  QMessageBox::Ok);
        }
    }
}



//void Vehicule::on_ajout_clicked()
//{
//    QString immatricule = ui->imm->text();
//    QString marque = ui->marq->currentText();
//    QString modele = ui->mode->currentText();
//    QString puissance = ui->pui->currentText();
//    QString type_de_recharge = ui->ty->currentText();
//    QString reference = ui->ref->text();

//    // Validate immatricule with a regular expression
//    QRegularExpression immatriculeRegex("^[a-zA-Z0-9]{8}$");
//    // Validate reference with a regular expression
//    QRegularExpression referenceRegex("^[a-zA-Z]{1,10}$");

//    if (!immatriculeRegex.match(immatricule).hasMatch()) {
//        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Immatricule doit contenir  8 caractères avec des lettres et des chiffres seulement."), QMessageBox::Ok);
//    } else if (!referenceRegex.match(reference).hasMatch()) {
//        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Référence doit contenir maximum 10 caractères alphabétiques."), QMessageBox::Ok);
//    } else if (immatricule.isEmpty() || marque.isEmpty() || modele.isEmpty() || puissance.isEmpty() || type_de_recharge.isEmpty() || reference.isEmpty()) {
//        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Tous les champs doivent être remplis."), QMessageBox::Ok);
//    } else {
//        // Additional validation checks for other input fields can be added here.

//        // If all input is valid, proceed with the database insertion.
//        Vhicule V(immatricule, marque, modele, puissance, type_de_recharge, reference);

//        bool test = V.ajouter();

//        if (test) {
//            // Si l'ajout est réussi, affichez un message de succès.
//            QMessageBox::information(nullptr, QObject::tr("Succès"),
//                                     QObject::tr("Ajout effectué avec succès."),
//                                     QMessageBox::Ok);
//            A.write_to_arduino("ajout de "+immatricule);
//            QSqlQuery query;
//            query.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
//            query.bindValue(":message", "ajout de "+immatricule);
//            query.bindValue(":datemess", QDateTime::currentDateTime());
//            query.exec();
//             showNotification("New vehicle created!");
//        } else {
//            // En cas d'échec, affichez un message d'erreur.
//            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
//                                  QObject::tr("Ajout non effectué."),
//                                  QMessageBox::Ok);
//        }
//    }
//}



//supp fonction
void Vehicule::on_supp_clicked()
{
    QString mat = ui->imm->text();
    Vhicule V;
    V.setimmatricule(mat);
    if (checkImmatriculeExistence(mat)){
    bool test = V.supprimer(mat);


    if (test)
    {
        statistiques();

        // Si la suppression est réussie, affichez un message de succès.
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Suppression effectuée avec succès."),
                                 QMessageBox::Ok);
        ui->tab_v->setModel(V.afiicher());
        ui->tab_v_3->setModel(V.afiicherh());
        A.write_to_arduino("supp de "+mat);
        QSqlQuery query;
        query.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
        query.bindValue(":message", "supprission de "+mat);
        query.bindValue(":datemess", QDateTime::currentDateTime());
        query.exec();
        notification("Vehicule Deleted!");
    }
    else
    {
        // En cas d'échec, affichez un message d'erreur.
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Suppression non effectuée."),
                              QMessageBox::Ok);
    }
}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("immatricule n'existe pas "),
                              QMessageBox::Ok);
    }
}


//modif


void Vehicule::on_modifier_clicked() {
    QString immatricule = ui->imm->text();
    QString marque = ui->marq->currentText();
    QString modele = ui->mode->currentText();
    QString puissance = ui->pui->currentText();
    QString type_de_recharge = ui->ty->currentText();
    QString reference = ui->ref->text();

      Vhicule V(immatricule, marque, modele, puissance, type_de_recharge, reference);
      bool immatriculeExists = checkImmatriculeExistence(immatricule);

          if (!immatriculeExists) {
              // If immatricule does not exist, display an error message
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                    QObject::tr("Immatricule n'existe pas."),
                                    QMessageBox::Ok);
              return;  // Exit the function without attempting modification
          }
        bool test = V.modifier(immatricule);

        if (test) {
            statistiques();

            // Si la modification est réussi, affichez un message de succès.
            QMessageBox::information(nullptr, QObject::tr("Succès"),
                                     QObject::tr("Modification effectué avec succès."),
                                     QMessageBox::Ok);
            A.write_to_arduino("mod de "+immatricule);
            QSqlQuery query;
            query.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
            query.bindValue(":message", "modification de "+immatricule);
            query.bindValue(":datemess", QDateTime::currentDateTime());
            query.exec();
//             showNotification("Database Updated!");
            notification("Database Updated!");
            ui->tab_v->setModel(V.afiicher());
            ui->tab_v_3->setModel(V.afiicherh());

        } else {
            // En cas d'échec, affichez un message d'erreur.
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Modification non effectué."),
                                  QMessageBox::Ok);
        }
    }

bool Vehicule::checkImmatriculeExistence(const QString& immatricule) {
    QSqlQuery query;

    // Assuming you have a table named 'vehicules' with a column 'immatricule'
    QString queryString = "SELECT COUNT(*) FROM VEHICULE WHERE IMMATRICULE = :immatricule";
    query.prepare(queryString);
    query.bindValue(":immatricule", immatricule);

    if (query.exec() && query.next()) {
        // If the query is successful, check if the count is greater than 0
        int count = query.value(0).toInt();
        return count > 0;
    } else {
        // If the query fails, you might want to handle the error
        qDebug() << "Error checking immatricule existence:" << query.lastError().text();
        return false;  // Return false in case of an error
    }
}








void Vehicule::on_comboBox_activated(const QString&arg1)
{
    QString tri;

    if (arg1 == "Croissant") {
        tri = "ASC";
        ui->tab_v->setModel(V.trier(tri)); // Assuming 'trier' is a function that sorts the data
    } else if (arg1 == "Décroissant") {
        tri = "DESC";
        ui->tab_v->setModel(V.trier(tri)); // Assuming 'trier' is a function that sorts the data
    } else {
        ui->tab_v->setModel(V.afiicher()); // Assuming 'afiicher' is a function that displays the data
    }
}




//C:/Users/benattia/Downloads/logo (1).png

void Vehicule::on_pushButton_3_clicked()
{
    // Ask the user for a file name to save the PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");

    if (!fileName.isEmpty()) {
        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);

        // Set the page size (e.g., A4)
        printer.setPageSize(QPrinter::A4);

        // Set the page orientation (optional)
        printer.setOrientation(QPrinter::Portrait);

        // Set margins (optional)
        printer.setPageMargins(QMarginsF(10, 10, 10, 10));

        QPainter painter(&printer);

        // Set the scaling factor to grow the content in the PDF
        const qreal scaleFactor = 9.0;
        painter.scale(scaleFactor, scaleFactor);

        // Resize and position the logo
        QPixmap logo("C:/Users/benattia/Downloads/logo (1).png");
        int logoWidth = 100; // Set the desired width
        int logoHeight = logo.width() > 0 ? (logoWidth * logo.height()) / logo.width() : 0;
        int logoX = 100;  // Set the desired X position
        int logoY = 200;  // Set the desired Y position
        painter.drawPixmap(logoX, logoY, logo.scaled(logoWidth, logoHeight, Qt::KeepAspectRatio));

        // Get the height of the captured content
        //int capturedContentHeight = ui->tab_v->height() * scaleFactor;

        // Render the QTableView onto the PDF
        ui->tab_v->render(&painter, QPoint(200, 300));  // Adjust the position as needed

        // Check if the painter is active after rendering
        if (painter.isActive()) {
            QMessageBox::information(this, "PDF Saved", "PDF saved successfully!");

            A.write_to_arduino("Creation de PDF");
            QSqlQuery query;
            query.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
            query.bindValue(":message", "Creation de PDF");
            query.bindValue(":datemess", QDateTime::currentDateTime());
            query.exec();
        } else {
            QMessageBox::warning(this, "Error", "Failed to save PDF. Check your printer settings and try again.");
        }

        // Draw fixed text below the captured content with the current date
        QString fixedText = "Your PDF Created By KOUSSAY \n  At  : " + QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss");

        // Set font and color
        QFont font("Calibri", 2, QFont::Bold);  // Example: Use Arial font, size 12, and bold
         // Adjust the point size as needed
        painter.setFont(font);

        QColor textColor(Qt::black);  // Adjust the color as needed
        painter.setPen(textColor);

        // Draw the text at the specified position
        int textX = 50;  // Set the desired X position
        int textY = logoY + logoHeight + ui->tab_v->height() + 300;  // Adjust the Y position as needed
        painter.drawText(textX, textY, fixedText);

        notification("PDF Created!");
    }
}








void Vehicule::showNotification(const QString& message)
{
    std::unique_ptr<PopUp> popup(new PopUp());
        popup->setPopupText(message);
        popup->showWithoutAnimation();
        qDebug() << "Popup visibility: " << popup->isVisible();
}


void Vehicule::notification(QString ch)//.cpp
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    QIcon icon("C:/Users/benattia/Downloads/notif.png");
    // Set the loaded icon to the system tray icon
    notifyIcon->setIcon(icon);
    notifyIcon->show();
    notifyIcon->showMessage("!!!!!",ch,QSystemTrayIcon::Information,15000);
}






void Vehicule::statistiques()
{
    // Initialize variables to count vehicles for each model
    int mercedesCount = 0, teslaCount = 0, kiaCount = 0, bmwCount = 0, fordCount = 0;

    // Execute queries to count vehicles for each model
    QSqlQuery query("SELECT COUNT(*) FROM VEHICULE WHERE MARQUE='Mercedes'");
    while (query.next())
    {
        mercedesCount = query.value(0).toInt();
    }

    QSqlQuery query2("SELECT COUNT(*) FROM VEHICULE WHERE MARQUE='Tesla'");
    while (query2.next())
    {
        teslaCount = query2.value(0).toInt();
        qDebug() << "ID:" << teslaCount;
    }

    QSqlQuery query3("SELECT COUNT(*) FROM VEHICULE WHERE MARQUE='Kia'");
    while (query3.next())
    {
        kiaCount = query3.value(0).toInt();
    }

    QSqlQuery query4("SELECT COUNT(*) FROM VEHICULE WHERE MARQUE='Bmw'");
    while (query4.next())
    {
        bmwCount = query4.value(0).toInt();
    }

    QSqlQuery query5("SELECT COUNT(*) FROM VEHICULE WHERE MARQUE='Ford'");
    while (query5.next())
    {
        fordCount = query5.value(0).toInt();
    }

    // Create a pie chart series
    QPieSeries *series = new QPieSeries();

    // Append data to the series
    series->append("Mercedes", mercedesCount);
    series->append("Tesla", teslaCount);
    series->append("Kia", kiaCount);
    series->append("BMW", bmwCount);
    series->append("Ford", fordCount);



    // Customize the appearance of slices
    QPieSlice *slice1 = series->slices().at(0);
    QPieSlice *slice2 = series->slices().at(1);
    QPieSlice *slice3 = series->slices().at(2);
    QPieSlice *slice4 = series->slices().at(3);
    QPieSlice *slice5 = series->slices().at(4);
    slice1->setLabel("Mercedes: " + QString::number(mercedesCount));
        slice2->setLabel("Tesla: " + QString::number(teslaCount));
        slice3->setLabel("Kia: " + QString::number(kiaCount));
        slice4->setLabel("BMW: " + QString::number(bmwCount));
        slice5->setLabel("Ford: " + QString::number(fordCount));


    // Customize each slice
    slice1->setBrush(QColor("#1f77b4"));  // Blue
    slice1->setLabelColor(QColor("#1f77b4"));

    slice2->setBrush(QColor("#ff7f0e"));  // Orange
    slice2->setLabelColor(QColor("#ff7f0e"));

    slice3->setBrush(QColor("#2ca02c"));  // Green
    slice3->setLabelColor(QColor("#2ca02c"));

    slice4->setBrush(QColor("#d62728"));  // Red
    slice4->setLabelColor(QColor("#d62728"));

    slice5->setBrush(QColor("#9467bd"));  // Purple
    slice5->setLabelColor(QColor("#9467bd"));

    // Create a chart and add the series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistics of Vehicle Models");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::AllAnimations);

    // Create a chart view and set its size
    chartView = new QChartView(chart,ui->chartview);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(661,321);

    chartView->show();

}





void Vehicule::saveToFile(const QString &filename, const QString &data)
{
    QFile file(filename);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << data << "\n";
        file.close();
    } else {
        qDebug() << "Failed to open the file for writing.";
    }
}

void Vehicule::on_tab_v_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tab_v->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select * from vehicule where IMMATRICULE='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {

            ui->imm->setText(qry.value(0).toString());
            ui->pui->setCurrentText(qry.value(3).toString());
            ui->marq->setCurrentText(qry.value(1).toString());
            ui->mode->setCurrentText(qry.value(2).toString());
            ui->ty->setCurrentText(qry.value(4).toString());
            ui->ref->setText(qry.value(5).toString());
        }
}
}

void Vehicule::on_ch_textChanged(const QString &arg1)
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->ch->text();

    if(text.isEmpty())
    {
        ui->tab_v->setModel(V.afiicher());

        ui->tab_v->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    }
    else
    {
        qry->prepare("select * from vehicule where ( IMMATRICULE LIKE'%"+text+"%' OR MARQUE LIKE'%"+text+"%' OR MODELE LIKE'%"+text+"%'OR TYPE_CHARGE LIKE'%"+text+"%' OR PUISSANCE LIKE'%"+text+"%' OR REFERENCE LIKE'%"+text+"%') ");
        qry->exec();
        modal->setQuery(*qry);
        ui->tab_v->setModel(modal);
    }
}

void Vehicule::on_pushButton_19_clicked()
{
    ui->tab_v->setModel(V.afiicher());
    ui->tab_v_3->setModel(V.afiicherh());
    statistiques();
}
