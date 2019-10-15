#ifndef PROPOSALSVIEWER_H
#define PROPOSALSVIEWER_H

#include <QSplitter>
#include <QScrollArea>
#include <QGridLayout>
#include <QFrame>

#include "../data/datamanager.h"
#include "../bank/dealhandler.h"
#include "proposalitem.h"
#include "filter.h"

class Account;

class ProposalsViewer : public QWidget
{
    Q_OBJECT
    DataManager *data;
    Filter *filter;
    QSplitter *main;
    QGridLayout *tablet;
    QWidget *blank;
    Account *user;
public:
    ProposalsViewer(Account *);
    void SetMakeDialWindow(ProposalItem *);
    void ClearLayout(QLayout *t);
public slots:
    void BuidProposalTablet(QVector<QMap<QString, QVariant> >);
    void UpdateProposal();
};

#endif // PROPOSALSVIEWER_H
