#ifndef USERSETTINGS_H
#define USERSETTINGS_H

#include "../data/userdataloader.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QString>

class UserSettings : public QWidget
{
    Q_OBJECT
    UserDataLoader *setting;
    QLineEdit *firstNameEdit;
    QLineEdit *secondNameEdit;
    QLineEdit *phoneEdit;
    QLineEdit *locationEdit;
    QLineEdit *emailEdit;
    QLineEdit *paymentEdit;
public:
    UserSettings();
public slots:
    void Set();
    void Close();
};

#endif // USERSETTINGS_H
