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

void UserDataLoader::ReadUserData(QString u)
{
    user = u;
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

void UserDataLoader::WriteSettings(QMap<QString, QVariant> newUserData)
{
    qDebug() << "write settings";
    QVariantMap newData;
    QMapIterator<QString, QVariant> it(newUserData);
    while (it.hasNext())
    {
        it.next();
        newData.insert(it.key(), it.value());
    }
    QJsonDocument jsonFile = QJsonDocument::fromVariant(newData);
    QFile usersDBRead("usersdata.json");
    usersDBRead.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!usersDBRead.isOpen())
    {
        qDebug() << "file not found";
        return;
    }
    QString data = usersDBRead.readAll();
    usersDBRead.close();
    QJsonDocument usersDataDocument = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject usersData = usersDataDocument.object();

    QJsonObject::iterator userPosition = usersData.find(user);
    userPosition.value() = jsonFile.object();

    QFile usersDBWrite("usersdata.json");
    usersDBWrite.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!usersDBWrite.isOpen())
    {
        qDebug() << "file not found";
        return;
    }
    usersDBWrite.write(QJsonDocument(usersData).toJson());
    usersDBWrite.close();
}
