#ifndef USERDATALOADER_H
#define USERDATALOADER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QMap>
#include <QString>
#include <QVariant>

class UserDataLoader
{
    QString user;
    QMap<QString,QVariant> *map;
public:
    UserDataLoader(QString);
};

#endif // USERDATALOADER_H
