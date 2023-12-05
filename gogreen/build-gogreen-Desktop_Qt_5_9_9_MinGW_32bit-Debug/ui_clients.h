/********************************************************************************
** Form generated from reading UI file 'clients.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTS_H
#define UI_CLIENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clients
{
public:
    QTabWidget *afficher;
    QWidget *tab;
    QWidget *tab_3;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLabel *label_36;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_37;
    QPushButton *pushButton_6;
    QPushButton *pushButton_pdf_2;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_qr;
    QWidget *modifieranimal;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QPushButton *pushButton_modifier;
    QLabel *label_12;
    QTableView *tableView;
    QWidget *tab_2;
    QLabel *label_18;
    QLineEdit *lineEdit_15;
    QPushButton *pushButton_supprimer;
    QLabel *label_20;
    QTableView *tableView_1;
    QWidget *tab_4;
    QTableView *tableView_2;
    QLabel *label_5;
    QLineEdit *rechercheID;
    QPushButton *Trie_botton;
    QPushButton *Trie_botto;
    QLabel *label_6;

    void setupUi(QWidget *clients)
    {
        if (clients->objectName().isEmpty())
            clients->setObjectName(QStringLiteral("clients"));
        clients->resize(1101, 511);
        afficher = new QTabWidget(clients);
        afficher->setObjectName(QStringLiteral("afficher"));
        afficher->setGeometry(QRect(170, 0, 931, 511));
        afficher->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        afficher->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        lineEdit_5 = new QLineEdit(tab_3);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(220, 420, 231, 31));
        lineEdit_3 = new QLineEdit(tab_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(220, 270, 231, 31));
        lineEdit_2 = new QLineEdit(tab_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(220, 190, 221, 31));
        label_36 = new QLabel(tab_3);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(50, 400, 111, 51));
        QFont font;
        font.setPointSize(20);
        label_36->setFont(font);
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 0, 431, 81));
        QFont font1;
        font1.setPointSize(40);
        label->setFont(font1);
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(220, 110, 221, 31));
        lineEdit_4 = new QLineEdit(tab_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(220, 350, 231, 31));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 260, 111, 41));
        label_4->setFont(font);
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 100, 121, 41));
        label_2->setFont(font);
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 190, 151, 41));
        QFont font2;
        font2.setPointSize(21);
        label_3->setFont(font2);
        label_37 = new QLabel(tab_3);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(70, 340, 71, 41));
        label_37->setFont(font);
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(530, 230, 93, 28));
        pushButton_pdf_2 = new QPushButton(tab_3);
        pushButton_pdf_2->setObjectName(QStringLiteral("pushButton_pdf_2"));
        pushButton_pdf_2->setGeometry(QRect(620, 380, 93, 51));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../fichier-pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_pdf_2->setIcon(icon);
        pushButton_pdf_2->setIconSize(QSize(30, 30));
        lineEdit_6 = new QLineEdit(tab_3);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(590, 320, 113, 22));
        pushButton_qr = new QPushButton(tab_3);
        pushButton_qr->setObjectName(QStringLiteral("pushButton_qr"));
        pushButton_qr->setGeometry(QRect(670, 100, 151, 121));
        afficher->addTab(tab_3, QString());
        modifieranimal = new QWidget();
        modifieranimal->setObjectName(QStringLiteral("modifieranimal"));
        label_13 = new QLabel(modifieranimal);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 110, 221, 16));
        QFont font3;
        font3.setPointSize(12);
        label_13->setFont(font3);
        label_14 = new QLabel(modifieranimal);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(40, 160, 91, 31));
        label_14->setFont(font3);
        label_15 = new QLabel(modifieranimal);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(40, 230, 131, 16));
        label_15->setFont(font3);
        label_16 = new QLabel(modifieranimal);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(40, 290, 121, 31));
        QFont font4;
        font4.setPointSize(11);
        label_16->setFont(font4);
        label_17 = new QLabel(modifieranimal);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(40, 360, 121, 21));
        label_17->setFont(font4);
        lineEdit_10 = new QLineEdit(modifieranimal);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(190, 110, 151, 22));
        lineEdit_10->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_11 = new QLineEdit(modifieranimal);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(190, 160, 151, 22));
        lineEdit_11->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_12 = new QLineEdit(modifieranimal);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(190, 230, 151, 22));
        lineEdit_12->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_13 = new QLineEdit(modifieranimal);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(190, 290, 151, 22));
        lineEdit_13->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_14 = new QLineEdit(modifieranimal);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(190, 360, 151, 22));
        lineEdit_14->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_modifier = new QPushButton(modifieranimal);
        pushButton_modifier->setObjectName(QStringLiteral("pushButton_modifier"));
        pushButton_modifier->setGeometry(QRect(220, 420, 93, 28));
        label_12 = new QLabel(modifieranimal);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(150, 30, 461, 41));
        QFont font5;
        font5.setPointSize(25);
        label_12->setFont(font5);
        tableView = new QTableView(modifieranimal);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(400, 90, 501, 371));
        afficher->addTab(modifieranimal, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(110, 90, 191, 16));
        label_18->setFont(font3);
        lineEdit_15 = new QLineEdit(tab_2);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        lineEdit_15->setGeometry(QRect(320, 90, 113, 22));
        lineEdit_15->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_supprimer = new QPushButton(tab_2);
        pushButton_supprimer->setObjectName(QStringLiteral("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(980, 500, 121, 31));
        pushButton_supprimer->setFont(font4);
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(100, 10, 521, 51));
        label_20->setFont(font5);
        tableView_1 = new QTableView(tab_2);
        tableView_1->setObjectName(QStringLiteral("tableView_1"));
        tableView_1->setGeometry(QRect(60, 160, 631, 241));
        afficher->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tableView_2 = new QTableView(tab_4);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(20, 100, 891, 351));
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(140, 10, 731, 51));
        QFont font6;
        font6.setPointSize(30);
        label_5->setFont(font6);
        rechercheID = new QLineEdit(tab_4);
        rechercheID->setObjectName(QStringLiteral("rechercheID"));
        rechercheID->setGeometry(QRect(972, 81, 121, 31));
        Trie_botton = new QPushButton(tab_4);
        Trie_botton->setObjectName(QStringLiteral("Trie_botton"));
        Trie_botton->setGeometry(QRect(10, 10, 93, 28));
        Trie_botto = new QPushButton(tab_4);
        Trie_botto->setObjectName(QStringLiteral("Trie_botto"));
        Trie_botto->setGeometry(QRect(10, 60, 93, 28));
        afficher->addTab(tab_4, QString());
        label_6 = new QLabel(clients);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, -60, 171, 651));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../../Bureau/login.png")));

        retranslateUi(clients);

        afficher->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(clients);
    } // setupUi

    void retranslateUi(QWidget *clients)
    {
        clients->setWindowTitle(QApplication::translate("clients", "Form", Q_NULLPTR));
        afficher->setTabText(afficher->indexOf(tab), QApplication::translate("clients", "Tab 1", Q_NULLPTR));
        label_36->setText(QApplication::translate("clients", "permis", Q_NULLPTR));
        label->setText(QApplication::translate("clients", "gestion client ", Q_NULLPTR));
        label_4->setText(QApplication::translate("clients", "email", Q_NULLPTR));
        label_2->setText(QApplication::translate("clients", "nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("clients", " prenom", Q_NULLPTR));
        label_37->setText(QApplication::translate("clients", " id", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("clients", "ajouter", Q_NULLPTR));
        pushButton_pdf_2->setText(QApplication::translate("clients", "IMPRIMER", Q_NULLPTR));
        pushButton_qr->setText(QString());
        afficher->setTabText(afficher->indexOf(tab_3), QApplication::translate("clients", "Ajouter un client", Q_NULLPTR));
        label_13->setText(QApplication::translate("clients", "nom", Q_NULLPTR));
        label_14->setText(QApplication::translate("clients", "prenom", Q_NULLPTR));
        label_15->setText(QApplication::translate("clients", "mail", Q_NULLPTR));
        label_16->setText(QApplication::translate("clients", "id", Q_NULLPTR));
        label_17->setText(QApplication::translate("clients", "permis", Q_NULLPTR));
        pushButton_modifier->setText(QApplication::translate("clients", "modifier", Q_NULLPTR));
        label_12->setText(QApplication::translate("clients", "    Modifier un client", Q_NULLPTR));
        afficher->setTabText(afficher->indexOf(modifieranimal), QApplication::translate("clients", "Modifier client", Q_NULLPTR));
        label_18->setText(QApplication::translate("clients", " Donner l\342\200\231Identifiant", Q_NULLPTR));
        pushButton_supprimer->setText(QApplication::translate("clients", "suprimer", Q_NULLPTR));
        label_20->setText(QApplication::translate("clients", "    Supprimer un client", Q_NULLPTR));
        afficher->setTabText(afficher->indexOf(tab_2), QApplication::translate("clients", "Supprimer un client", Q_NULLPTR));
        label_5->setText(QApplication::translate("clients", "AFFICHAGE LISTE DES CLIENTS ", Q_NULLPTR));
        Trie_botton->setText(QApplication::translate("clients", "trie down", Q_NULLPTR));
        Trie_botto->setText(QApplication::translate("clients", "trie up", Q_NULLPTR));
        afficher->setTabText(afficher->indexOf(tab_4), QApplication::translate("clients", "affichage", Q_NULLPTR));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class clients: public Ui_clients {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTS_H
