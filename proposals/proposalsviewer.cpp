#include "proposalsviewer.h"
#include <QDebug>

ProposalsViewer::ProposalsViewer()
{
    data = new DataManager("proposals.json");
    Filter *filter = new Filter;

    int position = 0;
    QGridLayout *layout = new QGridLayout;
    ProposalItem *item;
    DataManager::iterator it = data->begin();
    while (it.hasNext())
    {
        item = new ProposalItem(this, it.value());
        layout->addWidget(item, position / 2, position % 2);
        position++;
        it.next();
    }

    layout->setMargin(2);

    QWidget *blank = new QWidget;
    blank->setLayout(layout);
    blank->setStyleSheet("QWidget {"
                         "background: #89f0e9; }");

    QScrollArea *content = new QScrollArea;
    content->setWidget(blank);

    main = new QSplitter;
    main->addWidget(filter);
    main->addWidget(content);

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(main);

    this->setLayout(page);
}

void ProposalsViewer::SetMakeDialWindow(ProposalItem *house)
{
    DealHandler *deal = new DealHandler(this, house);
    deal->setModal(true);
    deal->exec();
}

