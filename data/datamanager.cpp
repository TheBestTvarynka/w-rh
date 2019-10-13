#include "datamanager.h"
#include <QDebug>
DataManager::DataManager(QString path)
{
    PATH = path;

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
        QMap<QString, QVariant> proposal = ConvertJsonValueToProposal(i.value());
        proposal.insert("id", i.key());
        proposals.push_back(proposal);
    }
}

QMap<QString, QVariant> DataManager::ConvertJsonValueToProposal(QJsonValue item)
{
    QJsonObject object = item.toObject();
    QMap<QString, QVariant> proposal;
    for (QJsonObject::iterator i = object.begin(); i != object.end(); i++)
    {
        if (i->isArray())
        {
            proposal.insert(i.key(), ConvertJsonArrayToList(i->toArray()));
        }
        else
        {
            proposal.insert(i.key().toUtf8(), i.value().toString());
        }
    }
    return proposal;
}

QList<QVariant> DataManager::ConvertJsonArrayToList(QJsonArray array)
{
    QList<QVariant> result;
    for (QJsonArray::iterator i = array.begin(); i != array.end(); i++)
    {
        result.push_back(i->toString());
    }
    return result;
}

