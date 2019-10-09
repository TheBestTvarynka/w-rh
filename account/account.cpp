#include "account.h"

Account::Account(Qt::Orientation orientation) : QSplitter(orientation)
{
    username = "";
    QPushButton *profile = new QPushButton("Profile");
    connect(profile, SIGNAL(clicked()), this, SLOT(SetProfile()));
    QPushButton *settings = new QPushButton("Accout settings");
    connect(settings, SIGNAL(clicked()), this, SLOT(SetUserSettings()));
    QPushButton *makeDeal = new QPushButton("Make a proposal");
//    connect(profile, SIGNAL(clicked()), this, SLOT(SetProfile()));
    QPushButton *logOut = new QPushButton("Log out");
//    connect(profile, SIGNAL(clicked()), this, SLOT(SetProfile()));
    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);

    QVBoxLayout *sideBarLayout = new QVBoxLayout;
    sideBarLayout->setMargin(0);
    sideBarLayout->addWidget(profile);
    sideBarLayout->addWidget(settings);
    sideBarLayout->addWidget(makeDeal);
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
    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);
    email->addItem(space);

    page->addLayout(email);
}
