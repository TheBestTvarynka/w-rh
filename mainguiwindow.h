#ifndef MAINGUIWINDOW_H
#define MAINGUIWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

#include "account/account.h"
#include "proposals/proposalsviewer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainGUIWindow; }
QT_END_NAMESPACE

class MainGUIWindow : public QMainWindow
{
    Q_OBJECT
    QWidget *content;
    Account *user;
    ProposalsViewer *proposals;
public:
    MainGUIWindow(QWidget *parent = nullptr);
    ~MainGUIWindow();
    QWidget *SetTopPanel();
    Account *GetAccount() { return user; }
    ProposalsViewer *GetViewer() { return proposals; }
private:
    Ui::MainGUIWindow *ui;
public slots:
    void LoadProfile();
    void LoadProposals();
};
#endif // MAINGUIWINDOW_H
