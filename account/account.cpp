#include "account.h"

Account::Account(Qt::Orientation orientation) : QSplitter(orientation)
{
    QPushButton *profile = new QPushButton("Profile");
    QPushButton *settings = new QPushButton("Profile");
    QPushButton *makeDeal = new QPushButton("Profile");
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
