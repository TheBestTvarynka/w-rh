#ifndef USERDATALOADER_H
#define USERDATALOADER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include <QMap>

class UserDataLoader
{
public:
    UserDataLoader(QString);
    QVariant GetMap(QString);
    ~UserDataLoader();
    QMap<QString,QVariant> *map;
};

#endif // USERDATALOADER_H
