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
        qDebug() << "item: " << i.value();
        proposals.push_back(ConvertJsonValueToProposal(i.value()));
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
    qDebug() << "Read: " << proposal;
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

//QMap<QString, QString> *DataManager::GetProposals()
//{
//    return proposals;
//}
