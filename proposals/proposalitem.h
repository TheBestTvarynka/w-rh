#ifndef PROPOSALITEM_H
#define PROPOSALITEM_H

#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMap>
#include <QVariant>

class ProposalsViewer;

class ProposalItem : public QPushButton
{
    Q_OBJECT
    ProposalsViewer *parent;
    QMap<QString, QVariant> proposal;
public:
    ProposalItem(ProposalsViewer *, const QMap<QString, QVariant> &);
public slots:
    void MakeDeal();
};

#endif // PROPOSALITEM_H
