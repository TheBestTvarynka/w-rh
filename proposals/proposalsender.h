#ifndef PROPOSALSENDER_H
#define PROPOSALSENDER_H

#include <QFileDialog>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>

#include "data/datamanager.h"

class ProposalSender : public QWidget
{
    Q_OBJECT
    QString roomNumber;
    QString price;
    QString location;
    QString bankAccount;
    QString nameOwner;
    QListWidget *filesList;
public:
    ProposalSender();
    void SetOwner(QString);
public slots:
    void EditedLocation(QString);
    void EditedNumberRooms(QString);
    void EditedBankAccount(QString);
    void EditedPrice(QString);
    void AddPhoto();
    void DeletePhoto();
    void SendProposal();
signals:
    void UpdateProposals();
};

#endif // PROPOSALSENDER_H
