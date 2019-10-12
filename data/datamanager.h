#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include <QVector>
#include <QVariant>
#include <QString>
#include <QList>

class DataManager
{
    QString PATH;
    QVector<QMap<QString, QVariant> > proposals;
public:
    DataManager(QString);
    QMap<QString, QVariant> ConvertJsonValueToProposal(QJsonValue);
    QList<QVariant> ConvertJsonArrayToList(QJsonArray);
};

#endif // DATAMANAGER_H
