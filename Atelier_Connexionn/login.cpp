#include "login.h"
#include"ui_login.h"
#include <QMessageBox>


Login::Login(QWidget *parent) : QWidget(parent) {

    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Username");

    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Password");
    passwordEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &Login::attemptLogin);
}

void Login::attemptLogin() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    // Check the credentials (you may replace this with your own logic)
    if (username == "admin" && password == "admin") {
        emit loginSuccessful();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password");
    }
}
