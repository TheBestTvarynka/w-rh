#ifndef PROPOSALITEM_H
#define PROPOSALITEM_H

#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMap>

class ProposalsViewer;

class ProposalItem : public QPushButton
{
    Q_OBJECT
    ProposalsViewer *parent;
    QMap<QString, QString> data;
public:
    ProposalItem(ProposalsViewer *, const QMap<QString, QString> &, QString);
public slots:
    void MakeDeal();
};

#endif // PROPOSALITEM_H
