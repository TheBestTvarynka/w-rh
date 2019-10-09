#include "filter.h"

Filter::Filter()
{
    QLabel *h = new QLabel("Filter");

    QLabel *roomLabel = new QLabel("Number of rooms: ");
    QLineEdit *roomEdit = new QLineEdit;
    QHBoxLayout *room = new QHBoxLayout;
    room->addWidget(roomLabel);
    room->addWidget(roomEdit);

    QLabel *priceLabel = new QLabel("Range of price: ");
    QLineEdit *priceLeftEdit = new QLineEdit;
    QLabel *between = new QLabel(" - ");
    QLineEdit *priceRightEdit = new QLineEdit;
    QHBoxLayout *rangePrice = new QHBoxLayout;
    rangePrice->addWidget(priceLeftEdit);
    rangePrice->addWidget(between);
    rangePrice->addWidget(priceRightEdit);
    QVBoxLayout *price = new QVBoxLayout;
    price->addWidget(priceLabel);
    price->addLayout(rangePrice);

    QLabel *locationLabel = new QLabel("Location:");
    QLineEdit *locationEdit = new QLineEdit;
    QVBoxLayout *location = new QVBoxLayout;
    location->addWidget(locationLabel);
    location->addWidget(locationEdit);

    QPushButton *submit = new QPushButton("Filter");

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(h);
    page->addLayout(room);
    page->addLayout(price);
    page->addLayout(location);
    page->addWidget(submit);
    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);
    page->addItem(space);

    this->setLayout(page);
}
