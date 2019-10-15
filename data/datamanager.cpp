#include "datamanager.h"
#include <QDebug>

DataManager::DataManager(QString path)
{
    PATH = path;

    QFile proposalsDB("proposals.json");
    proposalsDB.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!proposalsDB.isOpen())
    {
        qDebug() << "no proposals file";
        return;
    }
    QString data = proposalsDB.readAll();
    proposalsDB.close();
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

QJsonObject DataManager::ConvertMapToJsonObject(QMap<QString, QVariant> map)
{
    QJsonObject object;
    QMapIterator<QString, QVariant> it(map);
    while (it.hasNext())
    {
        it.next();
        object.insert(it.key(), it.value().toJsonValue());
    }
    return object;
}

void DataManager::AddProposal(QMap<QString, QVariant> newProposal)
{
    proposals.push_back(newProposal);
    WriteProposals();
}

void DataManager::WriteProposals()
{
    QJsonObject newProposals;
    QMap<QString, QVariant> currentProposal;
    for (int i = 0; i < proposals.size(); i++)
    {
        currentProposal = proposals[i];
        newProposals.insert(QString::number(i + 1), ConvertMapToJsonObject(currentProposal));
    }
    QFile proposalsDB("proposals.json");
    proposalsDB.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!proposalsDB.isOpen())
    {
        qDebug() << "no proposals file";
        return;
    }
    proposalsDB.write(QJsonDocument(newProposals).toJson());
    proposalsDB.close();
}

