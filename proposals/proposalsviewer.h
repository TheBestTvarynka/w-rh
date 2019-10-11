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

class ProposalsViewer : public QWidget
{
    Q_OBJECT
    DataManager *data;
    QSplitter *main;
public:
    ProposalsViewer();
    void SetMakeDialWindow(ProposalItem *);
};

#endif // PROPOSALSVIEWER_H
