#include "proposalsviewer.h"
#include "account/account.h"
#include <QDebug>

ProposalsViewer::ProposalsViewer(Account *p)
{
    user = p;

    data = new DataManager("proposals.json");

    tablet = new QGridLayout;
    tablet->setMargin(2);

    blank = new QWidget;
    blank->setLayout(tablet);
    blank->setStyleSheet("QWidget {"
                         "background: #89f0e9; }");

    Filter *filter = new Filter(data);
    connect(filter, SIGNAL(UpdateProposalTablet(QVector<QMap<QString, QVariant> >)), this, SLOT(BuidProposalTablet(QVector<QMap<QString, QVariant> >)));

    QScrollArea *content = new QScrollArea;
    content->setWidget(blank);

    main = new QSplitter;
    main->addWidget(filter);
    main->addWidget(content);

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(main);

    filter->FilterItems();
    this->setLayout(page);
}

void ProposalsViewer::SetMakeDialWindow(ProposalItem *house)
{
    if (user->GetName() == "")
    {
        user->LogIn();
        if (user->GetName() == "")
            return;
    }
    DealHandler *deal = new DealHandler(this, house);
    connect(deal, SIGNAL(AddToUser(QString)), user, SLOT(AddProposalToUser(QString)));
    deal->setModal(true);
    deal->exec();

    delete deal;
}

void ProposalsViewer::ClearLayout(QLayout *layout)
{
    if (!layout)
        return;
    while (auto item = layout->takeAt(0))
    {
        delete item->widget();
        ClearLayout(item->layout());
    }
}

void ProposalsViewer::BuidProposalTablet(QVector<QMap<QString, QVariant> > newProposals)
{
    qDebug() << "in viewer";
    QGridLayout *tablet = new QGridLayout;
    ProposalItem *item;
    for (int i = 0; i != newProposals.size(); i++)
    {
        item = new ProposalItem(this, newProposals[i]);
        tablet->addWidget(item, i / 2, i % 2);
    }
    QWidget *blank = new QWidget;
    blank->setLayout(tablet);
    QScrollArea *scroll = (QScrollArea *)main->widget(1);
    scroll->setWidget(blank);
}
