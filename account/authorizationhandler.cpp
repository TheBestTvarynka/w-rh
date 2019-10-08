#include "authorizationhandler.h"

AuthorizationHandler::AuthorizationHandler()
{
    name = "";
    pass = "";

    QLabel *nameLabel = new QLabel("Enter a name:");
    nameEdit = new QLineEdit;

    QHBoxLayout *nameLayout = new QHBoxLayout;
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameEdit);

    QLabel *passLabel = new QLabel("Enter a name:");
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
    this->close();
}
