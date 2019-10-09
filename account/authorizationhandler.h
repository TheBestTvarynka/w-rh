#ifndef AUTHORIZATIONHANDLER_H
#define AUTHORIZATIONHANDLER_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

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
    QString GetUserName();
    QString GetUserPass();
};

#endif // AUTHORIZATIONHANDLER_H
