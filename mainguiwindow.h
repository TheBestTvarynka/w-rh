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
    QWidget *content;
public:
    MainGUIWindow(QWidget *parent = nullptr);
    ~MainGUIWindow();
    QWidget *SetTopPanel();
private:
    Ui::MainGUIWindow *ui;
};
#endif // MAINGUIWINDOW_H
