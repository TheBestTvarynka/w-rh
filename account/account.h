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
//    void SetMakeDeal();
};

#endif // ACCOUNT_H
