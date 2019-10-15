#ifndef DEALHANDLER_H
#define DEALHANDLER_H

#include <QDialog>
#include <QPushButton>
#include <QVector>
#include <QLabel>
#include <QLineEdit>
#include <QFile>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateTimeEdit>

#include "../proposals/proposalitem.h"
#include "bank.h"

class DealHandler : public QDialog
{
    Q_OBJECT
    ProposalItem *item;
    QString bancAccountNumber;
    QLineEdit *bankAccount;
    QDateTimeEdit *datetimeEdit;
public:
    DealHandler(QWidget *, ProposalItem *);
public slots:
    void SetBankAccountNumber(QString);
    void MakeDial();
signals:
    void AddToUser(QString);
};

#endif // DEALHANDLER_H
