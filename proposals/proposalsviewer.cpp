#include "proposalsviewer.h"
#include <QDebug>

ProposalsViewer::ProposalsViewer()
{
    data = new DataManager("proposals.json");

    Filter *filter = new Filter;

    QMap<QString, QString> *proposalsAll = data->GetProposals();
    QMapIterator<QString, QString> it(*proposalsAll);
    QGridLayout *layout = new QGridLayout;
//    layout->
    ProposalItem *item;
    for (int i = 0; it.hasNext(); i++)
    {
        for (int j = 0; j < 3 && it.hasNext(); j++)
        {
            it.next();
            item = new ProposalItem(it.key(), it.value());
            item->setStyleSheet(".QWidget {"
                                "background: #f79216;"
                                "color: #228714; }");
            layout->addWidget(item, i, j);
        }
    }

    QWidget *blank = new QWidget;
    blank->setLayout(layout);

    QScrollArea *content = new QScrollArea;
    content->setWidget(blank);

    QSplitter *main = new QSplitter;
    main->addWidget(filter);
    main->addWidget(content);

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(main);

    this->setLayout(page);
}

