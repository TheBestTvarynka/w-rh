#include "usersettings.h"
#include <QDebug>

UserSettings::UserSettings(QMap<QString, QVariant> *data)
{
    userData = data;

    QLabel *firstNameLabel = new QLabel("First name");
    QLineEdit *firstNameEdit = new QLineEdit((*userData)["First name"].toString());
    connect(firstNameEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditedFirstName(QString)));
    QVBoxLayout *firstName = new QVBoxLayout;
    firstName->addWidget(firstNameLabel);
    firstName->addWidget(firstNameEdit);

    QLabel *secondNameLabel = new QLabel("Second name");
    QLineEdit *secondNameEdit = new QLineEdit((*userData)["Second name"].toString());
    connect(secondNameEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditedSeconsName(QString)));
    QVBoxLayout *secondName = new QVBoxLayout;
    secondName->addWidget(secondNameLabel);
    secondName->addWidget(secondNameEdit);

    QHBoxLayout *personName = new QHBoxLayout;
    personName->addItem(firstName);
    personName->addItem(secondName);

    QLabel *phoneLabel = new QLabel("Phone number");
    QLineEdit *phoneEdit = new QLineEdit((*userData)["phone number"].toString());
    connect(phoneEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditedPhoneNumber(QString)));
    QVBoxLayout *phone = new QVBoxLayout;
    phone->addWidget(phoneLabel);
    phone->addWidget(phoneEdit);

    QLabel *locationLabel = new QLabel("Location");
    QLineEdit *locationEdit = new QLineEdit((*userData)["Location"].toString());
    connect(locationEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditedLocation(QString)));
    QVBoxLayout *location = new QVBoxLayout;
    location->addWidget(locationLabel);
    location->addWidget(locationEdit);

    QLabel *emailLabel = new QLabel("Email address");
    QLineEdit *emailEdit = new QLineEdit((*userData)["email"].toString());
    connect(emailEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditedEmail(QString)));
    QVBoxLayout *email = new QVBoxLayout;
    email->addWidget(emailLabel);
    email->addWidget(emailEdit);

    QLabel *paymentLabel = new QLabel("Bank account");
    QLineEdit *paymentEdit = new QLineEdit((*userData)["bank account"].toString());
    connect(paymentEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditedBankAccount(QString)));
    QVBoxLayout *payment = new QVBoxLayout;
    payment->addWidget(paymentLabel);
    payment->addWidget(paymentEdit);

    QLabel *dealsLabel = new QLabel("Deals:");
    listDeals = new QListWidget;
    listDeals->setStyleSheet("QListWidget {"
                                 "background: #ffe7d0;"
                                 "border-radius: 4px; }"
                                 "QListWidget::item:hover { background: #b88c53; }"
                                 "QListWidget::item:selected { background: #f095ee; }");
    QList<QVariant> userDials = (*userData)["deals"].toList();
    QListIterator<QVariant> it(userDials);
    while (it.hasNext())
    {
        listDeals->addItem(it.next().toString());
    }

    QPushButton *deleteDeal = new QPushButton("delete");
    connect(deleteDeal, SIGNAL(clicked()), this, SLOT(RemoveDeal()));
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

void UserSettings::AddDeals(QString newDeal)
{
    QList<QVariant> deals = (*userData)["deals"].toList();
    deals.append(newDeal);
    (*userData)["deals"] = deals;
    listDeals->addItem(newDeal);
}

void UserSettings::RemoveDeal()
{
    QListWidgetItem *item = listDeals->selectedItems()[0];
    QList<QVariant> deals = (*userData)["deals"].toList();
    deals.removeOne(QVariant(item->text()));
    (*userData)["deals"] = deals;
    listDeals->takeItem(listDeals->currentRow());
}

void UserSettings::EditedFirstName(QString newFirstName)
{
    (*userData)["First name"] = QVariant(newFirstName);
}

void UserSettings::EditedSeconsName(QString newSecondName)
{
    (*userData)["Second name"] = QVariant(newSecondName);
}

void UserSettings::EditedEmail(QString newEmail)
{
    (*userData)["email"] = QVariant(newEmail);
}

void UserSettings::EditedPhoneNumber(QString newPhone)
{
    (*userData)["phone number"] = QVariant(newPhone);
}

void UserSettings::EditedBankAccount(QString newBankAccount)
{
    (*userData)["bank account"] = QVariant(newBankAccount);
}

void UserSettings::EditedLocation(QString newLocation)
{
    (*userData)["Location"] = QVariant(newLocation);
}
