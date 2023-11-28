#ifndef GOGREEN_H
#define GOGREEN_H
#include"QPushButton"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class gogreen; }
QT_END_NAMESPACE

class gogreen : public QMainWindow
{
    Q_OBJECT

public:
    gogreen(QWidget *parent = nullptr);
    ~gogreen();

private slots:


    void on_pushButton_clicked();

private:
    Ui::gogreen *ui;
    QPushButton *goToWidgetButton;
};
#endif // GOGREEN_H
