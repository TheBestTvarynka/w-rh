#include "proposalitem.h"
#include "proposalsviewer.h"

ProposalItem::ProposalItem(ProposalsViewer *p, const QMap<QString, QString> &origin, QString design)
{
    parent = p;
//    QLabel *HEAD = new QLabel(head);
//    QLabel *TEXT = new QLabel(text);

    QVBoxLayout *page = new QVBoxLayout;
//    page->addWidget(HEAD);
//    page->addWidget(TEXT);

    this->setLayout(page);
    this->setStyleSheet(design);
    this->setFixedHeight(200);
    this->setFixedWidth(200);

    connect(this, SIGNAL(clicked()), this, SLOT(MakeDeal()));
}

void ProposalItem::MakeDeal()
{
    parent->SetMakeDialWindow(this);
}
