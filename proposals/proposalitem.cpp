#include "proposalitem.h"
#include "proposalsviewer.h"

ProposalItem::ProposalItem(ProposalsViewer *p, const QMap<QString, QVariant> &origin)
{
    parent = p;
    proposal = origin;


    QPixmap previewPhoto(proposal["photos"].toList()[0].toString());
    QLabel *photo = new QLabel("");
//    photo->setStyleSheet("border-image:url(" + proposal["photos"].toList()[0].toString() + ");");
    photo->setPixmap(previewPhoto);
    QLabel *location = new QLabel(proposal["location"].toString());
    QLabel *price = new QLabel(proposal["Price"].toString());

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(photo);
    page->addWidget(location);
    page->addWidget(price);

    this->setLayout(page);
    this->setFixedHeight(200);
    this->setFixedWidth(200);

    connect(this, SIGNAL(clicked()), this, SLOT(MakeDeal()));
}

void ProposalItem::MakeDeal()
{
    parent->SetMakeDialWindow(this);
}
