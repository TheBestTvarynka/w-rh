#include "proposalsviewer.h"

ProposalsViewer::ProposalsViewer()
{
    data = new DataManager("proposals.json");

    Filter *filter = new Filter;
    QWidget *proposals = new QWidget;
    proposals->setStyleSheet("QWidget {"
                             "background: #cc5718; }");

    QSplitter *main = new QSplitter;
    main->addWidget(filter);
    main->addWidget(proposals);

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(main);

    this->setLayout(page);
}

