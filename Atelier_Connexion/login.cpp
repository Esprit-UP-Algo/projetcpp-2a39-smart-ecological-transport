#include "Login.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

Login::Login(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Login");

    QLabel *usernameLabel = new QLabel("Username:");
    QLabel *passwordLabel = new QLabel("Password:");

    usernameLineEdit = new QLineEdit;
    passwordLineEdit = new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameLineEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(loginButton);

    setLayout(layout);

    connect(loginButton, SIGNAL(clicked()), this, SLOT(attemptLogin()));
}

void Login::attemptLogin()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT ID, NOM FROM EMPLOYE WHERE ID = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        // Login successful
        emit loginSuccessful();
        accept(); // Close the login window
    } else {
        // Login failed
        QMessageBox::critical(this, "Login Failed", "Invalid username or password. Please try again.");
    }
}

