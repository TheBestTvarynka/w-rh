#ifndef PROPOSALITEM_H
#define PROPOSALITEM_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ProposalItem : public QWidget
{
    Q_OBJECT
public:
    ProposalItem(QString, QString, QString);
};

#endif // PROPOSALITEM_H
