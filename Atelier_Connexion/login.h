#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>


class Login : public QWidget
{
    Q_OBJECT

public:
   Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void attemptLogin();

private:
    QVBoxLayout *mainLayout;
    QLabel *title;
    QLabel *userLabel;
    QLabel *passwordLabel; // New label for password
    QLineEdit *userLineEdit;
    QLineEdit *passwordLineEdit; // New line edit for password
    QPushButton *loginButton;

    void setupUI();
    void setupConnections();
    bool authenticateUser(const QString& username, const QString& password);
};

#endif // LOGIN_H
