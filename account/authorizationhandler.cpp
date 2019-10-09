#include "authorizationhandler.h"
#include "account.h"
#include <QDebug>

AuthorizationHandler::AuthorizationHandler()
{
    name = "";
    pass = "";

    QLabel *nameLabel = new QLabel("Login:");
    nameEdit = new QLineEdit;

    QHBoxLayout *nameLayout = new QHBoxLayout;
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameEdit);

    QLabel *passLabel = new QLabel("Password:");
    passEdit = new QLineEdit;

    QHBoxLayout *passLayout = new QHBoxLayout;
    passLayout->addWidget(passLabel);
    passLayout->addWidget(passEdit);

    QPushButton *submit = new QPushButton("OK");
    QPushButton *cancel = new QPushButton("Cancel");
    connect(submit, SIGNAL(clicked()), this, SLOT(LogIn()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(close()));

    QVBoxLayout *main = new QVBoxLayout;
    main->addItem(nameLayout);
    main->addItem(passLayout);
    main->addWidget(submit);
    main->addWidget(cancel);

    this->setLayout(main);
}

void AuthorizationHandler::LogIn()
{
    name = nameEdit->text();
    pass = passEdit->text();
    if (VertifyAccount(name, pass))
    {
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Login or password is incorrect");
    }
}

bool AuthorizationHandler::VertifyAccount(QString login, QString password)
{
    QFile usersDB("./users.json");
    usersDB.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!usersDB.isOpen())
    {
        qDebug() << "no users file";
        return false;
    }
    QString usersLogins = usersDB.readAll();
    usersDB.close();
    QJsonDocument grid_json = QJsonDocument::fromJson(usersLogins.toUtf8());

    if (grid_json[login] == password)
    {
        return true;
    }
    return false;
}

QString AuthorizationHandler::GetUserName()
{
    return name;
}

QString AuthorizationHandler::GetUserPass()
{
    return pass;
}
