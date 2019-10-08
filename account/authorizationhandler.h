#ifndef AUTHORIZATIONHANDLER_H
#define AUTHORIZATIONHANDLER_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class AuthorizationHandler : public QDialog
{
    Q_OBJECT
    QString name;
    QString pass;
    QLineEdit *nameEdit;
    QLineEdit *passEdit;
public:
    AuthorizationHandler();
public slots:
    void LogIn();
};

#endif // AUTHORIZATIONHANDLER_H
