/********************************************************************************
** Form generated from reading UI file 'gogreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOGREEN_H
#define UI_GOGREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gogreen
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_17;

    void setupUi(QMainWindow *gogreen)
    {
        if (gogreen->objectName().isEmpty())
            gogreen->setObjectName(QStringLiteral("gogreen"));
        gogreen->resize(1017, 600);
        centralwidget = new QWidget(gogreen);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 0, 16));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(880, 20, 93, 28));
        pushButton_17 = new QPushButton(centralwidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(50, 340, 121, 41));
        QFont font;
        font.setPointSize(20);
        pushButton_17->setFont(font);
        pushButton_17->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../se-deconnecter.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon);
        pushButton_17->setIconSize(QSize(30, 30));
        gogreen->setCentralWidget(centralwidget);

        retranslateUi(gogreen);

        QMetaObject::connectSlotsByName(gogreen);
    } // setupUi

    void retranslateUi(QMainWindow *gogreen)
    {
        gogreen->setWindowTitle(QApplication::translate("gogreen", "gogreen", Q_NULLPTR));
        label->setText(QString());
        pushButton->setText(QApplication::translate("gogreen", "LOGIN", Q_NULLPTR));
        pushButton_17->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gogreen: public Ui_gogreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOGREEN_H
