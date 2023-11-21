#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

signals:
    void loginSuccessful();

private slots:
    void attemptLogin();

private:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;

    // You can add other necessary private members or methods here
};

#endif // LOGIN_H
