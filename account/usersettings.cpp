#include "usersettings.h"

UserSettings::UserSettings()
{
    QLabel *firstNameLabel = new QLabel("First name");
    QLineEdit *firstNameEdit = new QLineEdit;
    QVBoxLayout *firstName = new QVBoxLayout;
    firstName->addWidget(firstNameLabel);
    firstName->addWidget(firstNameEdit);

    QLabel *secondNameLabel = new QLabel("Second name");
    QLineEdit *secondNameEdit = new QLineEdit;
    QVBoxLayout *secondName = new QVBoxLayout;
    secondName->addWidget(secondNameLabel);
    secondName->addWidget(secondNameEdit);

    QHBoxLayout *personName = new QHBoxLayout;
    personName->addItem(firstName);
    personName->addItem(secondName);

    QLabel *phoneLabel = new QLabel("Phone number");
    QLineEdit *phoneEdit = new QLineEdit;
    QVBoxLayout *phone = new QVBoxLayout;
    phone->addWidget(phoneLabel);
    phone->addWidget(phoneEdit);

    QLabel *locationLabel = new QLabel("Location");
    QLineEdit *locationEdit = new QLineEdit;
    QVBoxLayout *location = new QVBoxLayout;
    location->addWidget(locationLabel);
    location->addWidget(locationEdit);

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

    QLabel *dealsLabel = new QLabel("Deals:");
    QListWidget *listDeals = new QListWidget;
    listDeals->setStyleSheet("QListWidget {"
                                 "background: #ffe7d0;"
                                 "border-radius: 4px; }"
                                 "QListWidget::item:hover { background: #b88c53; }"
                                 "QListWidget::item:selected { background: #f095ee; }");
    QPushButton *deleteDeal = new QPushButton("delete");
    QVBoxLayout *deals = new QVBoxLayout;
    deals->addWidget(dealsLabel);
    deals->addWidget(listDeals);
    deals->addWidget(deleteDeal);

    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);

    QVBoxLayout *page = new QVBoxLayout;
    page->addLayout(personName);
    page->addLayout(phone);
    page->addLayout(location);
    page->addLayout(email);
    page->addLayout(payment);
    page->addLayout(deals);
    page->addItem(space);

    this->setLayout(page);
}
