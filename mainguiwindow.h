#ifndef MAINGUIWINDOW_H
#define MAINGUIWINDOW_H

#include <QMainWindow>

#include "account/account.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainGUIWindow; }
QT_END_NAMESPACE

class MainGUIWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainGUIWindow(QWidget *parent = nullptr);
    ~MainGUIWindow();

private:
    Ui::MainGUIWindow *ui;
};
#endif // MAINGUIWINDOW_H
