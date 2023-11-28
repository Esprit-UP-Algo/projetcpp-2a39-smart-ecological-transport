#include "gogreen.h"
#include "ui_gogreen.h"
#include"login.h"
gogreen::gogreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gogreen)
{
    ui->setupUi(this);
      setFixedSize(1000, 500);



    QPixmap img8("C:/Users/MICRO-PC/OneDrive/Bureau/back.png"); // Replace "path/to/your/logo.png" with the actual path to your logo image
        ui->label->setPixmap(img8);
        ui->label->setScaledContents(true);
        ui->label->setFixedSize(1000, 500);
       ui->pushButton->setGeometry(850, 7, 100,30);
        show();
}

gogreen::~gogreen()
{
    delete ui;
}





void gogreen::on_pushButton_clicked()
{  Login *otherWidget = new Login;
    otherWidget->show();
      this->hide();


}
