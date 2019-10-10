#include "datamanager.h"
#include <QDebug>
DataManager::DataManager(QString path)
{
    PATH = path;
    proposals = new QMap<QString, QString>;

    QFile usersDB("proposals.json");
    usersDB.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!usersDB.isOpen())
    {
        qDebug() << "no users file";
        return;
    }
    QString data = usersDB.readAll();
    usersDB.close();
    QJsonDocument grid_json = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject proposalsData = grid_json.object();

    for (QJsonObject::iterator i = proposalsData.begin(); i != proposalsData.end(); i++)
    {
        proposals->insert(i.key(), i.value().toString());
    }
}

QMap<QString, QString> *DataManager::GetProposals()
{
    return proposals;
}
