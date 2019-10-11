#include "proposalitem.h"
#include "proposalsviewer.h"

ProposalItem::ProposalItem(ProposalsViewer *p, QString head, QString text, QString design)
{
    parent = p;
    QLabel *HEAD = new QLabel(head);
    QLabel *TEXT = new QLabel(text);

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(HEAD);
    page->addWidget(TEXT);

//    QWidget *main = new QWidget;
//    main->setLayout(page);
//    main->setStyleSheet(design);
//    QVBoxLayout *mainL = new QVBoxLayout;
//    mainL->addWidget(main);
    this->setLayout(page);
    this->setStyleSheet(design);
//    this->setMinimumSize(60, 60);
    this->setFixedHeight(200);
    this->setFixedWidth(200);

    connect(this, SIGNAL(clicked()), this, SLOT(MakeDeal()));
}

void ProposalItem::MakeDeal()
{
    parent->SetMakeDialWindow(this);
}
