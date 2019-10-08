#include "mainguiwindow.h"
#include "ui_mainguiwindow.h"
#include <QDebug>

MainGUIWindow::MainGUIWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainGUIWindow)
{
    ui->setupUi(this);

    user = new Account(Qt::Horizontal);
    proposals = new QWidget;
    content = new QWidget;
    content->setLayout(new QVBoxLayout);

    LoadProposals();

    QVBoxLayout *scene = new QVBoxLayout;
    scene->addWidget(SetTopPanel());
    scene->addWidget(content);
    scene->setMargin(0);
    ui->centralwidget->setLayout(scene);

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
    QObject::connect(profile, SIGNAL(clicked()), this, SLOT(LoadProfile()));

    QHBoxLayout *topPanelLayout = new QHBoxLayout;
    topPanelLayout->addWidget(logo);
    topPanelLayout->addItem(space);
    topPanelLayout->addWidget(profile);
    topPanelLayout->setMargin(0);

    QWidget *topPanel = new QWidget;
    topPanel->setFixedHeight(30);
    topPanel->setStyleSheet("QWidget {"
                            "background: #945138; }");
    topPanel->setLayout(topPanelLayout);
    return topPanel;
}

void MainGUIWindow::ClearLayout(QLayout *layout)
{
    if (!layout)
        return;
    while (auto item = layout->takeAt(0))
    {
        delete item->widget();
        ClearLayout(item->layout());
    }
}


void MainGUIWindow::LoadProfile()
{
    QLayout *current = content->layout();
    if (current->indexOf(proposals) == -1)
    {
        qDebug() << "already exist...";
        return;
    }
    delete current;
    if (user->GetName() == "")
    {
        user->LogIn();
    }
    current = new QHBoxLayout;
    current->addWidget(user);
    content->setLayout(current);
}

void MainGUIWindow::LoadProposals()
{
    QLayout *current = content->layout();
    delete current;
    current = new QHBoxLayout;
    current->addWidget(proposals);
    content->setLayout(current);
}

