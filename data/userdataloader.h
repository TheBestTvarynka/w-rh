#ifndef USERDATALOADER_H
#define USERDATALOADER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include <QMap>

class UserDataLoader
{
    QMap<QString,QVariant> *map;
public:
    UserDataLoader(QString);
    QVariant GetVariant(QString);
    void SetVariant(QString,QString);
    void WriteFile(QString);
    ~UserDataLoader();
};

#endif // USERDATALOADER_H
