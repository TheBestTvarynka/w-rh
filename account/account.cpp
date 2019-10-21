#include "account.h"
#include "mainguiwindow.h"
#include <QDebug>

Account::Account(MainGUIWindow *p, Qt::Orientation orientation) : QSplitter(orientation)
{
    Parent = p;
    username = "";
    loader = nullptr;

    QPushButton *settings = new QPushButton("Accout settings");
    settings->setStyleSheet("QPushButton {"
                            "background: #ffe7d0;"
                            "color: #ffba00;"
                            "border-radius: 0px;"
                            "border-top-left-radius: 8px;"
                            "padding: 10px; }"
                            "QPushButton::hover {"
                            "background: #b88c53; }");
    connect(settings, SIGNAL(clicked()), this, SLOT(SetUserSettings()));
    permissionsButton = new QPushButton("Permissions");
    permissionsButton->setStyleSheet("QPushButton {"
                            "background: #ffe7d0;"
                            "color: #ffba00;"
                            "border-radius: 0px;"
                            "padding: 10px; }"
                            "QPushButton::hover {"
                            "background: #b88c53; }");

    connect(permissionsButton, SIGNAL(clicked()), this, SLOT(SetUserPermissions()));
    QPushButton *logOut = new QPushButton("Log out");
    logOut->setStyleSheet("QPushButton {"
                            "background: #ffe7d0;"
                            "color: #ffba00;"
                            "border-radius: 0px;"
                            "padding: 10px; }"
                            "QPushButton::hover {"
                            "background: #b88c53; }");
    connect(logOut, SIGNAL(clicked()), this, SLOT(LogOut()));

    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);

    QVBoxLayout *sideBarLayout = new QVBoxLayout;

    sideBarLayout->addWidget(settings);
    sideBarLayout->addWidget(permissionsButton);
    sideBarLayout->addWidget(logOut);
    sideBarLayout->addItem(space);
    sideBarLayout->setMargin(0);
    sideBarLayout->setSpacing(0);

    QWidget *sideBar = new QWidget;
    sideBar->setLayout(sideBarLayout);
    sideBar->setStyleSheet(".QWidget {"
                           "background: #655b50;"
                           "border-radius: 8px; }");

    content = new QWidget(this);
    content->setLayout(new QVBoxLayout);
    SetUserSettings();

    content->setStyleSheet("QWidget {"
                            "background: #655b50;"
                            "border-radius: 8px; }"
                            "QLineEdit {"
                            "background: #ffba00;"
                            "border-radius: 4px; }"
                           "QPushButton {"
                           "background: #ffe7d0;"
                           "color: #ffba00;"
                           "border-radius: 4px;"
                           "padding: 10px; }"
                           "QPushButton::hover {"
                           "background: #b88c53; }");

    this->addWidget(sideBar);
    this->addWidget(content);
    this->setStyleSheet("QSplitter {"
                        "background: #655b50;"
                        "border: 1px solid #655b50;"
                        "border-radius: 8px; }"
                        "QSplitter::handle {"
                        "background: white;"
                        "border: 1px solid #2b241e;"
                        "width: 5px; }");
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
    if (username != "")
    {
        loader = new UserDataLoader;
        loader->ReadUserData(username);
        SetUserPermissions();
    }
}

void Account::LogOut()
{
    qDebug() << "Logging out...";
    QVBoxLayout *page = (QVBoxLayout *)(content->layout());
    ClearLayout(page);
    username.clear();
    delete loader;
    Parent->LoadProposals();
    qDebug() << "Logged out...";
}

void Account::WriteSettings(QMap<QString, QVariant> newSettings)
{
    loader->WriteSettings(newSettings);
}

QString Account::GetName()
{
    return username;
}

void Account::AddDealToUser(QString id)
{
    // there we add proposal id to user data
    SetUserSettings();
    UserSettings *settings = (UserSettings *)content->layout()->takeAt(0)->widget();
    settings->AddDeal(id);
}

void Account::SetUserSettings()
{
    QVBoxLayout *page = (QVBoxLayout *)(content->layout());
    ClearLayout(page);

    QWidget *settings;
    if (username != "")
        settings = new UserSettings(this, *loader->GetUserData());
    else
    {
        settings = new QWidget;
        settings->setLayout(new QHBoxLayout);
    }
    page->addWidget(settings);
}

void Account::SetUserPermissions()
{
    QVBoxLayout *page = (QVBoxLayout *)(content->layout());
    ClearLayout(page);

    QString permissions = loader->GetPreference("permission").toString();
    if (permissions == "user")
    {
        permissionsButton->setText("Proposals");
        QLabel *proposalsLabel = new QLabel("Your proposals");
        QListWidget *proposalsList = new QListWidget;
        proposalsList->setStyleSheet("QListWidget {"
                                     "background: #ffe7d0;"
                                     "border-radius: 4px; }"
                                     "QListWidget::item:hover { background: #b88c53; }"
                                     "QListWidget::item:selected { background: #f095ee; }");
        proposalsList->addItem("erferf");
        proposalsList->addItem("ojoijijnvi");
        QPushButton *deleteProposal = new QPushButton("delete");
        QVBoxLayout *proposals = new QVBoxLayout;
        proposals->addWidget(proposalsLabel);
        proposals->addWidget(proposalsList);
        proposals->addWidget(deleteProposal);

        ProposalSender *sender = new ProposalSender;
        connect(sender, SIGNAL(UpdateProposals()), Parent->GetViewer(), SLOT(UpdateProposal()));
        sender->SetOwner(username);

        page->addLayout(proposals);
        page->addWidget(sender);
    }
    if (permissions == "manager")
    {
        permissionsButton->setText("Manager Profile");
        page->addWidget(new manager(username));
    }
    if (permissions == "admin")
    {
        permissionsButton->setText("Admin profile");
        page->addWidget(new Admin);
    }
}

void Account::DeleteProposal()
{

}
