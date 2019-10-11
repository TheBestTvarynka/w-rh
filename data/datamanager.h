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

class DataManager
{
    QString PATH;
    QVector<QMap<QString, QVariant> > proposals;
public:
    DataManager(QString);
    void AddProposal(QJsonValue);
//    QMap<QString, QString> *GetProposals();
};

#endif // DATAMANAGER_H
