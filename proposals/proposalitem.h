#ifndef PROPOSALITEM_H
#define PROPOSALITEM_H

#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ProposalsViewer;

class ProposalItem : public QPushButton
{
    Q_OBJECT
    ProposalsViewer *parent;
public:
    ProposalItem(ProposalsViewer *, QString, QString, QString);
public slots:
    void MakeDeal();
};

#endif // PROPOSALITEM_H
