#include "mainguiwindow.h"
#include "ui_mainguiwindow.h"
#include <QDebug>

MainGUIWindow::MainGUIWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainGUIWindow)
{
    ui->setupUi(this);

    user = new Account(Qt::Horizontal);
    proposals = new ProposalsViewer(user);

    content = new QWidget;
    content->setLayout(new QVBoxLayout);

    LoadProposals();

    QVBoxLayout *scene = new QVBoxLayout;
    scene->addWidget(SetTopPanel());
    scene->addWidget(content);
    scene->setMargin(5);
    ui->centralwidget->setLayout(scene);

    ui->centralwidget->setStyleSheet("QWidget {"
                                     "background: #2b241e; }");
}

MainGUIWindow::~MainGUIWindow()
{
    delete ui;
}

QWidget *MainGUIWindow::SetTopPanel()
{
    QLabel *logo = new QLabel("W-RH");
    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Expanding, QSizePolicy::Preferred);
    QPushButton *profile = new QPushButton("Profile");
    profile->setStyleSheet("QPushButton {"
                           "background: #ffe7d0;"
                           "color: #ffba00;"
                           "border-radius: 4px;"
                           "padding-right: 15px;"
                           "padding-left: 15px; }");
    profile->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    QObject::connect(profile, SIGNAL(clicked()), this, SLOT(LoadProfile()));

    QHBoxLayout *topPanelLayout = new QHBoxLayout;
    topPanelLayout->addWidget(logo);
    topPanelLayout->addItem(space);
    topPanelLayout->addWidget(profile);
    topPanelLayout->setMargin(5);

    QWidget *topPanel = new QWidget;
    topPanel->setFixedHeight(50);
    topPanel->setStyleSheet("QWidget {"
                            "background: #655b50;"
                            "border: 1px solid #655b50;"
                            "border-radius: 8px; }");
    topPanel->setLayout(topPanelLayout);
    return topPanel;
}

void MainGUIWindow::LoadProfile()
{
    user->hide();
    QLayout *current = content->layout();
    if (current->indexOf(user) != -1)
    {
        LoadProposals();
        return;
    }
    if (user->GetName() == "")
    {
        user->LogIn();
        if (user->GetName() == "")
            return;
    }
    user->show();
    proposals->hide();
    if (current->indexOf(proposals) != -1)
    {
        current->replaceWidget(proposals, user);
        return;
    }
    current->addWidget(user);
}

void MainGUIWindow::LoadProposals()
{
    user->hide();
    proposals->show();
    QLayout *current = content->layout();
    if (current->indexOf(proposals) != -1)
    {
        return;
    }
    if (current->indexOf(user) != -1)
    {
        current->replaceWidget(user, proposals);
        return;
    }
    current->addWidget(proposals);
}

