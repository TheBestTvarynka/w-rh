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
        qDebug() << i.value().isArray(); // yes, it's array
        AddProposal(i.value());
//        i.value().toArray().
//        proposals->insert(i.key(), i.value().);
    }
}

void DataManager::AddProposal(QJsonValue item)
{
    QVector<QString> titles;
    titles.push_back("Name");
    titles.push_back("Address");
    titles.push_back("Number of rooms");
    titles.push_back("Price");
    titles.push_back("Photos");

    QMap<QString, QString> proposal;
    proposal.insert("Name", item["Name"].toString());
    proposal.insert("Address", item["Address"].toString());
    proposal.insert("Number of rooms", item["Number of rooms"].toString());
    proposal.insert("Price", item["Price"].toString());

    QJsonArray files = item["Photos"].toArray();
    for (QJsonArray::iterator i = files.begin(); i != files.end(); i++)
    {

    }

//    for (QJsonArray::iterator i = item.at(3); i != )
}

//QMap<QString, QString> *DataManager::GetProposals()
//{
//    return proposals;
//}
