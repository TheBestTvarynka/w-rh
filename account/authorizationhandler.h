#ifndef AUTHORIZATIONHANDLER_H
#define AUTHORIZATIONHANDLER_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>

#include "registrationhandler.h"

class Account;

class AuthorizationHandler : public QDialog
{
    Q_OBJECT
    QString name;
    QString pass;
    QLineEdit *nameEdit;
    QLineEdit *passEdit;
    Account *Parent;
public:
    AuthorizationHandler();
public slots:
    void LogIn();
    bool VertifyAccount(QString, QString);
    QString GetUserName();
    QString GetUserPass();
    void Register();
};

#endif // AUTHORIZATIONHANDLER_H
