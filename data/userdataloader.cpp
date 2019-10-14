#include "userdataloader.h"

UserDataLoader::UserDataLoader(QString account)
{
    QString val;
        QFile usersDB("usersdata.json");
        usersDB.open(QIODevice::ReadOnly | QIODevice::Text);
        QString data = usersDB.readAll();
        usersDB.close();
        QJsonDocument grid_json = QJsonDocument::fromJson(data.toUtf8());
        QJsonObject proposalsData = grid_json.object();

        QJsonObject prop = proposalsData[account].toObject();

        map = new QMap<QString,QVariant>;
        for (QJsonObject::Iterator i = prop.begin(); i != prop.end(); i++)
        {
            map->insert(i.key(),  i.value().toVariant());
        }
}

QVariant UserDataLoader::GetVariant(QString key){
    return map->find(key).value();
}

void UserDataLoader::SetVariant(QString key,QString value){
    //map->erase(map->find(key));
    (*this->map)[key] = value;
}

void UserDataLoader::WriteFile(QString account){
    QFile usersDB("usersdata.json");
    usersDB.open(QIODevice::ReadWrite | QIODevice::Text);
    QString data = usersDB.readAll();
    usersDB.close();
    QVariantMap vmap;

    QMapIterator<QString, QVariant> i(*map);
    while (i.hasNext()) {
        i.next();
        vmap.insert(i.key(), i.value());
    }

    QJsonDocument json = QJsonDocument::fromVariant(vmap);
    QString strJson(json.toJson(QJsonDocument::Compact));
    int comPos = data.indexOf(account + "\" : ");
    int comEndPos = data.indexOf("}", comPos);
    int odds = account.size() + 4;
    data.remove(odds + comPos, comEndPos - comPos - odds + 1);
    data.insert(odds + comPos, strJson);
    usersDB.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
    QTextStream writeStream(&usersDB);
    writeStream << data;
    usersDB.close();
}

UserDataLoader::~UserDataLoader(){}
