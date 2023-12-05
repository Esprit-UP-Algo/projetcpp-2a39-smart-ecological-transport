#ifndef POPUP_H
#define POPUP_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPropertyAnimation>
#include <QTimer>

class PopUp : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(float popupOpacity READ getPopupOpacity WRITE setPopupOpacity)

protected:
    void paintEvent(QPaintEvent *event) override;

public:
    explicit PopUp(QWidget *parent = nullptr);

    // ... other declarations

public slots:
    void setPopupText(const QString& text);
    void show();
    void hideAnimation();
    void hide();
    void showWithoutAnimation();
private:
    QLabel label;
    QGridLayout layout;
    QPropertyAnimation animation;
    float popupOpacity;
    QTimer *timer;
    void onAnimationFinished();
    float getPopupOpacity() const;
    void setPopupOpacity(float opacity);
};

#endif // POPUP_H
