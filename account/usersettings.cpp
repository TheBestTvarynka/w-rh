#include "usersettings.h"

UserSettings::UserSettings()
{
    QLabel *emailLabel = new QLabel("Email address");
    QLineEdit *emailEdit = new QLineEdit;
    QVBoxLayout *email = new QVBoxLayout;
    email->addWidget(emailLabel);
    email->addWidget(emailEdit);

    QLabel *paymentLabel = new QLabel("Bank account");
    QLineEdit *paymentEdit = new QLineEdit;
    QVBoxLayout *payment = new QVBoxLayout;
    payment->addWidget(paymentLabel);
    payment->addWidget(paymentEdit);

    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);

    QVBoxLayout *page = new QVBoxLayout;
    page->addLayout(email);
    page->addLayout(payment);
    page->addItem(space);

    this->setLayout(page);
}
