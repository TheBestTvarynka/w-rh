#include "dealhandler.h"

DealHandler::DealHandler(QWidget *parent, ProposalItem *i) : QDialog(parent)
{
    item = i;
    QVBoxLayout *page = new QVBoxLayout;

    QHBoxLayout *inscription;
    QLabel *title, *value;
    QMap<QString, QVariant> *details = i->GetProposalDetails();
    for (QMap<QString, QVariant>::Iterator i = details->begin(); i != details->end(); i++)
    {
        if (i->type() == QVariant::Type::List)
        {
            title = new QLabel(i.key());
            QList<QVariant> photos = i.value().toList();
            QVBoxLayout *collectionPhoto = new QVBoxLayout;
            for (QList<QVariant>::Iterator photo = photos.begin(); photo != photos.end(); photo++)
            {
                value = new QLabel(photo->toString());
                collectionPhoto->addWidget(value);
            }
            QVBoxLayout *photosLayout = new QVBoxLayout;
            photosLayout->addWidget(title);
            photosLayout->addLayout(collectionPhoto);
            page->addLayout(photosLayout);
        }
        else
        {
            title = new QLabel(i.key() + ": ");
            value = new QLabel(i.value().toString());
            inscription = new QHBoxLayout;
            inscription->addWidget(title);
            inscription->addWidget(value);
            page->addLayout(inscription);
        }
    }

    title = new QLabel("Enter your bank account: ");
    bankAccount = new QLineEdit;
    connect(bankAccount, SIGNAL(textEdited(const QString &)), this, SLOT(SetBankAccountNumber(QString)));
    QVBoxLayout *bank = new QVBoxLayout;
    bank->addWidget(title);
    bank->addWidget(bankAccount);

    QPushButton *submit = new QPushButton("Submit");
    connect(submit, SIGNAL(clicked()), this, SLOT(MakeDial()));

    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);
    page->addLayout(bank);
    page->addWidget(submit);
    page->addItem(space);
    this->setLayout(page);
}

void DealHandler::SetBankAccountNumber(QString newBankAccountNumber)
{
    bancAccountNumber = newBankAccountNumber;
}

void DealHandler::MakeDial()
{
    Bank *bank = new Bank("bankusers.json");

}
