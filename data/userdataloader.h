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
    QMap<QString, QVariant> *userData;
public:
    UserDataLoader();
    QVariant GetPreference(QString);
    QMap<QString, QVariant> *GetUserData();
    void ReadUserData(QString);
    void SetUserData();
    void WriteSettings(QMap<QString, QVariant>);
};

#endif // USERDATALOADER_H
