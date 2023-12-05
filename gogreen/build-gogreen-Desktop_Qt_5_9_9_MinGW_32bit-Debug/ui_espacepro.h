/********************************************************************************
** Form generated from reading UI file 'espacepro.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESPACEPRO_H
#define UI_ESPACEPRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_espacepro
{
public:
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QLabel *label_8;

    void setupUi(QWidget *espacepro)
    {
        if (espacepro->objectName().isEmpty())
            espacepro->setObjectName(QStringLiteral("espacepro"));
        espacepro->resize(987, 571);
        label_4 = new QLabel(espacepro);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 181, 101));
        label_2 = new QLabel(espacepro);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 50, 241, 31));
        pushButton_2 = new QPushButton(espacepro);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 140, 141, 121));
        pushButton_4 = new QPushButton(espacepro);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(80, 140, 141, 121));
        pushButton_5 = new QPushButton(espacepro);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(170, 330, 151, 121));
        pushButton = new QPushButton(espacepro);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(660, 140, 151, 121));
        pushButton_3 = new QPushButton(espacepro);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 330, 151, 121));
        label_8 = new QLabel(espacepro);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 0, 981, 551));
        label_8->raise();
        label_4->raise();
        label_2->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton->raise();
        pushButton_3->raise();

        retranslateUi(espacepro);

        QMetaObject::connectSlotsByName(espacepro);
    } // setupUi

    void retranslateUi(QWidget *espacepro)
    {
        espacepro->setWindowTitle(QApplication::translate("espacepro", "Form", Q_NULLPTR));
        label_4->setText(QString());
        label_2->setText(QApplication::translate("espacepro", "BIENVENUE!", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("espacepro", "GESTION CLIENTS", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("espacepro", "GESTION DE RETOUR", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("espacepro", "RESERVATIONS", Q_NULLPTR));
        pushButton->setText(QApplication::translate("espacepro", "GESTION EMPLOYES", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("espacepro", "GESTION VEHICULES", Q_NULLPTR));
        label_8->setText(QApplication::translate("espacepro", "l", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class espacepro: public Ui_espacepro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESPACEPRO_H
