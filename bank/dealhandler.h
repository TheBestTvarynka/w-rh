#ifndef DEALHANDLER_H
#define DEALHANDLER_H

#include <QDialog>
#include <QPushButton>
#include <QVector>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../proposals/proposalitem.h"

class DealHandler : public QDialog
{
    Q_OBJECT
    ProposalItem *item;
    QVector<QString> titles;
    void CreateTitles();
public:
    DealHandler(QWidget *, ProposalItem *);
};

#endif // DEALHANDLER_H
