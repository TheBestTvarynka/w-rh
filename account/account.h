#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QSplitter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QLabel>

#include "authorizationhandler.h"

class Account : public QSplitter
{
    Q_OBJECT
    QString username;
public:
    Account(Qt::Orientation orientation);
    void LogIn();
    QString GetName();
};

#endif // ACCOUNT_H
