#include "usersettings.h"

UserSettings::UserSettings()
{
    setting = new UserDataLoader(account);

    QPushButton *Set = new QPushButton("Set");
    QPushButton *Return = new QPushButton("Return");
    QObject::connect(Set, SIGNAL(clicked()), this, SLOT(Set()));
    QObject::connect(Return, SIGNAL(clicked()), this, SLOT(Close()));

    QLabel *firstNameLabel = new QLabel("First name");
    QLineEdit *firstNameEdit = new QLineEdit;
    firstNameEdit->setText(setting->GetMap("Firstname").toString());
    QVBoxLayout *firstName = new QVBoxLayout;
    firstName->addWidget(firstNameLabel);
    firstName->addWidget(firstNameEdit);

    QLabel *secondNameLabel = new QLabel("Second name");
    QLineEdit *secondNameEdit = new QLineEdit;
    firstNameEdit->setText(setting->GetMap("Secondname").toString());
    QVBoxLayout *secondName = new QVBoxLayout;
    secondName->addWidget(secondNameLabel);
    secondName->addWidget(secondNameEdit);

    QHBoxLayout *personName = new QHBoxLayout;
    personName->addItem(firstName);
    personName->addItem(secondName);

    QLabel *phoneLabel = new QLabel("Phone number");
    QLineEdit *phoneEdit = new QLineEdit;
    firstNameEdit->setText(setting->GetMap("Phonen number").toString());
    QVBoxLayout *phone = new QVBoxLayout;
    phone->addWidget(phoneLabel);
    phone->addWidget(phoneEdit);

    QLabel *locationLabel = new QLabel("Location");
    QLineEdit *locationEdit = new QLineEdit;
    firstNameEdit->setText(setting->GetMap("Location").toString());
    QVBoxLayout *location = new QVBoxLayout;
    location->addWidget(locationLabel);
    location->addWidget(locationEdit);

    QLabel *emailLabel = new QLabel("Email address");
    QLineEdit *emailEdit = new QLineEdit;
    firstNameEdit->setText(setting->GetMap("Email").toString());
    QVBoxLayout *email = new QVBoxLayout;
    email->addWidget(emailLabel);
    email->addWidget(emailEdit);

    QLabel *paymentLabel = new QLabel("Bank account");
    QLineEdit *paymentEdit = new QLineEdit;
    firstNameEdit->setText(setting->GetMap("Bank account").toString());
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
    (*setting->map)["Email"] = emailEdit->text();
    (*setting->map)["SecondName"] = secondNameEdit->text();
    (*setting->map)["FirstName"] = firstNameEdit->text();
    (*setting->map)["PhoneNumber"] = phoneEdit->text();
    (*setting->map)["Location"] = locationEdit->text();
    (*setting->map)["BankAccount"] = paymentEdit->text();
}

void UserSettings::Close(){
    delete setting;
    this->close();
}
