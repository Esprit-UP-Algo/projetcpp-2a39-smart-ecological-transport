#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connection.h"
#include<reservation.h>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QTextEdit>
#include "mailing.h"
#include "exportexcel.h"
#include<QFileDialog>
#include "arduino.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_recherchecin_textChanged(const QString &arg1);
        void on_Trie_name_clicked();
        void on_pb_pdf_clicked();
        void on_pushButton_send_mail_clicked();
        void on_export_button_clicked();
        void on_calendarWidget_clicked(const QDate &date);


        void on_send_clicked();

        void on_sendMail_clicked();


private:
    Ui::MainWindow *ui;
    reservation r;





};

#endif // MAINWINDOW_H


