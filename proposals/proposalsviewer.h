#ifndef PROPOSALSVIEWER_H
#define PROPOSALSVIEWER_H

#include <QSplitter>
#include <QScrollArea>
#include <QGridLayout>

#include "../data/datamanager.h"
#include "proposalitem.h"
#include "filter.h"

class ProposalsViewer : public QWidget
{
    Q_OBJECT
    DataManager *data;
public:
    ProposalsViewer();
};

#endif // PROPOSALSVIEWER_H
