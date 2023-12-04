#ifndef RETOURS_H
#define RETOURS_H
#include "connection.h"
#include <QMainWindow>
#include "station.h"
#include "qrcode.h"
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSeries>
#include <QPieSlice>
#include <vector>
QT_BEGIN_NAMESPACE
namespace Ui { class retours; }
QT_END_NAMESPACE

class retours : public QWidget
{
    Q_OBJECT

public:
    QChartView *chartView ;
    station s;
    retours(QWidget *parent = nullptr);
    ~retours();
    void updateQRImage();
QStringList files;
private slots:

    void on_ajouter_clicked();
    void on_comboBox_trie_currentIndexChanged(const QString &arg1);

    void on_lineEdit_recherche_textChanged(const QString &arg1);

    void on_generate_pdf_clicked();
void on_tab_stations_clicked(const QModelIndex &index);



void on_deleteBtn_clicked();

void on_modifierBtn_clicked();

void on_send_clicked();

void on_save_clicked();
void returnToHomepage();

void stat();
private:

bool successfulEncoding;
int encodeImageSize;
QPoint lastPos;
CQR_Encode qrEncode;
    Ui::retours*ui;

};




#endif // RETOURS_H
