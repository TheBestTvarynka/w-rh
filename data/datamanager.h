#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include <QString>

class DataManager
{
    QString PATH;
    QMap<QString, QString> *proposals;
public:
    DataManager(QString);
    QMap<QString, QString> *GetProposals();
};

#endif // DATAMANAGER_H
