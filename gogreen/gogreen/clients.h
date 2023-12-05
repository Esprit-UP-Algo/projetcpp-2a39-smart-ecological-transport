#ifndef CLIENTS_H
#define CLIENTS_H
#include <QMainWindow>
#include<connection.h>
#include <QLineEdit>
#include <QPushButton>
#include <QDate>
#include <QSqlQuery>
#include <QTableWidget>
#include<QTableView>
#include <QMessageBox>
#include "client.h"
#include <QDialog>
#include <QFile>
#include "arduinoc.h"
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class clients; }
QT_END_NAMESPACE

class clients : public QWidget
{
    Q_OBJECT

public:
    clients(QWidget *parent = nullptr);
    ~clients();

private slots:
    void on_pushButton_17_clicked();
     void on_pushButton_10_clicked();
      void on_pushButton_50_clicked();
       void on_pushButton_26_clicked();
        void on_pushButton_58_clicked();
         void on_pushButton_6_clicked();
          void on_pushButton_supprimer_clicked();
           void on_pushButton_modifier_clicked();
          void on_pushButton_pdf_2_clicked();
         void on_rechercheID_textChanged(const QString &arg1);
        void on_Trie_botton_clicked();
       void on_Trie_botto_clicked();
      void on_pushButton_qr_clicked();
      void returnToHomepage() ;


private:
    Ui::clients *ui;
    client ctmp;
    arduinoc ard;
    QPushButton *startButton;
};
class ImageDelegate : public QStyledItemDelegate
{

};
#endif // CLIENTS_H
