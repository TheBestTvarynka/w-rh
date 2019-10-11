#include "account.h"

Account::Account(Qt::Orientation orientation) : QSplitter(orientation)
{
    username = "";
    QPushButton *settings = new QPushButton("Accout settings");
    connect(settings, SIGNAL(clicked()), this, SLOT(SetUserSettings()));
    QPushButton *makeProposal = new QPushButton("Make a proposal");
    connect(makeProposal, SIGNAL(clicked()), this, SLOT(SetMakeProposal()));
    QPushButton *logOut = new QPushButton("Log out");
//    connect(profile, SIGNAL(clicked()), this, SLOT(SetProfile()));
    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);

    QVBoxLayout *sideBarLayout = new QVBoxLayout;
    sideBarLayout->addWidget(settings);
    sideBarLayout->addWidget(makeProposal);
    sideBarLayout->addWidget(logOut);
    sideBarLayout->addItem(space);
    sideBarLayout->setMargin(0);

    QWidget *sideBar = new QWidget;
    sideBar->setLayout(sideBarLayout);

    content = new QWidget(this);
    content->setLayout(new QVBoxLayout);
    SetUserSettings();
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
    username = login->GetUserName();
}

QString Account::GetName()
{
    return username;
}

void Account::SetUserSettings()
{
    QVBoxLayout *page = (QVBoxLayout *)(content->layout());
    ClearLayout(page);

    UserSettings *settings = new UserSettings;

    page->addWidget(settings);
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

    ProposalSender *sender = new ProposalSender;
    sender->SetOwner(username);

    page->addLayout(proposals);
    page->addWidget(sender);
}
