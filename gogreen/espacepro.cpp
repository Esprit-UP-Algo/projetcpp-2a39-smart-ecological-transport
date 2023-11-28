#include "espacepro.h"
#include "employes.h"
#include"retours.h"
#include "ui_espacepro.h"
#include"QLabel"
#include"gogreen.h"
espacepro::espacepro(QWidget *parent)
    : QWidget(parent), ui(new Ui::espacepro)
{
    ui->setupUi(this); // Setup the UI components
      setFixedSize(1000, 500);


    QPixmap img8("C:/Users/MICRO-PC/Downloads/bb.jpg"); // Replace "path/to/your/logo.png" with the actual path to your logo image
        ui->label_8->setPixmap(img8);
        ui->label_8->setScaledContents(true);
ui->label_2->setStyleSheet("color: #45a049;");
ui->label_2->setFont(QFont("Georgia", 20));

QPixmap logo("C:/Users/MICRO-PC/OneDrive/Bureau/logo.png"); // Replace "path/to/your/logo.png" with the actual path to your logo image

    ui->label_4->setPixmap(logo);
    ui->label_4->setScaledContents(true);
    ui->label_4->setFixedSize(150, 100);
    ui->label_4->setStyleSheet("border: 1px solid #45a049;");


QString buttonStyle = "QPushButton {""border-radius: 25px;" "color: white;""background-color: white;"
  "background-image: url(C:/Users/MICRO-PC/OneDrive/Bureau/emm.png);""background-repeat: no-repeat;"
           "background-position: center;" "}"  "QPushButton:hover {"
                             "background-color: white;"
                               "color: green;"
                          "font-family: Georgia;"
                             "font-size: 12px;"

                             "}" "QPushButton:pressed {"
                             "color: #45a049;";  // Change text color when pressed

        ui->pushButton->setStyleSheet(buttonStyle);
        QString button1Style = "QPushButton {"
    "border-radius: 25px;"
                                 "color: white;"
                        "background-color: white;"
                "background-image: url(C:/Users/MICRO-PC/OneDrive/Bureau/res.png);"
                               "background-repeat: no-repeat;"
                                   "background-position: center;"


                                 "}"
                                 "QPushButton:hover {"
                                 "background-color: white;"
                                    "color: green;"
                               "font-family: Georgia;"
                                  "font-size: 12px;"

                                 "}"
                                 "QPushButton:pressed {"
                                 "color: #45a049;";  // Change text color when pressed

            ui->pushButton_5->setStyleSheet(button1Style);
            QString button2Style = "QPushButton {"
        "border-radius: 25px;"
                                     "color: white;"
                            "background-color: white;"
                    "background-image: url(C:/Users/MICRO-PC/OneDrive/Bureau/cl.png);"
                                   "background-repeat: no-repeat;"
                                       "background-position: center;"


                                     "}"
                                     "QPushButton:hover {"
                                     "background-color: white;"
                    "color: green;"
                                   "font-family: Georgia;"
                                      "font-size: 12px;"

                                     "}"
                                     "QPushButton:pressed {"
                                     "color: #45a049;";  // Change text color when pressed

                ui->pushButton_2->setStyleSheet(button2Style);

                QString button3Style = "QPushButton {"
            "border-radius: 25px;"
                                         "color: white;"
                                "background-color: white;"
                        "background-image: url(C:/Users/MICRO-PC/OneDrive/Bureau/vv.png);"
                                       "background-repeat: no-repeat;"
                                           "background-position: center;"


                                         "}"
                                         "QPushButton:hover {"
                                         "background-color: white;"
                                          "color: green;"
                                       "font-family: Georgia;"
                                          "font-size: 12px;"

                                         "}"
                                         "QPushButton:pressed {"
                                         "color: #45a049;";  // Change text color when pressed

                    ui->pushButton_3->setStyleSheet(button3Style);
                    QString button4Style = "QPushButton {"
                "border-radius: 25px;"
                                             "color: white;"
                                    "background-color: white;"
                            "background-image: url(C:/Users/MICRO-PC/OneDrive/Bureau/ll.png);"
                                           "background-repeat: no-repeat;"
                                               "background-position: center;"


                                             "}"
                                             "QPushButton:hover {"
                                             "background-color: white;"
                                             "color: #45a049;"
                                           "font-family: Georgia;"
                                              "font-size: 12px;"


                                             "}"
                                             "QPushButton:pressed {"
                                             "color: #45a049;";  // Change text color when pressed

                        ui->pushButton_4->setStyleSheet(button4Style);
        QPushButton *returnButton = new QPushButton("Retour", this);
           returnButton->setStyleSheet(" color: white; background-color: green;");
           returnButton->setFont(QFont("Georgia", 12));

           // Set the button's position and size
           returnButton->setGeometry(620, 450, 150, 30); // Adjust position and size as needed

           // Connect the button's clicked signal to the appropriate slot or function
           connect(returnButton, &QPushButton::clicked, this, &espacepro::returnToHomepage);

    show();
    // Other UI setup for the logged-in interface
}

espacepro::~espacepro() {
    delete ui; // Cleanup the UI object
}



void espacepro::on_pushButton_clicked() {
    // Create and show the other widget upon button click
    employes *otherWidget = new employes;
    otherWidget->show();

    // Hide the current LoggedInWidget
    this->hide();
}
void espacepro::on_pushButton_4_clicked() {
    // Create and show the other widget upon button click
    retours *otherWidget = new retours;
    otherWidget->show();

    // Hide the current LoggedInWidget
    this->hide();
}
void espacepro::returnToHomepage() {
    // Implement the logic to return to the homepage here
    // For example:
    gogreen *homepageWidget = new gogreen;
    homepageWidget->show();

    // Hide the current LoggedInWidget
    this->hide();
}
