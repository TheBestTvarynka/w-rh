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

class Account : public QSplitter
{
    Q_OBJECT
    QWidget *content;
    QString username;
public:
    Account(Qt::Orientation orientation);
    void ClearLayout(QLayout *);
    void LogIn();
    QString GetName();
public slots:
    void SetProfile();
    void SetUserSettings();
    void SetMakeProposal();
};

#endif // ACCOUNT_H
