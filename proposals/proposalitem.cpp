#include "proposalitem.h"
#include "proposalsviewer.h"

ProposalItem::ProposalItem(ProposalsViewer *p, const QMap<QString, QVariant> &origin)
{
    parent = p;
    proposal = origin;

    QVBoxLayout *page = new QVBoxLayout;

    this->setLayout(page);
    this->setFixedHeight(200);
    this->setFixedWidth(200);

    connect(this, SIGNAL(clicked()), this, SLOT(MakeDeal()));
}

void ProposalItem::MakeDeal()
{
    parent->SetMakeDialWindow(this);
}
