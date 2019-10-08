#include "mainguiwindow.h"
#include "ui_mainguiwindow.h"

MainGUIWindow::MainGUIWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainGUIWindow)
{
    ui->setupUi(this);

    Account *user = new Account(Qt::Horizontal);
    content = user;

    QVBoxLayout *scene = new QVBoxLayout;
    scene->addWidget(SetTopPanel());
    scene->addWidget(user);
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

