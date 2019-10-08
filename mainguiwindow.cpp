#include "mainguiwindow.h"
#include "ui_mainguiwindow.h"

MainGUIWindow::MainGUIWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainGUIWindow)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout;
    Account *user = new Account(Qt::Horizontal);
    layout->addWidget(user);
    ui->centralwidget->setLayout(layout);
}

MainGUIWindow::~MainGUIWindow()
{
    delete ui;
}

