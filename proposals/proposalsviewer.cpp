#include "proposalsviewer.h"
#include <QDebug>

ProposalsViewer::ProposalsViewer()
{
    data = new DataManager("proposals.json");

    Filter *filter = new Filter;

//    QMap<QString, QString> *proposalsAll = data->GetProposals();
//    QMapIterator<QString, QString> it(*proposalsAll);
//    QGridLayout *layout = new QGridLayout;
//    ProposalItem *item;
//    for (int i = 0; it.hasNext(); i++)
//    {
//        for (int j = 0; j < 3 && it.hasNext(); j++)
//        {
//            it.next();
//            item = new ProposalItem(this, it.key(), it.value(), "QWidget {"
//                                                                "background: #f79216;"
//                                                                "color: #228714; }");
//            layout->addWidget(item, i, j);
//        }
//    }
//    layout->setMargin(2);

//    QWidget *blank = new QWidget;
//    blank->setLayout(layout);
//    blank->setStyleSheet("QWidget {"
//                         "background: #89f0e9; }");

    QScrollArea *content = new QScrollArea;
//    content->setWidget(blank);

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


