#include "stats.h"
#include "ui_stats.h"

stats::stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stats)
{
    ui->setupUi(this);
}

stats::~stats()
{
    delete ui;
}
void stats::pie()
{
    QSqlQuery q1,q2,q3,q4,q5,q6;
    qreal total=0,c1=0,c2=0,c3=0,c4=0,c5=0;
    q1.prepare("Select * from AGENT");
    if(q1.exec())
    {
        while (q1.next())
        {
            total++;
        }
    }
    q2.prepare("Select * from EMPLOYE where POSTE ='Conducteur' ");
    if(q2.exec())
    {
        while (q2.next())
        {
            c1++;
        }
    }
    q3.prepare("Select * from EMPLOYE where POSTE ='Controleur technique' ");
    if(q3.exec())
    {
        while (q3.next())
        {
            c2++;
        }
    }
    q4.prepare("Select * from EMPLOYE where POSTE ='Inspecteur Qualite' ");
    if(q4.exec())
    {
        while (q4.next())
        {
            c3++;
        }
    }
    q5.prepare("Select * from EMPLOYE where POSTE ='Reducateur Technique' ");
    if(q5.exec())
    {
        while (q5.next())
        {
            c4++;
        }
    }
    q6.prepare("Select * from EMPLOYE where POSTE ='RH' ");
    if(q6.exec())
    {
        while (q6.next())
        {
            c5++;
        }
    }
    c1=(c1/total)*100;
    c2=(c2/total)*100;
    c3=(c3/total)*100;
    c4=(c4/total)*100;
    c5=(c5/total)*100;
    QString c1_string = QString::number(c1);
    QString c2_string = QString::number(c2);
    QString c3_string = QString::number(c3);
    QString c4_string = QString::number(c4);
    QString c5_string = QString::number(c5);
    QString infos = (" Conducteur : \t" + c1_string + "% \n Controleur technique : \t" + c2_string +"% \n Inspecteur Qualite : \t"+ c3_string + "% \n Reducateur Technique : \t"+ c4_string + "% \n RH : \t"+ c5_string + "%" );
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.3);
            series->append("Conducteur",c1);
            series->append("Controleur technique",c2);
            series->append("Inspecteur Qualite",c3);
            series->append("Reducateur Technique",c4);
            series->append("RH",c5);
            QPieSlice *slice0 = series->slices().at(0);
            slice0->setExploded();
            slice0->setLabelVisible();
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setExploded();
            slice1->setLabelVisible();
            QPieSlice *slice2 = series->slices().at(2);
            slice2->setExploded();
            slice2->setLabelVisible();
            QPieSlice *slice3 = series->slices().at(3);
            slice3->setExploded();
            slice3->setLabelVisible();
            QPieSlice *slice4 = series->slices().at(4);
            slice4->setExploded();
            slice4->setLabelVisible();
            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("MOST POSTS SAVED");
            chart->setTheme(QChart::ChartThemeLight);
            chart->setAnimationOptions(QChart::AllAnimations);
            chart->legend()->hide();
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            QGridLayout *layout = new QGridLayout();
            layout->addWidget(chartView);
            ui->stat->setLayout(layout);
            ui->stat_2->setText(infos);
}

void stats::on_pushButton_9_clicked()
{
    stats::hide();
}
