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

class Account : public QSplitter
{
    Q_OBJECT
    UserDataLoader *loader;
    QWidget *content;
    QString username;
public:
    Account(Qt::Orientation orientation);
    void ClearLayout(QLayout *);
    void LogIn();
public slots:
    QString GetName();
    void SetUserSettings();
    void SetMakeProposal();
};

#endif // ACCOUNT_H
