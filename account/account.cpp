#include "account.h"

Account::Account(Qt::Orientation orientation) : QSplitter(orientation)
{
    username = "";
    QPushButton *profile = new QPushButton("Profile");
    QPushButton *settings = new QPushButton("Settings");
    QPushButton *makeDeal = new QPushButton("Make a proposal");
    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);

    QVBoxLayout *sideBarLayout = new QVBoxLayout;
    sideBarLayout->setMargin(0);
    sideBarLayout->addWidget(profile);
    sideBarLayout->addWidget(settings);
    sideBarLayout->addWidget(makeDeal);
    sideBarLayout->addItem(space);

    QWidget *sideBar = new QWidget;
    sideBar->setLayout(sideBarLayout);

    QWidget *content = new QWidget;
    content->setStyleSheet("QWidget {"
                           "background: grey; }");

    this->addWidget(sideBar);
    this->addWidget(content);
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
