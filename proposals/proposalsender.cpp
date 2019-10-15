#include "proposalsender.h"
#include <QDebug>

ProposalSender::ProposalSender()
{
    roomNumber = "";
    price = "";
    location = "";
    nameOwner = "";
    bankAccount = "";

    QLabel *addProposalLabel = new QLabel("Add new proposal");

    QLabel *addressLabel = new QLabel("Address of house");
    QLineEdit *addressEdit = new QLineEdit;
    connect(addressEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditedLocation(QString)));
    QVBoxLayout *address = new QVBoxLayout;
    address->addWidget(addressLabel);
    address->addWidget(addressEdit);

    QLabel *roomLabel = new QLabel("Number of rooms");
    QLineEdit *roomEdit = new QLineEdit;
    connect(roomEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditedNumberRooms(QString)));
    QVBoxLayout *room = new QVBoxLayout;
    room->addWidget(roomLabel);
    room->addWidget(roomEdit);

    QLabel *photoLabel = new QLabel("Add photos");
    filesList = new QListWidget;
    filesList->setStyleSheet("QListWidget {"
                             "background: #ffe7d0;"
                             "border-radius: 4px; }"
                             "QListWidget::item:hover { background: #b88c53; }"
                             "QListWidget::item:selected { background: #f095ee; }");
    filesList->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    QPushButton *deleteFile = new QPushButton("Delete file");
    connect(deleteFile, SIGNAL(clicked()), this, SLOT(DeletePhoto()));
    QPushButton *addFile = new QPushButton("Add file");
    connect(addFile, SIGNAL(clicked()), this, SLOT(AddPhoto()));
    QHBoxLayout *manageFiles = new QHBoxLayout;
    manageFiles->addWidget(deleteFile);
    manageFiles->addWidget(addFile);
    QVBoxLayout *files = new QVBoxLayout;
    files->addWidget(photoLabel);
    files->addWidget(filesList);
    files->addLayout(manageFiles);

    QLabel *bankLabel = new QLabel("Bank account");
    QLineEdit *bankEdit = new QLineEdit;
    connect(bankEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditedBankAccount(QString)));
    QVBoxLayout *bank = new QVBoxLayout;
    bank->addWidget(bankLabel);
    bank->addWidget(bankEdit);

    QLabel *priceLabel = new QLabel("Price per month:");
    QLineEdit *priceEdit = new QLineEdit;
    connect(priceEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditedPrice(QString)));
    QVBoxLayout *price = new QVBoxLayout;
    price->addWidget(priceLabel);
    price->addWidget(priceEdit);

    QSpacerItem *leftSpace = new QSpacerItem(40, 60, QSizePolicy::Expanding, QSizePolicy::Preferred);
    QSpacerItem *rightSpace = new QSpacerItem(40, 60, QSizePolicy::Expanding, QSizePolicy::Preferred);
    QPushButton *makeProposal = new QPushButton("add proposal");
    connect(makeProposal, SIGNAL(clicked()), this, SLOT(SendProposal()));
    QHBoxLayout *make = new QHBoxLayout;
    make->addItem(leftSpace);
    make->addWidget(makeProposal);
    make->addItem(rightSpace);

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(addProposalLabel);
    page->addLayout(address);
    page->addLayout(room);
    page->addLayout(files);
    page->addLayout(bank);
    page->addLayout(price);
    page->addLayout(make);

    this->setLayout(page);
}

void ProposalSender::SetOwner(QString name)
{
    nameOwner = name;
}

void ProposalSender::EditedLocation(QString newLocation)
{
    location = newLocation;
}

void ProposalSender::EditedNumberRooms(QString newNumberRooms)
{
    roomNumber = newNumberRooms;
}

void ProposalSender::EditedBankAccount(QString newBankAccount)
{
    bankAccount = newBankAccount;
}

void ProposalSender::EditedPrice(QString newPrice)
{
    price = newPrice;
}

void ProposalSender::AddPhoto()
{
    QString file = QFileDialog::getOpenFileName(this);
    if (file == "")
        return;
    filesList->addItem(file);
}

void ProposalSender::DeletePhoto()
{
    filesList->takeItem(filesList->currentRow());
}

void ProposalSender::SendProposal()
{
    qDebug() << "send proposal";
    QMap<QString, QVariant> newProposal;
    newProposal.insert("owner", nameOwner);
    newProposal.insert("location", location);
    newProposal.insert("Number of room", roomNumber);
    newProposal.insert("Price", price);
    QList<QVariant> photos;
    for (int i = 0; i < filesList->count(); i++)
    {
        photos.append(filesList->item(i)->text());
    }
    newProposal.insert("photos", photos);

    emit UpdateProposals();
}
