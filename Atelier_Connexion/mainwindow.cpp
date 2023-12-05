#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"pdf.h"
#include"arduino.h"
#include <QtCharts>
#include <QChartView>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
         ui->setupUi(this);


     ui->lineEdit_2->setValidator(new QRegExpValidator (QRegExp ("[a-zA-Z]+")));
      ui->lineEdit_3->setValidator(new QRegExpValidator (QRegExp ("[a-zA-Z]+")));
     ui->lineEdit->setValidator(new QIntValidator (0,99999999,this));

     ui->lineEdit_4->setValidator(new QIntValidator);

     ui->lineEdit_4->setValidator(new QIntValidator);
     ui->lineEdit_16->setValidator(new QIntValidator);
     ui->lineEdit_16->setValidator(new QIntValidator (0,99999999,this));
     ui->tri->addItem("par NOM");
     ui->tri->addItem("par PRENOM");
     ui->tri->addItem("par SALAIRE");
     ui->tri->addItem("par POSTE");
     ui->tri->addItem("par ID");
     int ret=A.connect_arduino(); // lancer la connexion à arduino
     switch(ret){
     case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
         break;
     case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
     case(-1):qDebug() << "arduino is not available";
     }
      QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
      //le slot update_label suite à la reception du signal readyRead (reception des données).



show();
stat();

ui->tableView->setModel(Etmp.afficher());


}
MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_pushButton_ajouter_clicked()
{
    QString ID= ui->lineEdit->text();
    QString salaireText = ui->lineEdit_4->text();
    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();
   QString poste = ui->poste_p->currentText();
    QDate datedebut = ui->dateEdit->date();

    // Check if any required fields are empty
        if (ID.isEmpty() || salaireText.isEmpty() || nom.isEmpty() || prenom.isEmpty() || poste.isEmpty()) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Veuillez remplir tous les champs obligatoires."), QMessageBox::Ok);
            return;
        }


        // Validate the format of numeric input fields
        bool ok;

        int salaire = salaireText.toInt(&ok);
        if (!ok) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("valeur du salaire est incorrect."), QMessageBox::Ok);
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

bool recordExists(QString ID) {

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYE WHERE id = :id");
    query.bindValue(":id", ID);
    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    QString id= ui->lineEdit_16->text();

    // Check if the ID field is empty
    if (id.isEmpty()) {
        QMessageBox::critical(nullptr, tr("Error"), tr("Veuillez entrer un ID."), QMessageBox::Ok);
        return;
    }

 // Check if the ID exists before deletion
    bool idExists = recordExists(id);
    if (!idExists) {
        QMessageBox::critical(nullptr, tr("Error"), tr("L'ID spécifié n'existe pas."), QMessageBox::Ok);
        return;
    }

    bool test = Etmp.supprimer(id);
    if (test)
    {
        ui->tableView->setModel(Etmp.afficher());

        QMessageBox::information(nullptr, tr("OK"), tr("Suppression effectuée."), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr, tr("NOT OK"), tr("La suppression n'a pas été effectuée."), QMessageBox::Ok);
    }
}
void MainWindow::on_pushButton_modifier_clicked()
{
    QString ID = ui->lineEdit_11->text();
    QString salaireText = ui->lineEdit_14->text();
    QString nom = ui->lineEdit_12->text();
    QString prenom = ui->lineEdit_13->text();
    QString poste = ui->POSTE_p->currentText();
    QDate datedebut = ui->dateEdit_3->date();



        if (ID.isEmpty() || salaireText.isEmpty() || nom.isEmpty() || prenom.isEmpty() || poste.isEmpty()) {
            QMessageBox::critical(nullptr, tr("Error"), tr("Please fill in all the required fields."), QMessageBox::Ok);
        return;}


        bool ok;

         salaire = salaireText.toInt(&ok);
        if (!ok) {
            QMessageBox::critical(nullptr, tr("Error"), tr("Invalid value for ID."), QMessageBox::Ok);
             return;

        }
        if (ID.length() > 8) {
              QMessageBox::critical(nullptr, tr("Error"), tr("ID should not exceed 8 characters."), QMessageBox::Ok);
              return;
          }

        if (!recordExists(ID)) {
            QMessageBox::critical(nullptr, tr("Error"), tr("Record with ID does not exist."), QMessageBox::Ok);
            return;

        }

        salaireText.toInt(&ok);
        if (!ok) {
            QMessageBox::critical(nullptr, tr("Error"), tr("Invalid value for salaire."), QMessageBox::Ok);

        }

    Employe E(ID,salaire, datedebut, nom, prenom, poste);
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




/*void MainWindow::on_pushButton_7_clicked()
{
    s = new stats ();
    s->setWindowTitle("MOST POSTS SAVED");
    s->pie();
    s->show();
}*/
void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
     ui->tableView->setModel(Etmp.recherche(arg1));
}

void MainWindow::on_pushButton_3_clicked() // ajouter congé
{

    int id_c=ui->lineEdit_5->text().toInt();
    QDate d1=ui->dateEdit_2->date();
    QDate d2=ui->dateEdit_4->date();
    QString etat="";
     QString idText = ui->lineEdit_5->text();
   bool idExists = recordExists(idText);
    if (!idExists) {
        QMessageBox::critical(nullptr, tr("Error"), tr("L'ID spécifié n'existe pas."), QMessageBox::Ok);
        return;
    }
    conge c(id_c,d1,d2,etat);

    bool test=c.ajouter();
    if(test)
    {

     QMessageBox::information(this,"edit","validee");

    }
    else
    {
            QMessageBox::warning(this,"edit","failed");
    }
    ui->tableView_2->setModel(c.affiche());
}


