#include "proposalitem.h"

ProposalItem::ProposalItem(QString head, QString text)
{
    QLabel *HEAD = new QLabel(head);
    QLabel *TEXT = new QLabel(text);

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(HEAD);
    page->addWidget(TEXT);

    this->setLayout(page);
    this->setMinimumSize(60, 60);
}
