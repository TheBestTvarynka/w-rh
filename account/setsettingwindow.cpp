#include "setsettingwindow.h"
#include "account.h"
#include <QDebug>

SetSettingWindow::SetSettingWindow()
{
    FirstName = "";
    SecondName = "";
    Email = "";
    BankAccount = "";
    Location = "";
    PhoneNumber = "";
    Deals = "";

    QLabel *FirstNameLabel = new QLabel("FirstName:");
    FirstNameEdit = new QLineEdit;

    QHBoxLayout *FirstNameLayout = new QHBoxLayout;
    FirstNameLayout->addWidget(FirstNameLabel);
    FirstNameLayout->addWidget(FirstNameEdit);

    QLabel *SecondNameLabel = new QLabel("SecondName:");
    SecondNameEdit = new QLineEdit;

    QHBoxLayout *SecondNameLayout = new QHBoxLayout;
    SecondNameLayout->addWidget(SecondNameLabel);
    SecondNameLayout->addWidget(SecondNameEdit);

    QLabel *EmailLabel = new QLabel("Email:");
    EmailEdit = new QLineEdit;

    QHBoxLayout *EmailLayout = new QHBoxLayout;
    EmailLayout->addWidget(EmailLabel);
    EmailLayout->addWidget(EmailEdit);

    QLabel *BankAccountLabel = new QLabel("BankAccount:");
    SecondNameEdit = new QLineEdit;

    QHBoxLayout *BankAccountLayout = new QHBoxLayout;
    BankAccountLayout->addWidget(BankAccountLabel);
    BankAccountLayout->addWidget(BankAccountEdit);

    QLabel *LocationLabel = new QLabel("Location:");
    SecondNameEdit = new QLineEdit;

    QHBoxLayout *LocationLayout = new QHBoxLayout;
    LocationLayout->addWidget(LocationLabel);
    LocationLayout->addWidget(LocationEdit);

    QLabel *PhoneNumberLabel = new QLabel("PhoneNumber:");
    PhoneNumberEdit = new QLineEdit;

    QHBoxLayout *PhoneNumberLayout = new QHBoxLayout;
    PhoneNumberLayout->addWidget(PhoneNumberLabel);
    PhoneNumberLayout->addWidget(PhoneNumberEdit);

    QPushButton *SetSetting = new QPushButton("Set");
    QPushButton *Return = new QPushButton("Return");
    connect(SetSetting, SIGNAL(clicked()), this, SLOT(SetSetting()));
    connect(Return, SIGNAL(clicked()), this, SLOT(close()));

    QVBoxLayout *main = new QVBoxLayout;
    main->addItem(FirstNameLayout);
    main->addItem(SecondNameLayout);
    main->addItem(EmailLayout);
    main->addItem(BankAccountLayout);
    main->addItem(LocationLayout);
    main->addItem(PhoneNumberLayout);
    main->addWidget(SetSetting);
    main->addWidget(Return);

    this->setLayout(main);
}

void SetSettingWindow::SetSetting(){

}