void MainWindow::on_supp_clicked()//supprimer congé
{
    int id_c=ui->lineEdit_5->text().toInt();
      bool test=c.supprimer(id_c);
      if (test)
      {
ui->tableView_2->setModel(c.affiche());
       QMessageBox::information(this,"edit","validee");

      }
      else
      {QMessageBox::warning(this,"edit","failed");
  }

}




void MainWindow::on_confirmer_clicked()//confirmer congé
{
    int id_c=ui->lineEdit_5->text().toInt();
   bool test=c.modifier(id_c);
      if (test)
      {

       QMessageBox::information(this,"edit","validee");

      }

      else
      {
          QMessageBox::warning(this,"edit","failed");
    }
    ui->tableView_2->setModel(c.affiche());
}

void MainWindow::on_pushButton_4_clicked()//retour
{
    ui->lineEdit_5->clear();
    ui->dateEdit_2->clear();
    ui->dateEdit_4->clear();
}



void MainWindow::on_pushButton_22_clicked()

    {
        exportTableViewToPDF(ui->tableView_2);
    }




void MainWindow::on_aff_clicked()
{
    ui->tableView_3->setModel(Etmp.afficher());

}







void MainWindow::on_tri_currentIndexChanged(const QString &arg1)
{
    ui->tableView->setModel(Etmp.trier(arg1));
}
void MainWindow::stat(){
        QSqlQuery q1,q2,q3,q4,q5,q6;
        qreal total=0,c1=0,c2=0,c3=0,c4=0,c5=0;
        q1.prepare("Select * from EMPLOYE");
        if(q1.exec())
        {
            while (q1.next())
            {
                total++;
            }
        }
        q2.prepare("Select * from EMPLOYE where POSTE ='Conducteur' ");
        if(q2.exec())
        {
            while (q2.next())
            {
                c1++;
            }
        }
        q3.prepare("Select * from EMPLOYE where POSTE ='Controleur technique' ");
        if(q3.exec())
        {
            while (q3.next())
            {
                c2++;
            }
        }
        q4.prepare("Select * from EMPLOYE where POSTE ='Inspecteur Qualite' ");
        if(q4.exec())
        {
            while (q4.next())
            {
                c3++;
            }
        }
        q5.prepare("Select * from EMPLOYE where POSTE ='Reducateur Technique' ");
        if(q5.exec())
        {
            while (q5.next())
            {
                c4++;
            }
        }
        q6.prepare("Select * from EMPLOYE where POSTE ='RH' ");
        if(q6.exec())
        {
            while (q6.next())
            {
                c5++;
            }
        }
        c1=(c1/total)*100;
        c2=(c2/total)*100;
        c3=(c3/total)*100;
        c4=(c4/total)*100;
        c5=(c5/total)*100;
        QString c1_string = QString::number(c1);
        QString c2_string = QString::number(c2);
        QString c3_string = QString::number(c3);
        QString c4_string = QString::number(c4);
        QString c5_string = QString::number(c5);
        QString infos = (" Conducteur : \t" + c1_string + "% \n Controleur technique : \t" + c2_string +"% \n Inspecteur Qualite : \t"+ c3_string + "% \n Reducateur Technique : \t"+ c4_string + "% \n RH : \t"+ c5_string + "%" );
        QPieSeries *series = new QPieSeries();
        series->setHoleSize(0.3);
                series->append("Conducteur",c1);
                series->append("Controleur technique",c2);
                series->append("Inspecteur Qualite",c3);
                series->append("Reducateur Technique",c4);
                series->append("RH",c5);
                QPieSlice *slice0 = series->slices().at(0);
                slice0->setExploded();
                slice0->setLabelVisible();
                QPieSlice *slice1 = series->slices().at(1);
                slice1->setExploded();
                slice1->setLabelVisible();
                QPieSlice *slice2 = series->slices().at(2);
                slice2->setExploded();
                slice2->setLabelVisible();
                QPieSlice *slice3 = series->slices().at(3);
                slice3->setExploded();
                slice3->setLabelVisible();
                QPieSlice *slice4 = series->slices().at(4);
                slice4->setExploded();
                slice4->setLabelVisible();
                QChart *chart = new QChart();
                 chart->addSeries(series);
                 chart->setTitle("Les postes");

                    chart->setAnimationOptions(QChart::AllAnimations);

                    chart->legend()->hide();

                    chartView = new QChartView(chart,ui->chartview);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->setMinimumSize(551,291);

                    chartView->show();

    }

void MainWindow::update_label()
{
    if (data.endsWith("\n") || data.endsWith("\t")) {
        data.chop(2);
        qDebug() << data << endl;

        // Test the existence of an employe with the received code
        QSqlQueryModel *model = Etmp.testCode(QString(data));

        // Check if the model has any rows, i.e., if the code is valid
        if (model->rowCount() > 0) {
            // Get the first row of the model
            QSqlRecord record = model->record(0);
            // Get the name and surname of the employe from the model
            QString nom = record.value("NOM").toString();
            QString prenom = record.value("PRENOM").toString();
            // Write the greeting message to the Arduino
            QByteArray message = "slt " + nom.toUtf8() + " " + prenom.toUtf8() + "\n";
            A.write_to_arduino(message);
            data ="";

        } else {
            // Write the not authorized message to the Arduino
            QByteArray message = "Non autorisé\n";
            A.write_to_arduino(message);
            data ="";

        }
    } else {
        data += A.read_from_arduino();
    }
}

