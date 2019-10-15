#include "userdataloader.h"
#include <QDebug>

UserDataLoader::UserDataLoader()
{

}

QVariant UserDataLoader::GetPreference(QString preference)
{
    return (*userData)[preference];
}

QMap<QString, QVariant> *UserDataLoader::GetUserData()
{
    return userData;
}

void UserDataLoader::ReadUserData(QString user)
{
    QString val;
    QFile usersDB("usersdata.json");
    usersDB.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!usersDB.isOpen())
    {
        qDebug() << "file not found";
        return;
    }
    QString data = usersDB.readAll();
    usersDB.close();
    QJsonDocument grid_json = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject proposalsData = grid_json.object();

    QJsonObject prop = proposalsData[user].toObject();

    userData = new QMap<QString,QVariant>;
    for (QJsonObject::Iterator i = prop.begin(); i != prop.end(); i++)
    {
        userData->insert(i.key(),  i.value().toVariant());
    }
}

void UserDataLoader::WriteSettings(QMap<QString, QVariant>)
{
    qDebug() << "write settings";
}
