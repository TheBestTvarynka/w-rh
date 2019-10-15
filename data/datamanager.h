#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include <QVector>
#include <QVectorIterator>
#include <QVariant>
#include <QString>
#include <QList>
#include <iterator>

class DataManager
{
    QString PATH;
    QVector<QMap<QString, QVariant> > proposals;
public:
    DataManager(QString);
    QMap<QString, QVariant> ConvertJsonValueToProposal(QJsonValue);
    QList<QVariant> ConvertJsonArrayToList(QJsonArray);
    QJsonObject ConvertMapToJsonObject(QMap<QString, QVariant>);
    void AddProposal(QMap<QString, QVariant>);
    void WriteProposals();
    class iterator : public std::iterator<
            std::input_iterator_tag,
            QMap<QString, QVariant>,
            long,
            const QMap<QString, QVariant>*,
            QMap<QString, QVariant>>
    {
        QVectorIterator<QMap<QString, QVariant> > *it;
        public:
            iterator(const QVector<QMap<QString, QVariant> > &origin, bool start)
            {
                it = new QVectorIterator<QMap<QString, QVariant> >(origin);
                if (!start)
                    it->toBack();
            }
            iterator& operator++()
            {
                it->next();
                return *this;
            }
            iterator operator++(int)
            {
                iterator old = *this;
                ++(*this);
                return old;
            }
            QMap<QString, QVariant> value()
            {
                return it->peekNext();
            }
            bool hasNext()
            {
                return it->hasNext();
            }
            void next()
            {
                it->next();
            }

    };
    iterator begin() { return  iterator(proposals, true); }
    iterator end() { return  iterator(proposals, false); }
};

#endif // DATAMANAGER_H
