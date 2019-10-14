#ifndef BANK_H
#define BANK_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QMap>

class Bank
{
    QString PATH;
    QMap<QString, QString> usersAccounts;
public:
    Bank(QString);
};

#endif // BANK_H
