#include "proposalsender.h"

ProposalSender::ProposalSender()
{
    name = "";
    roomNumber = "";
    price = "";
    location = "";
    nameOwner = "";

    QLabel *addProposalLabel = new QLabel("Add new proposal");

    QLabel *addressLabel = new QLabel("Address of house");
    QLineEdit *addressEdit = new QLineEdit;
    QVBoxLayout *address = new QVBoxLayout;
    address->addWidget(addressLabel);
    address->addWidget(addressEdit);

    QLabel *roomLabel = new QLabel("Number of rooms");
    QLineEdit *roomEdit = new QLineEdit;
    QVBoxLayout *room = new QVBoxLayout;
    room->addWidget(roomLabel);
    room->addWidget(roomEdit);

    QLabel *photoLabel = new QLabel("Add photos");
    QListWidget *filesList = new QListWidget;
    QPushButton *deleteFile = new QPushButton("Delete file");
    QPushButton *addFile = new QPushButton("Add file");
    QHBoxLayout *manageFiles = new QHBoxLayout;
    manageFiles->addWidget(deleteFile);
    manageFiles->addWidget(addFile);
    QVBoxLayout *files = new QVBoxLayout;
    files->addWidget(photoLabel);
    files->addWidget(filesList);
    files->addLayout(manageFiles);

    QLabel *bankLabel = new QLabel("Bank account");
    QLineEdit *bankEdit = new QLineEdit;
    QVBoxLayout *bank = new QVBoxLayout;
    bank->addWidget(bankLabel);
    bank->addWidget(bankEdit);

    QLabel *priceLabel = new QLabel("Price per month:");
    QLineEdit *priceEdit = new QLineEdit;
    QVBoxLayout *price = new QVBoxLayout;
    price->addWidget(priceLabel);
    price->addWidget(priceEdit);

    QPushButton *makeProposal = new QPushButton("add proposal");

    QVBoxLayout *page = new QVBoxLayout;
    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);
    page->addWidget(addProposalLabel);
    page->addLayout(address);
    page->addLayout(room);
    page->addLayout(files);
    page->addLayout(bank);
    page->addLayout(price);
    page->addWidget(makeProposal);
    page->addItem(space);

    this->setLayout(page);
}

void ProposalSender::SetOwner(QString name)
{
    nameOwner = name;
}
