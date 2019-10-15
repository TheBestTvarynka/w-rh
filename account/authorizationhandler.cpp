#include "authorizationhandler.h"
#include "account.h"
#include <QDebug>

AuthorizationHandler::AuthorizationHandler()
{
    name = "";
    pass = "";

    QLabel *nameLabel = new QLabel("Login:");
    nameEdit = new QLineEdit;

    QVBoxLayout *nameLayout = new QVBoxLayout;
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameEdit);

    QLabel *passLabel = new QLabel("Password:");
    passEdit = new QLineEdit;

    QVBoxLayout *passLayout = new QVBoxLayout;
    passLayout->addWidget(passLabel);
    passLayout->addWidget(passEdit);

    QPushButton *submit = new QPushButton("OK");
    submit->setStyleSheet("QPushButton {"
                           "background: #ffe7d0;"
                           "color: #ffba00;"
                           "border-radius: 4px;"
                           "padding: 5px; }");
    QPushButton *cancel = new QPushButton("Cancel");
    cancel->setStyleSheet("QPushButton {"
                           "background: #ffe7d0;"
                           "color: #ffba00;"
                           "border-radius: 4px;"
                           "padding: 5px; }");
    connect(submit, SIGNAL(clicked()), this, SLOT(LogIn()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(close()));

    QSpacerItem *space_up = new QSpacerItem(50, 50, QSizePolicy::Preferred, QSizePolicy::Expanding);
    QSpacerItem *space_down = new QSpacerItem(50, 50, QSizePolicy::Preferred, QSizePolicy::Expanding);
    QVBoxLayout *main = new QVBoxLayout;
    main->addItem(space_up);
    main->addItem(nameLayout);
    main->addItem(passLayout);
    main->addWidget(submit);
    main->addWidget(cancel);
    main->addItem(space_down);

    this->setLayout(main);
    this->setFixedSize(300, 400);
    this->setStyleSheet("QWidget {"
                        "background: #655b50; }"
                        "QLineEdit {"
                        "background: #ffba00; }"
                        "QLabel {"
                        "background: transparent; }");
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
        name = "";
    }
}

bool AuthorizationHandler::VertifyAccount(QString login, QString password)
{
    QFile usersDB("users.json");
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
