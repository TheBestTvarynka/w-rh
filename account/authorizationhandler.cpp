#include "authorizationhandler.h"
#include "account.h"

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
    connect(submit, SIGNAL(clicked()), this, SLOT(LogIn()));

    QVBoxLayout *main = new QVBoxLayout;
    main->addItem(nameLayout);
    main->addItem(passLayout);
    main->addWidget(submit);

    this->setLayout(main);
}

void AuthorizationHandler::LogIn()
{
    name = nameEdit->text();
    pass = passEdit->text();
    // we check login and pass
    this->close();
}

QString AuthorizationHandler::GetUserName()
{
    return name;
}

QString AuthorizationHandler::GetUserPass()
{
    return pass;
}
