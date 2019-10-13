#include "userdataloader.h"

UserDataLoader::UserDataLoader(QString account)
{
    QString val;
        QFile usersDB("userdata.json");
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

QVariant UserDataLoader::GetMap(QString key){
    return map->find(key).value();
}

UserDataLoader::~UserDataLoader(){
    QVariantMap vmap;

    QMapIterator<QString, QVariant> i(*map);
    while (i.hasNext()) {
        i.next();
        vmap.insert(i.key(), i.value());
    }

    QJsonDocument json = QJsonDocument::fromVariant(vmap);
}
