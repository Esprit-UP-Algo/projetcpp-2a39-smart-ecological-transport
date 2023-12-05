#include "popup.h"
#include <QPainter>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

PopUp::PopUp(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint |
                   Qt::Tool |
                   Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);

    animation.setTargetObject(this);
    animation.setPropertyName("popupOpacity");
    connect(&animation, &QAbstractAnimation::finished, this, &PopUp::onAnimationFinished);  // Add this line

    label.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label.setStyleSheet("QLabel { color : white; "
                        "margin-top: 6px;"
                        "margin-bottom: 6px;"
                        "margin-left: 10px;"
                        "margin-right: 10px; }");

    layout.addWidget(&label, 0, 0);
    setLayout(&layout);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &PopUp::hideAnimation);
}



void PopUp::paintEvent(QPaintEvent *event)
{
    qDebug() << "Paint event triggered!";
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Add a background color for visibility
    painter.fillRect(rect(), Qt::red);

    QRect roundedRect;
    roundedRect.setX(rect().x() + 5);
    roundedRect.setY(rect().y() + 5);
    roundedRect.setWidth(rect().width() - 10);
    roundedRect.setHeight(rect().height() - 10);

    painter.setBrush(QBrush(QColor(0, 0, 0, 180)));
    painter.setPen(Qt::NoPen);

    painter.drawRoundedRect(roundedRect, 10, 10);
}



void PopUp::setPopupText(const QString &text)
{
    qDebug() << "Setting Popup text:" << text;
    label.setText(text);
    adjustSize();
    setMinimumSize(100, 50);
}


void PopUp::show()
{
    qDebug() << "Popup show function called!";
    setWindowOpacity(1.0);

    setGeometry(QApplication::desktop()->availableGeometry().width() - 36 - width() + QApplication::desktop()->availableGeometry().x(),
                QApplication::desktop()->availableGeometry().height() - 36 - height() + QApplication::desktop()->availableGeometry().y(),
                width(),
                height());

    qDebug() << "Popup Geometry:" << geometry();

    raise();
    activateWindow();
    QWidget::show();
}


void PopUp::hideAnimation()
{
    qDebug() << "Hide animation triggered!";
    timer->stop();
    animation.setDuration(1000);
    animation.setStartValue(1.0);
    animation.setEndValue(0.0);
    animation.start();
}

void PopUp::hide()
{
    if (getPopupOpacity() == 0.0) {
        QWidget::hide();
    }
}

void PopUp::setPopupOpacity(float opacity)
{
    popupOpacity = opacity;
    setWindowOpacity(opacity);
}

float PopUp::getPopupOpacity() const
{
    return popupOpacity;
}
void PopUp::onAnimationFinished()
{
    qDebug() << "Animation Finished";
}


void PopUp::showWithoutAnimation()
{
    setWindowOpacity(1.0);

    QRect desktopRect = QApplication::desktop()->availableGeometry();
    int x = desktopRect.width() - width() - 36 + desktopRect.x();
    int y = desktopRect.height() - height() - 36 + desktopRect.y();
    setGeometry(x, y, width(), height());

    qDebug() << "Popup Geometry:" << geometry();

    raise();
    setParent(QApplication::activeWindow());  // Set the parent widget
    setAttribute(Qt::WA_ShowWithoutActivating, true);
    QWidget::show();
}






