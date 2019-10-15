#ifndef USERSETTINGS_H
#define USERSETTINGS_H

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QListWidget>
#include <QMap>
#include <QVariant>
#include <QList>
#include <QListIterator>

class Account;

class UserSettings : public QWidget
{
    Q_OBJECT
    QMap<QString, QVariant> userData;
    QListWidget *listDeals;
    Account *Parent;
public:
    UserSettings(Account *, QMap<QString, QVariant>);
    void AddDeals(QString);
public slots:
    void RemoveDeal();
    void SaveSettings();
    void EditedFirstName(QString);
    void EditedSeconsName(QString);
    void EditedEmail(QString);
    void EditedPhoneNumber(QString);
    void EditedBankAccount(QString);
    void EditedLocation(QString);
};

#endif // USERSETTINGS_H
