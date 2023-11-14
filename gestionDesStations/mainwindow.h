#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connection.h"
#include <QMainWindow>
#include "station.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    station s;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
QStringList files;
private slots:

    void on_ajouter_clicked();
    void on_comboBox_trie_currentIndexChanged(const QString &arg1);

    void on_lineEdit_recherche_textChanged(const QString &arg1);

    void on_generate_pdf_clicked();
    void  browse();
    void   sendMail();
void   mailSent(QString status);
void on_tab_stations_clicked(const QModelIndex &index);


void on_HistoriqueBtn_clicked();

void on_deleteBtn_clicked();

void on_modifierBtn_clicked();

void on_send_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
