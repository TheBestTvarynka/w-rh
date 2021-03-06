#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QSplitter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QListWidget>

#include "authorizationhandler.h"
#include "../proposals/proposalsender.h"
#include "../data/userdataloader.h"
#include "usersettings.h"
#include "actors/admin.h"
#include "actors/manager.h"

class MainGUIWindow;

class Account : public QSplitter
{
    Q_OBJECT
    UserDataLoader *loader;
    MainGUIWindow *Parent;
    QWidget *content;
    QPushButton *permissionsButton;
    QString username;
//    QPushButton *manager;
public:
    Account(MainGUIWindow *, Qt::Orientation orientation);
    void ClearLayout(QLayout *);
    void LogIn();
    void WriteSettings(QMap<QString, QVariant>);
public slots:
    QString GetName();
    void AddDealToUser(QString);
    void SetUserSettings();
    void SetUserPermissions();
    void DeleteProposal();
    void LogOut();
};

#endif // ACCOUNT_H
