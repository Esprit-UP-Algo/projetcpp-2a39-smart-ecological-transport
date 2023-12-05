/********************************************************************************
** Form generated from reading UI file 'Vehicule.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEHICULE_H
#define UI_VEHICULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Vehicule
{
public:
    QStackedWidget *Modifie;
    QWidget *ModifiePage1;
    QComboBox *marq;
    QPushButton *supp;
    QLabel *label_9;
    QLabel *label_15;
    QTableView *tab_v_3;
    QLabel *label_12;
    QLineEdit *imm;
    QLabel *label_13;
    QComboBox *pui;
    QLabel *label_14;
    QPushButton *ajout;
    QLabel *label_8;
    QLabel *label_11;
    QComboBox *comboBox;
    QComboBox *ty;
    QLineEdit *ref;
    QTableView *tab_v;
    QLabel *label_10;
    QComboBox *mode;
    QLineEdit *ch;
    QPushButton *pushButton_3;
    QLabel *label_16;
    QPushButton *modifier;
    QLabel *chartview;
    QWidget *ModifiePage2;
    QFrame *frame;
    QPushButton *pushButton_18;
    QLabel *label_2;
    QPushButton *pushButton_19;
    QLabel *label_3;
    QPushButton *pushButton_6;
    QLabel *label_4;
    QPushButton *pushButton_9;
    QLabel *label_5;
    QPushButton *pushButton_14;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;

    void setupUi(QWidget *Vehicule)
    {
        if (Vehicule->objectName().isEmpty())
            Vehicule->setObjectName(QStringLiteral("Vehicule"));
        Vehicule->resize(1313, 628);
        Modifie = new QStackedWidget(Vehicule);
        Modifie->setObjectName(QStringLiteral("Modifie"));
        Modifie->setGeometry(QRect(180, 0, 1221, 711));
        Modifie->setStyleSheet(QStringLiteral("Modifier"));
        ModifiePage1 = new QWidget();
        ModifiePage1->setObjectName(QStringLiteral("ModifiePage1"));
        marq = new QComboBox(ModifiePage1);
        marq->setObjectName(QStringLiteral("marq"));
        marq->setGeometry(QRect(300, 110, 121, 21));
        supp = new QPushButton(ModifiePage1);
        supp->setObjectName(QStringLiteral("supp"));
        supp->setGeometry(QRect(280, 400, 71, 21));
        label_9 = new QLabel(ModifiePage1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(330, 70, 51, 31));
        label_15 = new QLabel(ModifiePage1);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(180, 350, 101, 31));
        tab_v_3 = new QTableView(ModifiePage1);
        tab_v_3->setObjectName(QStringLiteral("tab_v_3"));
        tab_v_3->setGeometry(QRect(570, 430, 651, 271));
        label_12 = new QLabel(ModifiePage1);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(310, 150, 71, 31));
        imm = new QLineEdit(ModifiePage1);
        imm->setObjectName(QStringLiteral("imm"));
        imm->setGeometry(QRect(60, 120, 101, 21));
        label_13 = new QLabel(ModifiePage1);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(310, 230, 61, 31));
        pui = new QComboBox(ModifiePage1);
        pui->setObjectName(QStringLiteral("pui"));
        pui->setGeometry(QRect(60, 200, 111, 21));
        label_14 = new QLabel(ModifiePage1);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(70, 70, 61, 31));
        ajout = new QPushButton(ModifiePage1);
        ajout->setObjectName(QStringLiteral("ajout"));
        ajout->setGeometry(QRect(120, 300, 81, 31));
        label_8 = new QLabel(ModifiePage1);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(180, 40, 101, 31));
        label_11 = new QLabel(ModifiePage1);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(70, 150, 61, 31));
        comboBox = new QComboBox(ModifiePage1);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(370, 400, 101, 21));
        comboBox->setStyleSheet(QStringLiteral(""));
        ty = new QComboBox(ModifiePage1);
        ty->setObjectName(QStringLiteral("ty"));
        ty->setGeometry(QRect(300, 201, 121, 20));
        ref = new QLineEdit(ModifiePage1);
        ref->setObjectName(QStringLiteral("ref"));
        ref->setGeometry(QRect(290, 270, 131, 21));
        tab_v = new QTableView(ModifiePage1);
        tab_v->setObjectName(QStringLiteral("tab_v"));
        tab_v->setGeometry(QRect(10, 430, 541, 271));
        tab_v->setSelectionBehavior(QAbstractItemView::SelectRows);
        label_10 = new QLabel(ModifiePage1);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(70, 230, 51, 31));
        mode = new QComboBox(ModifiePage1);
        mode->setObjectName(QStringLiteral("mode"));
        mode->setGeometry(QRect(60, 270, 101, 21));
        ch = new QLineEdit(ModifiePage1);
        ch->setObjectName(QStringLiteral("ch"));
        ch->setGeometry(QRect(20, 400, 101, 16));
        pushButton_3 = new QPushButton(ModifiePage1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 400, 61, 21));
        pushButton_3->setStyleSheet(QStringLiteral(""));
        label_16 = new QLabel(ModifiePage1);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(840, 380, 101, 31));
        modifier = new QPushButton(ModifiePage1);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(250, 300, 91, 31));
        chartview = new QLabel(ModifiePage1);
        chartview->setObjectName(QStringLiteral("chartview"));
        chartview->setGeometry(QRect(550, 30, 661, 321));
        Modifie->addWidget(ModifiePage1);
        ModifiePage2 = new QWidget();
        ModifiePage2->setObjectName(QStringLiteral("ModifiePage2"));
        Modifie->addWidget(ModifiePage2);
        frame = new QFrame(Vehicule);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-60, -20, 231, 731));
        frame->setStyleSheet(QStringLiteral("background-color: rgb(20, 166, 88);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_18 = new QPushButton(frame);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(20, 100, 61, 61));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Downloads/IMG_1867.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon);
        pushButton_18->setIconSize(QSize(50, 50));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 120, 91, 31));
        QFont font;
        font.setPointSize(11);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton_19 = new QPushButton(frame);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(-10, 180, 251, 61));
        pushButton_19->setStyleSheet(QStringLiteral("background:white;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../Downloads/IMG_1864.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon1);
        pushButton_19->setIconSize(QSize(50, 50));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 200, 61, 21));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("background:transparent;"));
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 260, 61, 61));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../Downloads/IMG_1865.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon2);
        pushButton_6->setIconSize(QSize(50, 50));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 280, 71, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background:transparent;"));
        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(20, 340, 61, 61));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../Downloads/IMG_1866.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon3);
        pushButton_9->setIconSize(QSize(50, 50));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 360, 101, 31));
        label_5->setFont(font);
        label_5->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background:transparent;"));
        pushButton_14 = new QPushButton(frame);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(20, 420, 61, 61));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../../../Downloads/IMG_1862.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon4);
        pushButton_14->setIconSize(QSize(50, 50));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 450, 101, 20));
        label_6->setFont(font);
        label_6->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background:transparent;"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 530, 81, 16));
        label_7->setFont(font);
        label_7->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background:transparent;"));
        pushButton_20 = new QPushButton(frame);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(20, 500, 61, 61));
        pushButton_20->setStyleSheet(QStringLiteral(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../Downloads/Capture d'\303\251cran 2023-10-08 155058.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_20->setIcon(icon5);
        pushButton_20->setIconSize(QSize(50, 50));
        pushButton_21 = new QPushButton(frame);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(70, 650, 81, 41));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../Downloads/Capture d'\303\251cran 2023-10-08 141340.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_21->setIcon(icon6);
        pushButton_21->setIconSize(QSize(80, 80));

        retranslateUi(Vehicule);

        Modifie->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Vehicule);
    } // setupUi

    void retranslateUi(QWidget *Vehicule)
    {
        Vehicule->setWindowTitle(QApplication::translate("Vehicule", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Modifie->setToolTip(QApplication::translate("Vehicule", "<html><head/><body><p>Modifier</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        marq->clear();
        marq->insertItems(0, QStringList()
         << QApplication::translate("Vehicule", "Bmw", Q_NULLPTR)
         << QApplication::translate("Vehicule", "Mercedes", Q_NULLPTR)
         << QApplication::translate("Vehicule", "Tesla", Q_NULLPTR)
         << QApplication::translate("Vehicule", "Kia", Q_NULLPTR)
         << QApplication::translate("Vehicule", "Ford", Q_NULLPTR)
        );
        supp->setText(QApplication::translate("Vehicule", "Supprimer", Q_NULLPTR));
        label_9->setText(QApplication::translate("Vehicule", "Marque", Q_NULLPTR));
        label_15->setText(QApplication::translate("Vehicule", "Liste de Matricule", Q_NULLPTR));
        label_12->setText(QApplication::translate("Vehicule", "type_charge", Q_NULLPTR));
        label_13->setText(QApplication::translate("Vehicule", "Reference", Q_NULLPTR));
        pui->clear();
        pui->insertItems(0, QStringList()
         << QApplication::translate("Vehicule", "25CH", Q_NULLPTR)
         << QApplication::translate("Vehicule", "400CH", Q_NULLPTR)
         << QApplication::translate("Vehicule", "6CH", Q_NULLPTR)
        );
        label_14->setText(QApplication::translate("Vehicule", "immatricule", Q_NULLPTR));
        ajout->setText(QApplication::translate("Vehicule", "Ajouter", Q_NULLPTR));
        label_8->setText(QApplication::translate("Vehicule", "Ajout De Matricule", Q_NULLPTR));
        label_11->setText(QApplication::translate("Vehicule", "puissance", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Vehicule", "tri par marque", Q_NULLPTR)
         << QApplication::translate("Vehicule", "Croissant", Q_NULLPTR)
         << QApplication::translate("Vehicule", "D\303\251croissant", Q_NULLPTR)
        );
        ty->clear();
        ty->insertItems(0, QStringList()
         << QApplication::translate("Vehicule", "Electrique", Q_NULLPTR)
         << QApplication::translate("Vehicule", "Solaire", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("Vehicule", "Modele", Q_NULLPTR));
        mode->clear();
        mode->insertItems(0, QStringList()
         << QApplication::translate("Vehicule", "S\303\251rie1", Q_NULLPTR)
         << QApplication::translate("Vehicule", "CLA", Q_NULLPTR)
         << QApplication::translate("Vehicule", "Fiesta", Q_NULLPTR)
        );
        pushButton_3->setText(QApplication::translate("Vehicule", "imprimer", Q_NULLPTR));
        label_16->setText(QApplication::translate("Vehicule", "Histoirque", Q_NULLPTR));
        modifier->setText(QApplication::translate("Vehicule", "Modifier", Q_NULLPTR));
        chartview->setText(QString());
        pushButton_18->setText(QString());
        label_2->setText(QApplication::translate("Vehicule", "Accueil", Q_NULLPTR));
        pushButton_19->setText(QString());
        label_3->setText(QApplication::translate("Vehicule", "V\303\251hicule", Q_NULLPTR));
        pushButton_6->setText(QString());
        label_4->setText(QApplication::translate("Vehicule", "Client", Q_NULLPTR));
        pushButton_9->setText(QString());
        label_5->setText(QApplication::translate("Vehicule", "R\303\251servation", Q_NULLPTR));
        pushButton_14->setText(QString());
        label_6->setText(QApplication::translate("Vehicule", "Recharge", Q_NULLPTR));
        label_7->setText(QApplication::translate("Vehicule", "Employ\303\251s", Q_NULLPTR));
        pushButton_20->setText(QString());
        pushButton_21->setText(QApplication::translate("Vehicule", "QUIT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Vehicule: public Ui_Vehicule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEHICULE_H
