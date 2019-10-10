#ifndef PROPOSALSVIEWER_H
#define PROPOSALSVIEWER_H

#include <QSplitter>

#include "../data/datamanager.h"
#include "filter.h"

class ProposalsViewer : public QWidget
{
    Q_OBJECT
    DataManager *data;
public:
    ProposalsViewer();
};

#endif // PROPOSALSVIEWER_H
