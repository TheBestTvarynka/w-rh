#include "usersettings.h"
#include <QDebug>

UserSettings::UserSettings(QMap<QString, QVariant> *data)
{
    userData = data;

    QLabel *firstNameLabel = new QLabel("First name");
    QLineEdit *firstNameEdit = new QLineEdit((*userData)["First name"].toString());
    QVBoxLayout *firstName = new QVBoxLayout;
    firstName->addWidget(firstNameLabel);
    firstName->addWidget(firstNameEdit);

    QLabel *secondNameLabel = new QLabel("Second name");
    QLineEdit *secondNameEdit = new QLineEdit((*userData)["Second name"].toString());
    QVBoxLayout *secondName = new QVBoxLayout;
    secondName->addWidget(secondNameLabel);
    secondName->addWidget(secondNameEdit);

    QHBoxLayout *personName = new QHBoxLayout;
    personName->addItem(firstName);
    personName->addItem(secondName);

    QLabel *phoneLabel = new QLabel("Phone number");
    QLineEdit *phoneEdit = new QLineEdit((*userData)["phone number"].toString());
    QVBoxLayout *phone = new QVBoxLayout;
    phone->addWidget(phoneLabel);
    phone->addWidget(phoneEdit);

    QLabel *locationLabel = new QLabel("Location");
    QLineEdit *locationEdit = new QLineEdit((*userData)["Location"].toString());
    QVBoxLayout *location = new QVBoxLayout;
    location->addWidget(locationLabel);
    location->addWidget(locationEdit);

    QLabel *emailLabel = new QLabel("Email address");
    QLineEdit *emailEdit = new QLineEdit((*userData)["email"].toString());
    QVBoxLayout *email = new QVBoxLayout;
    email->addWidget(emailLabel);
    email->addWidget(emailEdit);

    QLabel *paymentLabel = new QLabel("Bank account");
    QLineEdit *paymentEdit = new QLineEdit((*userData)["bank account"].toString());
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
