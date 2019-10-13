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
#include "bank.h"

class DealHandler : public QDialog
{
    Q_OBJECT
    ProposalItem *item;
    QString bancAccountNumber;
    QLineEdit *bankAccount;
public:
    DealHandler(QWidget *, ProposalItem *);
public slots:
    void SetBankAccountNumber(QString);
    void MakeDial();
};

#endif // DEALHANDLER_H
