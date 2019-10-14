#include "usersettings.h"

UserSettings::UserSettings()
{
    setting = new UserDataLoader("capmap"); // capmap = account

    QPushButton *Set = new QPushButton("Set");
    QPushButton *Return = new QPushButton("Return");
    QObject::connect(Set, SIGNAL(clicked()), this, SLOT(Set()));
    QObject::connect(Return, SIGNAL(clicked()), this, SLOT(Close()));

    QLabel *firstNameLabel = new QLabel("First name");
    firstNameEdit = new QLineEdit;
    firstNameEdit->setText(setting->GetVariant("First name").toString());
    QVBoxLayout *firstName = new QVBoxLayout;
    firstName->addWidget(firstNameLabel);
    firstName->addWidget(firstNameEdit);

    QLabel *secondNameLabel = new QLabel("Second name");
    secondNameEdit = new QLineEdit;
    secondNameEdit->setText(setting->GetVariant("Second name").toString());
    QVBoxLayout *secondName = new QVBoxLayout;
    secondName->addWidget(secondNameLabel);
    secondName->addWidget(secondNameEdit);

    QHBoxLayout *personName = new QHBoxLayout;
    personName->addItem(firstName);
    personName->addItem(secondName);

    QLabel *phoneLabel = new QLabel("Phone number");
    phoneEdit = new QLineEdit;
    phoneEdit->setText(setting->GetVariant("Phone number").toString());
    QVBoxLayout *phone = new QVBoxLayout;
    phone->addWidget(phoneLabel);
    phone->addWidget(phoneEdit);

    QLabel *locationLabel = new QLabel("Location");
    locationEdit = new QLineEdit;
    locationEdit->setText(setting->GetVariant("Location").toString());
    QVBoxLayout *location = new QVBoxLayout;
    location->addWidget(locationLabel);
    location->addWidget(locationEdit);

    QLabel *emailLabel = new QLabel("Email address");
    emailEdit = new QLineEdit;
    emailEdit->setText(setting->GetVariant("Email").toString());
    QVBoxLayout *email = new QVBoxLayout;
    email->addWidget(emailLabel);
    email->addWidget(emailEdit);

    QLabel *paymentLabel = new QLabel("Bank account");
    paymentEdit = new QLineEdit;
    paymentEdit->setText(setting->GetVariant("Bank account").toString());
    QVBoxLayout *payment = new QVBoxLayout;
    payment->addWidget(paymentLabel);
    payment->addWidget(paymentEdit);

    QVBoxLayout *page = new QVBoxLayout;
    page->addLayout(personName);
    page->addLayout(phone);
    page->addLayout(location);
    page->addLayout(email);
    page->addLayout(payment);
    page->addWidget(Set);
    page->addWidget(Return);

    this->setLayout(page);
}

void UserSettings::Set(){
    setting->SetVariant("Email",emailEdit->text());
    setting->SetVariant("Second name",secondNameEdit->text());
    setting->SetVariant("First name",firstNameEdit->text());
    setting->SetVariant("Phone number",phoneEdit->text());
    setting->SetVariant("Location",locationEdit->text());
    setting->SetVariant("Bank account",paymentEdit->text());
}

void UserSettings::Close(){
    setting->WriteFile("capmap"); // capmap = account
    this->close();
}
