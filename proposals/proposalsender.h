#ifndef PROPOSALSENDER_H
#define PROPOSALSENDER_H

#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>

class ProposalSender : public QWidget
{
    Q_OBJECT
    QString name;
    QString roomNumber;
    QString price;
    QString location;
    QString nameOwner;
public:
    ProposalSender();
    void SetOwner(QString);
};

#endif // PROPOSALSENDER_H
