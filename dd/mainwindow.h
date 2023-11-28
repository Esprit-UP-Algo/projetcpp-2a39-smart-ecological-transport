#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
#include <qrcode.h>
#include "qrcode.h"
#include "arduino.h"
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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


private:
    Ui::MainWindow *ui;
    client ctmp;
    Arduino ard;
    QPushButton *startButton;
};
class ImageDelegate : public QStyledItemDelegate
{
//public:
   // ImageDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    /*void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        if (index.column() == 7) // remplacez IMAGE_COLUMN_INDEX par l'indice de la colonne contenant l'image dans votre modèle
        {
            // récupérer l'image stockée dans le modèle
            QByteArray imageData = index.model()->data(index, Qt::DisplayRole).toByteArray();
            QPixmap pixmap;
            pixmap.loadFromData(imageData);

            // dessiner l'image sur le painter
            painter->drawPixmap(option.rect, pixmap);
        }
        else
        {
            QStyledItemDelegate::paint(painter, option, index);
        }
    }*/
};
#endif // MAINWINDOW_H
