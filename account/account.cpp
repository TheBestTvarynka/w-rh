#include "account.h"

Account::Account(Qt::Orientation orientation) : QSplitter(orientation)
{
    username = "";
    QPushButton *profile = new QPushButton("Profile");
    connect(profile, SIGNAL(clicked()), this, SLOT(SetProfile()));
    QPushButton *settings = new QPushButton("Accout settings");
    connect(settings, SIGNAL(clicked()), this, SLOT(SetUserSettings()));
    QPushButton *makeProposal = new QPushButton("Make a proposal");
    connect(makeProposal, SIGNAL(clicked()), this, SLOT(SetMakeProposal()));
    QPushButton *logOut = new QPushButton("Log out");
//    connect(profile, SIGNAL(clicked()), this, SLOT(SetProfile()));
    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);

    QVBoxLayout *sideBarLayout = new QVBoxLayout;
    sideBarLayout->setMargin(0);
    sideBarLayout->addWidget(profile);
    sideBarLayout->addWidget(settings);
    sideBarLayout->addWidget(makeProposal);
    sideBarLayout->addWidget(logOut);
    sideBarLayout->addItem(space);

    QWidget *sideBar = new QWidget;
    sideBar->setLayout(sideBarLayout);

    content = new QWidget(this);
    content->setLayout(new QVBoxLayout);
    SetProfile();
    this->addWidget(sideBar);
    this->addWidget(content);
}

void Account::ClearLayout(QLayout *layout)
{
    if (!layout)
        return;
    while (auto item = layout->takeAt(0))
    {
        delete item->widget();
        ClearLayout(item->layout());
    }
}

void Account::LogIn()
{
    AuthorizationHandler *login = new AuthorizationHandler;
    login->exec();

}

QString Account::GetName()
{
    return username;
}

void Account::SetProfile()
{
    QVBoxLayout *page = (QVBoxLayout *)(content->layout());
    ClearLayout(page);

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

    page->addLayout(personName);
    page->addLayout(phone);
    page->addLayout(location);
    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);
    page->addItem(space);
}

void Account::SetUserSettings()
{
    QVBoxLayout *page = (QVBoxLayout *)(content->layout());
    ClearLayout(page);

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
    page->addLayout(email);
    page->addLayout(payment);
    page->addItem(space);
}

void Account::SetMakeProposal()
{
    QVBoxLayout *page = (QVBoxLayout *)(content->layout());
    ClearLayout(page);

    QLabel *proposalsLabel = new QLabel("Your proposals");
    QListWidget *proposalsList = new QListWidget;
    QVBoxLayout *proposals = new QVBoxLayout;
    proposals->addWidget(proposalsLabel);
    proposals->addWidget(proposalsList);

    QLabel *addProposalLabel = new QLabel("Add new proposal");

    QLabel *addressLabel = new QLabel("Address of house");
    QLineEdit *addressEdit = new QLineEdit;
    QVBoxLayout *address = new QVBoxLayout;
    address->addWidget(addressLabel);
    address->addWidget(addressEdit);

    QLabel *bankLabel = new QLabel("Bank account");
    QLineEdit *bankEdit = new QLineEdit;
    QVBoxLayout *bank = new QVBoxLayout;
    bank->addWidget(bankLabel);
    bank->addWidget(bankEdit);

    QListWidget *filesList = new QListWidget;
    QPushButton *deleteFile = new QPushButton("Delete file");
    QPushButton *addFile = new QPushButton("Add file");
    QHBoxLayout *manageFiles = new QHBoxLayout;
    manageFiles->addWidget(deleteFile);
    manageFiles->addWidget(addFile);
    QVBoxLayout *files = new QVBoxLayout;
    files->addWidget(filesList);
    files->addLayout(manageFiles);

    QPushButton *makeProposal = new QPushButton("add proposal");

    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);
    page->addLayout(proposals);
    page->addWidget(addProposalLabel);
    page->addLayout(address);
    page->addLayout(bank);
    page->addLayout(files);
    page->addWidget(makeProposal);
    page->addItem(space);
}
