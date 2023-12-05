/********************************************************************************
** Form generated from reading UI file 'retours.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETOURS_H
#define UI_RETOURS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_retours
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit_ref;
    QLabel *label_2;
    QLineEdit *lineEdit_point;
    QLabel *label_3;
    QLineEdit *lineEdit_type_chargeur;
    QLabel *label_4;
    QLineEdit *lineEdit_temps;
    QPushButton *ajouter;
    QPushButton *modifierBtn;
    QLineEdit *lineEdit_phone;
    QLabel *label_11;
    QWidget *tab_3;
    QTableView *tab_stations;
    QLineEdit *lineEdit_recherche;
    QComboBox *comboBox_trie;
    QPushButton *generate_pdf;
    QPushButton *deleteBtn;
    QLabel *qrcode;
    QPushButton *save;
    QWidget *tab;
    QLabel *chartview;
    QWidget *tab_4;
    QPushButton *send;
    QTextEdit *sms;
    QLineEdit *phone;
    QLabel *label_5;

    void setupUi(QWidget *retours)
    {
        if (retours->objectName().isEmpty())
            retours->setObjectName(QStringLiteral("retours"));
        retours->resize(1121, 604);
        tabWidget = new QTabWidget(retours);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(170, 0, 741, 511));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 70, 461, 261));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 50, 56, 16));
        lineEdit_ref = new QLineEdit(groupBox);
        lineEdit_ref->setObjectName(QStringLiteral("lineEdit_ref"));
        lineEdit_ref->setGeometry(QRect(150, 50, 113, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 80, 56, 16));
        lineEdit_point = new QLineEdit(groupBox);
        lineEdit_point->setObjectName(QStringLiteral("lineEdit_point"));
        lineEdit_point->setGeometry(QRect(150, 80, 113, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 110, 91, 20));
        lineEdit_type_chargeur = new QLineEdit(groupBox);
        lineEdit_type_chargeur->setObjectName(QStringLiteral("lineEdit_type_chargeur"));
        lineEdit_type_chargeur->setGeometry(QRect(150, 110, 113, 22));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 140, 56, 16));
        lineEdit_temps = new QLineEdit(groupBox);
        lineEdit_temps->setObjectName(QStringLiteral("lineEdit_temps"));
        lineEdit_temps->setGeometry(QRect(150, 140, 113, 22));
        ajouter = new QPushButton(groupBox);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(330, 210, 93, 28));
        modifierBtn = new QPushButton(groupBox);
        modifierBtn->setObjectName(QStringLiteral("modifierBtn"));
        modifierBtn->setGeometry(QRect(190, 210, 93, 28));
        lineEdit_phone = new QLineEdit(groupBox);
        lineEdit_phone->setObjectName(QStringLiteral("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(150, 170, 113, 22));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(60, 170, 56, 16));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tab_stations = new QTableView(tab_3);
        tab_stations->setObjectName(QStringLiteral("tab_stations"));
        tab_stations->setGeometry(QRect(20, 50, 671, 281));
        tab_stations->setSelectionBehavior(QAbstractItemView::SelectRows);
        lineEdit_recherche = new QLineEdit(tab_3);
        lineEdit_recherche->setObjectName(QStringLiteral("lineEdit_recherche"));
        lineEdit_recherche->setGeometry(QRect(440, 20, 191, 21));
        comboBox_trie = new QComboBox(tab_3);
        comboBox_trie->setObjectName(QStringLiteral("comboBox_trie"));
        comboBox_trie->setGeometry(QRect(40, 20, 151, 21));
        generate_pdf = new QPushButton(tab_3);
        generate_pdf->setObjectName(QStringLiteral("generate_pdf"));
        generate_pdf->setGeometry(QRect(30, 350, 93, 28));
        deleteBtn = new QPushButton(tab_3);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        deleteBtn->setGeometry(QRect(140, 350, 93, 28));
        qrcode = new QLabel(tab_3);
        qrcode->setObjectName(QStringLiteral("qrcode"));
        qrcode->setGeometry(QRect(470, 340, 171, 131));
        save = new QPushButton(tab_3);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(340, 390, 93, 28));
        save->setStyleSheet(QStringLiteral(""));
        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        chartview = new QLabel(tab);
        chartview->setObjectName(QStringLiteral("chartview"));
        chartview->setGeometry(QRect(20, 110, 551, 291));
        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        send = new QPushButton(tab_4);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(230, 380, 93, 28));
        sms = new QTextEdit(tab_4);
        sms->setObjectName(QStringLiteral("sms"));
        sms->setGeometry(QRect(130, 90, 321, 261));
        phone = new QLineEdit(tab_4);
        phone->setObjectName(QStringLiteral("phone"));
        phone->setGeometry(QRect(190, 50, 171, 21));
        tabWidget->addTab(tab_4, QString());
        label_5 = new QLabel(retours);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, -20, 167, 561));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../Bureau/login.png")));

        retranslateUi(retours);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(retours);
    } // setupUi

    void retranslateUi(QWidget *retours)
    {
        retours->setWindowTitle(QApplication::translate("retours", "Form", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("retours", "reference", Q_NULLPTR));
        label_2->setText(QApplication::translate("retours", "point ", Q_NULLPTR));
        label_3->setText(QApplication::translate("retours", "type_chargeur", Q_NULLPTR));
        label_4->setText(QApplication::translate("retours", "temps", Q_NULLPTR));
        ajouter->setText(QApplication::translate("retours", "ajouter", Q_NULLPTR));
        modifierBtn->setText(QApplication::translate("retours", "modifier", Q_NULLPTR));
        label_11->setText(QApplication::translate("retours", "phone", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("retours", " ajout d'une station", Q_NULLPTR));
        lineEdit_recherche->setPlaceholderText(QApplication::translate("retours", "search...", Q_NULLPTR));
        generate_pdf->setText(QApplication::translate("retours", "pdf", Q_NULLPTR));
        deleteBtn->setText(QApplication::translate("retours", "Delete", Q_NULLPTR));
        qrcode->setText(QString());
        save->setText(QApplication::translate("retours", "save", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("retours", "afficher une station", Q_NULLPTR));
        chartview->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("retours", "Page", Q_NULLPTR));
        send->setText(QApplication::translate("retours", "send sms", Q_NULLPTR));
        phone->setPlaceholderText(QApplication::translate("retours", "phone number", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("retours", "sms", Q_NULLPTR));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class retours: public Ui_retours {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETOURS_H
