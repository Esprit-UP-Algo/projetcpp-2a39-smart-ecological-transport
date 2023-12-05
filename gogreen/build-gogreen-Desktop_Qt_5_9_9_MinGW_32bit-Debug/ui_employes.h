/********************************************************************************
** Form generated from reading UI file 'employes.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYES_H
#define UI_EMPLOYES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employes
{
public:
    QTabWidget *tabWidget;
    QWidget *AJOUTE;
    QGroupBox *groupBox_5;
    QLabel *ID_2;
    QLabel *label_25;
    QLabel *label_26;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_27;
    QLabel *label_28;
    QLineEdit *lineEdit_4;
    QDateEdit *dateEdit;
    QLabel *label_29;
    QPushButton *pushButton_ajouter;
    QComboBox *poste_p;
    QWidget *tab_6;
    QGroupBox *groupBox_6;
    QLabel *ID_3;
    QLabel *label_30;
    QLabel *label_31;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLabel *label_32;
    QLabel *label_33;
    QLineEdit *lineEdit_14;
    QDateEdit *dateEdit_3;
    QLabel *label_34;
    QPushButton *pushButton_modifier;
    QComboBox *POSTE_p;
    QWidget *tab_2;
    QTableView *tableView;
    QPushButton *recherche;
    QLineEdit *lineEdit_6;
    QPushButton *tri;
    QWidget *tab;
    QGroupBox *groupBox_7;
    QLabel *ID_4;
    QLineEdit *lineEdit_16;
    QPushButton *pushButton_supprimer;
    QWidget *tab_5;
    QWidget *tab_4;
    QLabel *label_4;
    QWidget *tab_3;
    QGroupBox *groupBox;
    QLabel *ID_5;
    QLineEdit *lineEdit_5;
    QDateEdit *dateEdit_2;
    QDateEdit *dateEdit_4;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tableView_2;
    QPushButton *confirmer;
    QPushButton *pushButton_2;
    QPushButton *pushButton_22;
    QPushButton *supp;
    QTableView *tableView_3;
    QPushButton *aff;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_5;

    void setupUi(QWidget *employes)
    {
        if (employes->objectName().isEmpty())
            employes->setObjectName(QStringLiteral("employes"));
        employes->resize(1060, 510);
        tabWidget = new QTabWidget(employes);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(160, 0, 901, 511));
        AJOUTE = new QWidget();
        AJOUTE->setObjectName(QStringLiteral("AJOUTE"));
        groupBox_5 = new QGroupBox(AJOUTE);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 20, 851, 421));
        ID_2 = new QLabel(groupBox_5);
        ID_2->setObjectName(QStringLiteral("ID_2"));
        ID_2->setGeometry(QRect(10, 40, 47, 13));
        label_25 = new QLabel(groupBox_5);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(10, 80, 47, 13));
        label_26 = new QLabel(groupBox_5);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(10, 120, 81, 16));
        lineEdit = new QLineEdit(groupBox_5);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 40, 113, 20));
        lineEdit_2 = new QLineEdit(groupBox_5);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 80, 113, 20));
        lineEdit_3 = new QLineEdit(groupBox_5);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 120, 113, 20));
        label_27 = new QLabel(groupBox_5);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(10, 190, 81, 16));
        label_28 = new QLabel(groupBox_5);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(10, 150, 81, 16));
        lineEdit_4 = new QLineEdit(groupBox_5);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(140, 150, 113, 20));
        dateEdit = new QDateEdit(groupBox_5);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(140, 190, 110, 22));
        label_29 = new QLabel(groupBox_5);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(10, 230, 81, 16));
        pushButton_ajouter = new QPushButton(groupBox_5);
        pushButton_ajouter->setObjectName(QStringLiteral("pushButton_ajouter"));
        pushButton_ajouter->setGeometry(QRect(260, 290, 75, 23));
        poste_p = new QComboBox(groupBox_5);
        poste_p->setObjectName(QStringLiteral("poste_p"));
        poste_p->setGeometry(QRect(120, 230, 181, 22));
        tabWidget->addTab(AJOUTE, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        groupBox_6 = new QGroupBox(tab_6);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 20, 831, 441));
        ID_3 = new QLabel(groupBox_6);
        ID_3->setObjectName(QStringLiteral("ID_3"));
        ID_3->setGeometry(QRect(10, 40, 47, 13));
        label_30 = new QLabel(groupBox_6);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(10, 80, 47, 13));
        label_31 = new QLabel(groupBox_6);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(10, 120, 81, 16));
        lineEdit_11 = new QLineEdit(groupBox_6);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(140, 40, 113, 20));
        lineEdit_12 = new QLineEdit(groupBox_6);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(140, 80, 113, 20));
        lineEdit_13 = new QLineEdit(groupBox_6);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(140, 120, 113, 20));
        label_32 = new QLabel(groupBox_6);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(10, 190, 81, 16));
        label_33 = new QLabel(groupBox_6);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(10, 150, 81, 16));
        lineEdit_14 = new QLineEdit(groupBox_6);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(140, 150, 113, 20));
        dateEdit_3 = new QDateEdit(groupBox_6);
        dateEdit_3->setObjectName(QStringLiteral("dateEdit_3"));
        dateEdit_3->setGeometry(QRect(140, 190, 110, 22));
        label_34 = new QLabel(groupBox_6);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(10, 230, 81, 16));
        pushButton_modifier = new QPushButton(groupBox_6);
        pushButton_modifier->setObjectName(QStringLiteral("pushButton_modifier"));
        pushButton_modifier->setGeometry(QRect(260, 290, 75, 23));
        POSTE_p = new QComboBox(groupBox_6);
        POSTE_p->setObjectName(QStringLiteral("POSTE_p"));
        POSTE_p->setGeometry(QRect(140, 230, 111, 22));
        tabWidget->addTab(tab_6, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableView = new QTableView(tab_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(25, 11, 831, 361));
        recherche = new QPushButton(tab_2);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(460, 400, 93, 28));
        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(560, 400, 113, 22));
        tri = new QPushButton(tab_2);
        tri->setObjectName(QStringLiteral("tri"));
        tri->setGeometry(QRect(130, 410, 93, 28));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(30, 30, 641, 421));
        ID_4 = new QLabel(groupBox_7);
        ID_4->setObjectName(QStringLiteral("ID_4"));
        ID_4->setGeometry(QRect(150, 120, 47, 13));
        lineEdit_16 = new QLineEdit(groupBox_7);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setGeometry(QRect(200, 120, 113, 20));
        pushButton_supprimer = new QPushButton(groupBox_7);
        pushButton_supprimer->setObjectName(QStringLiteral("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(300, 190, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 10, 701, 411));
        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 251, 211));
        ID_5 = new QLabel(groupBox);
        ID_5->setObjectName(QStringLiteral("ID_5"));
        ID_5->setGeometry(QRect(30, 30, 47, 13));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(90, 30, 113, 22));
        dateEdit_2 = new QDateEdit(groupBox);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(90, 70, 110, 22));
        dateEdit_4 = new QDateEdit(groupBox);
        dateEdit_4->setObjectName(QStringLiteral("dateEdit_4"));
        dateEdit_4->setGeometry(QRect(90, 110, 110, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 71, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(5, 110, 71, 20));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 160, 93, 28));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(130, 160, 93, 28));
        tableView_2 = new QTableView(tab_3);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(310, 10, 561, 261));
        confirmer = new QPushButton(tab_3);
        confirmer->setObjectName(QStringLiteral("confirmer"));
        confirmer->setGeometry(QRect(30, 260, 93, 28));
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 260, 93, 28));
        pushButton_22 = new QPushButton(tab_3);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(160, 310, 93, 28));
        supp = new QPushButton(tab_3);
        supp->setObjectName(QStringLiteral("supp"));
        supp->setGeometry(QRect(40, 310, 93, 28));
        tableView_3 = new QTableView(tab_3);
        tableView_3->setObjectName(QStringLiteral("tableView_3"));
        tableView_3->setGeometry(QRect(320, 280, 551, 192));
        aff = new QPushButton(tab_3);
        aff->setObjectName(QStringLiteral("aff"));
        aff->setGeometry(QRect(50, 380, 241, 28));
        tabWidget->addTab(tab_3, QString());
        verticalLayoutWidget = new QWidget(employes);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 169, 491));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Bureau/login.png")));

        verticalLayout->addWidget(label);

        label_5 = new QLabel(employes);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 250, 167, 489));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../Bureau/login.png")));

        retranslateUi(employes);

        tabWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(employes);
    } // setupUi

    void retranslateUi(QWidget *employes)
    {
        employes->setWindowTitle(QApplication::translate("employes", "Form", Q_NULLPTR));
        groupBox_5->setTitle(QString());
        ID_2->setText(QApplication::translate("employes", "ID", Q_NULLPTR));
        label_25->setText(QApplication::translate("employes", "NOM", Q_NULLPTR));
        label_26->setText(QApplication::translate("employes", "PRENOM", Q_NULLPTR));
        label_27->setText(QApplication::translate("employes", "DATE", Q_NULLPTR));
        label_28->setText(QApplication::translate("employes", "SALAIRE", Q_NULLPTR));
        label_29->setText(QApplication::translate("employes", "POSTE", Q_NULLPTR));
        pushButton_ajouter->setText(QApplication::translate("employes", "Ajouter", Q_NULLPTR));
        poste_p->clear();
        poste_p->insertItems(0, QStringList()
         << QApplication::translate("employes", "Reducateur Technique", Q_NULLPTR)
         << QApplication::translate("employes", "Conducteur", Q_NULLPTR)
         << QApplication::translate("employes", "controleur technique", Q_NULLPTR)
         << QApplication::translate("employes", "Inspecteur Qualite", Q_NULLPTR)
         << QApplication::translate("employes", "RH", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(AJOUTE), QApplication::translate("employes", "AJOUTER EMPLOYE", Q_NULLPTR));
        groupBox_6->setTitle(QString());
        ID_3->setText(QApplication::translate("employes", "ID", Q_NULLPTR));
        label_30->setText(QApplication::translate("employes", "NOM", Q_NULLPTR));
        label_31->setText(QApplication::translate("employes", "PRENOM", Q_NULLPTR));
        label_32->setText(QApplication::translate("employes", "DATE", Q_NULLPTR));
        label_33->setText(QApplication::translate("employes", "SALAIRE", Q_NULLPTR));
        label_34->setText(QApplication::translate("employes", "POSTE", Q_NULLPTR));
        pushButton_modifier->setText(QApplication::translate("employes", "Modifier", Q_NULLPTR));
        POSTE_p->clear();
        POSTE_p->insertItems(0, QStringList()
         << QApplication::translate("employes", "chef", Q_NULLPTR)
         << QApplication::translate("employes", "RS", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("employes", "MODIFIER", Q_NULLPTR));
        recherche->setText(QApplication::translate("employes", "Recherche", Q_NULLPTR));
        tri->setText(QApplication::translate("employes", "TRI", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("employes", "CONSULTER LA LISTE", Q_NULLPTR));
        groupBox_7->setTitle(QString());
        ID_4->setText(QApplication::translate("employes", "ID", Q_NULLPTR));
        pushButton_supprimer->setText(QApplication::translate("employes", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("employes", "ELIMINER UN EMPLOYE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("employes", "Page", Q_NULLPTR));
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("employes", "stats", Q_NULLPTR));
        groupBox->setTitle(QString());
        ID_5->setText(QApplication::translate("employes", "ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("employes", "Date debut", Q_NULLPTR));
        label_3->setText(QApplication::translate("employes", "Date retour", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("employes", "ajouter", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("employes", "annuler", Q_NULLPTR));
        confirmer->setText(QApplication::translate("employes", "confirmer", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("employes", "refuser", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("employes", "imprimer", Q_NULLPTR));
        supp->setText(QApplication::translate("employes", "supprimer", Q_NULLPTR));
        aff->setText(QApplication::translate("employes", "afficher les informations des employes", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("employes", "CONGES", Q_NULLPTR));
        label->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class employes: public Ui_employes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYES_H
