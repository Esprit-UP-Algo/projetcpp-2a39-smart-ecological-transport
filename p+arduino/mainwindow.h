#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connection.h"
#include <QMainWindow>
#include "station.h"
#include "arduino.h"
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
void on_send_clicked();
    void on_ajouter_clicked();
    void on_comboBox_trie_currentIndexChanged(const QString &arg1);

    void on_lineEdit_recherche_textChanged(const QString &arg1);

    void on_generate_pdf_clicked();
void on_tab_stations_clicked(const QModelIndex &index);



void on_deleteBtn_clicked();

void on_modifierBtn_clicked();

void input();

private:
    Ui::MainWindow *ui;
    Arduino A;
    QByteArray data; // variable contenant les données reçues
QString ref;

};
#endif // MAINWINDOW_H
