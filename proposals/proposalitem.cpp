#include "proposalitem.h"
#include "proposalsviewer.h"

ProposalItem::ProposalItem(ProposalsViewer *p, const QMap<QString, QVariant> &origin)
{
    parent = p;
    proposal = origin;


    QPixmap previewPhoto(proposal["photos"].toList()[0].toString());
    QLabel *photo = new QLabel("");
    photo->setStyleSheet("QLabel {"
                         "background: transparent;"
                         "color: #ffba00;"
                         "border: none; }");
    photo->setPixmap(previewPhoto);
    QLabel *location = new QLabel(proposal["location"].toString());
    location->setStyleSheet("QLabel {"
                         "background: transparent;"
                         "color: #ffba00;"
                            "border:none; }");
    QLabel *price = new QLabel(proposal["Price"].toString());
    price->setStyleSheet("QLabel {"
                         "background: transparent;"
                         "color: #ffba00;"
                         "border: none; }");

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(photo);
    page->addWidget(location);
    page->addWidget(price);

    this->setLayout(page);
    this->setFixedHeight(200);
    this->setFixedWidth(200);

    connect(this, SIGNAL(clicked()), this, SLOT(MakeDeal()));
    this->setStyleSheet("QWidget {"
                        "background: #ffe7d0;"
                        "border-radius: 4px; }"
                        "QWidget::hover {"
                        "border: 3px solid #ffba00; }");
}

void ProposalItem::MakeDeal()
{
    parent->SetMakeDialWindow(this);
}
