#ifndef VEHICULE_H
#define VEHICULE_H

#include"vhicule.h"
#include <QMainWindow>
#include <QObject>
#include <QString>
#include "popup.h"
#include "arduino.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QtCharts>
#include <QtCharts/QPieSlice>


namespace Ui {
class Vehicule;
}

class Vehicule : public QMainWindow
{
    Q_OBJECT

public:
    explicit Vehicule(QWidget *parent = nullptr);
    ~Vehicule();
    void showNotification(const QString& message);
    bool checkImmatriculeExistence(const QString& immatricule);
    void statistiques();
    QWidget* chartWidget;
    QChartView* chartView;
    void saveToFile(const QString &filename, const QString &data);
    void notification(QString);
private slots:
    void on_ajout_clicked();

    void on_supp_clicked();

    void on_modifier_clicked();

//    void on_trier_clicked();
//   void onComboBoxCurrentIndexChanged( QString arg1);



  void on_comboBox_activated(const QString &arg1);



  void on_pushButton_3_clicked();




  void on_tab_v_clicked(const QModelIndex &index);

  void on_ch_textChanged(const QString &arg1);

  void on_pushButton_19_clicked();

private:
    Ui::Vehicule *ui;
    Vhicule V;
    QByteArray data; // variable contenant les données reçues
QString ref;
       Arduino A;
       historique h;

};

#endif // VEHICULE_H
