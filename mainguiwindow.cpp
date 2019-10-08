#include "mainguiwindow.h"
#include "ui_mainguiwindow.h"

MainGUIWindow::MainGUIWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainGUIWindow)
{
    ui->setupUi(this);
}

MainGUIWindow::~MainGUIWindow()
{
    delete ui;
}

