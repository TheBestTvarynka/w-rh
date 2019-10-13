#include "dealhandler.h"

void DealHandler::CreateTitles()
{
    titles.push_back("Name");
    titles.push_back("Address");
    titles.push_back("Number of rooms");
    titles.push_back("Price");
    titles.push_back("Photos");


}

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
    QLineEdit *bankAccount = new QLineEdit;
    QVBoxLayout *bank = new QVBoxLayout;
    bank->addWidget(title);
    bank->addWidget(bankAccount);

    QPushButton *submit = new QPushButton("Submit");

    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);
    page->addLayout(bank);
    page->addWidget(submit);
    page->addItem(space);
    this->setLayout(page);
}
