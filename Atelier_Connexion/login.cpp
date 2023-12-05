#include "login.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include"mainwindow.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(1000, 500);
    setupUI();
    setupConnections();
     setStyleSheet( "background-color: white; ");
}

Login::~Login() {
    delete mainLayout; // Ensure proper resource handling
}

void Login::setupUI() {
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(50, 50, 50, 50); // Add margins for better spacing

    // Logo
    QLabel *backgroundLabel = new QLabel(this);
    QPixmap backgroundImage("C:/Users/MICRO-PC/OneDrive/Bureau/logo.png");
    backgroundLabel->setPixmap(backgroundImage.scaled(300, 300));
    backgroundLabel->setAlignment(Qt::AlignTop |Qt::AlignCenter);
    mainLayout->addWidget(backgroundLabel);

    // Title
    title = new QLabel("Bonjour,Identifiez-vous!", this);
    title->setAlignment(Qt::AlignCenter);
    title->setFont(QFont("Calibri", 13));

    mainLayout->addWidget(title);

    // Login and Password fields
    userLabel = new QLabel("Login:", this);
    userLabel->setAlignment(Qt::AlignLeft); // Align left for labels
    userLabel->setFont(QFont("Times New Roman", 13));
    mainLayout->addWidget(userLabel);

    userLineEdit = new QLineEdit(this);
    userLineEdit->setPlaceholderText("Enter your login");
    mainLayout->addWidget(userLineEdit);

    passwordLabel = new QLabel("Password:", this);
    passwordLabel->setAlignment(Qt::AlignLeft); // Align left for labels
    passwordLabel->setFont(QFont("Times New Roman", 13));
    mainLayout->addWidget(passwordLabel);

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Enter your password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    mainLayout->addWidget(passwordLineEdit);


    // Login button
    loginButton = new QPushButton("Login", this);
    loginButton->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 10px; } QPushButton:hover { background-color: #45a049; }"); // Customizing button appearance
    loginButton->setFont(QFont("Arial", 16));
    mainLayout->addWidget(loginButton);

    setLayout(mainLayout);
}


void Login::setupConnections() {
    connect(loginButton, &QPushButton::clicked, this, &Login::attemptLogin);
}

void Login::attemptLogin() {

    QString username = userLineEdit->text();
    QString password = passwordLineEdit->text();
 QSqlQuery query;
    query.prepare("SELECT ID, NOM FROM EMPLOYE WHERE   ID = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {

        // Simulate successful login for demonstration purposes
        QMessageBox::information(this, "Login Successful", "Welcome, " + username);

        // Create and show the LoggedInWidget upon successful login
        MainWindow *loggedInWidget = new  MainWindow ;
        loggedInWidget->show();

        // Hide the current widget (MyApp)
        this->hide();
    } else {
        QMessageBox::warning(this, "Error", "password or login is incorrect");
    }}

