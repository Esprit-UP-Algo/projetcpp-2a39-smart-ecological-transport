#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"pdf.h"

#include"arduino.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
   arduino(new Arduino(this))
{ // Initialize Arduino instance
         ui->setupUi(this);

         if (arduino->connectToArduino()) {
             qDebug() << "Connected to Arduino!";
             // Perform fingerprint operations as needed
             connect(arduino, &Arduino::fingerprintEnrolled, this, &MainWindow::handleEnrollmentResult);
             connect(arduino, &Arduino::fingerprintVerified, this, &MainWindow::handleVerificationResult);
         } else {
             qDebug() << "Failed to connect to Arduino!";
         }


     ui->lineEdit_2->setValidator(new QRegExpValidator (QRegExp ("[a-zA-Z]+")));
      ui->lineEdit_3->setValidator(new QRegExpValidator (QRegExp ("[a-zA-Z]+")));
     ui->lineEdit->setValidator(new QIntValidator (0,99999999,this));
     ui->lineEdit_4->setValidator(new QIntValidator);
     ui->lineEdit->setValidator(new QIntValidator (0,99999999,this));
     ui->lineEdit_4->setValidator(new QIntValidator);
     ui->lineEdit_16->setValidator(new QIntValidator);
     ui->lineEdit_16->setValidator(new QIntValidator (0,99999999,this));


show();

ui->tableView->setModel(Etmp.afficher());


}
MainWindow::~MainWindow()
{
    delete ui;
     delete arduino;
}



void MainWindow::on_pushButton_ajouter_clicked()
{
    QString IDText = ui->lineEdit->text();
    QString salaireText = ui->lineEdit_4->text();
    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();
   QString poste = ui->POSTE_p->currentText();
    QDate datedebut = ui->dateEdit->date();

    // Check if any required fields are empty
        if (IDText.isEmpty() || salaireText.isEmpty() || nom.isEmpty() || prenom.isEmpty() || poste.isEmpty()) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Veuillez remplir tous les champs obligatoires."), QMessageBox::Ok);
            return;
        }
        if (IDText.length() != 8) {
            QMessageBox::critical(nullptr, tr("Error"), tr("L'ID doit contenir exactement 8 caractères."), QMessageBox::Ok);
              return;
        }

        // Validate the format of numeric input fields
        bool ok;
        int ID = IDText.toInt(&ok);
        if (!ok) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("ID Incorrect."), QMessageBox::Ok);
            return;
        }

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

bool recordExists(int ID) {

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
    QString idText = ui->lineEdit_16->text();

    // Check if the ID field is empty
    if (idText.isEmpty()) {
        QMessageBox::critical(nullptr, tr("Error"), tr("Veuillez entrer un ID."), QMessageBox::Ok);
        return;
    }

    // Validate the format of the ID field
    bool ok;
    int id = idText.toInt(&ok);
    if (!ok) {
        QMessageBox::critical(nullptr, tr("Error"), tr("Veuillez entrer un ID valide."), QMessageBox::Ok);
        return;
    }


    if (idText.length() != 8) {
        QMessageBox::critical(nullptr, tr("Error"), tr("L'ID doit contenir exactement 8 caractères."), QMessageBox::Ok);
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
    QString IDText = ui->lineEdit_11->text();
    QString salaireText = ui->lineEdit_14->text();
    QString nom = ui->lineEdit_12->text();
    QString prenom = ui->lineEdit_13->text();
    QString poste = ui->POSTE_p->currentText();
    QDate datedebut = ui->dateEdit_3->date();



        if (IDText.isEmpty() || salaireText.isEmpty() || nom.isEmpty() || prenom.isEmpty() || poste.isEmpty()) {
            QMessageBox::critical(nullptr, tr("Error"), tr("Please fill in all the required fields."), QMessageBox::Ok);
        return;}


        bool ok;
        int ID = IDText.toInt(&ok);
         salaire = salaireText.toInt(&ok);
        if (!ok) {
            QMessageBox::critical(nullptr, tr("Error"), tr("Invalid value for ID."), QMessageBox::Ok);
             return;

        }
        if (IDText.length() > 8) {
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
    bool idExists = recordExists(id_c);
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

void MainWindow::on_pushButton_2_clicked() //refuser congé
{
    int id_c=ui->lineEdit_5->text().toInt();
   bool test=c.refuser(id_c);
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


void MainWindow::handleEnrollmentResult(bool success) {
    if (success) {
        qDebug() << "Fingerprint enrolled successfully!";
        // Handle success scenario
    } else {
        qDebug() << "Failed to enroll fingerprint!";
        // Handle failure scenario
    }
}

void MainWindow::handleVerificationResult(bool success) {
    if (success) {
        qDebug() << "Fingerprint verified!";
        // Handle success scenario
    } else {
        qDebug() << "Fingerprint verification failed!";
        // Handle failure scenario
    }
}

// Functions to trigger fingerprint operations, e.g., upon button click
void MainWindow::enrollFingerprintButtonClicked() {
    bool enrollmentSuccess = arduino->enrollFingerprint();
    if (!enrollmentSuccess) {
        qDebug() << "Failed to initiate fingerprint enrollment!";
        // Handle failure scenario
    }
}

void MainWindow::verifyFingerprintButtonClicked() {
    bool verificationSuccess = arduino->verifyFingerprint();
    if (!verificationSuccess) {
        qDebug() << "Failed to initiate fingerprint verification!";
        // Handle failure scenario
    }
}


void MainWindow::on_tri_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from EMPLOYEE order by nom ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEDEBUT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("POSTE"));




  ui->tableView->setModel(Etmp.afficher());
}
