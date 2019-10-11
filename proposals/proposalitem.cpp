#include "proposalitem.h"

ProposalItem::ProposalItem(QString head, QString text, QString design)
{
    QLabel *HEAD = new QLabel(head);
    QLabel *TEXT = new QLabel(text);

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(HEAD);
    page->addWidget(TEXT);

    QWidget *main = new QWidget;
    main->setLayout(page);
    main->setStyleSheet(design);
    QVBoxLayout *mainL = new QVBoxLayout;
    mainL->addWidget(main);
    this->setLayout(mainL);
//    this->setMinimumSize(60, 60);
    this->setFixedHeight(200);
}
