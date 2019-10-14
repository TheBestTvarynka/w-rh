#include "bank.h"
#include <QDebug>

Bank::Bank(QString path)
{
    qDebug() << "in bank";
    PATH = path;

    QFile usersDB(PATH);
    usersDB.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!usersDB.isOpen())
    {
        qDebug() << "no users file";
        return;
    }
    QString data = usersDB.readAll();
    usersDB.close();
    QJsonDocument users = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject usersBankAccounts = users.object();

    for (QJsonObject::Iterator user = usersBankAccounts.begin(); user != usersBankAccounts.end(); user++)
    {
        usersAccounts.insert(user.key(), user.value().toString());
    }
    qDebug() << usersBankAccounts;
}
