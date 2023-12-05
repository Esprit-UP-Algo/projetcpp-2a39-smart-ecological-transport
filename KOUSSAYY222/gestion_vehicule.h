#ifndef GESTION_VEHICULE_H
#define GESTION_VEHICULE_H

#include <QDialog>

namespace Ui {
class gestion_vehicule;
}

class gestion_vehicule : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_vehicule(QWidget *parent = nullptr);
    ~gestion_vehicule();

private:
    Ui::gestion_vehicule *ui;
};

#endif // GESTION_VEHICULE_H
