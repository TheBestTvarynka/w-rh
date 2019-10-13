#include "filter.h"

Filter::Filter(DataManager *ps)
{
    proposals = ps;
    QLabel *h = new QLabel("Filter");

    roomsTo = roomsFrom = 0;
    priceTo = priceFrom = 0;
    location = "";

    QLabel *roomsLabel = new QLabel("Number of rooms: ");
    QLineEdit *roomsLeftEdit = new QLineEdit;
    connect(roomsLeftEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditRoomsFrom(QString)));
    QLabel *betweenRooms = new QLabel(" - ");
    QLineEdit *roomsRightEdit = new QLineEdit;
    connect(roomsRightEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditRoomsTo(QString)));
    QHBoxLayout *rangeRooms = new QHBoxLayout;
    rangeRooms->addWidget(roomsLeftEdit);
    rangeRooms->addWidget(betweenRooms);
    rangeRooms->addWidget(roomsRightEdit);
    QVBoxLayout *rooms = new QVBoxLayout;
    rooms->addWidget(roomsLabel);
    rooms->addLayout(rangeRooms);

    QLabel *priceLabel = new QLabel("Range of price: ");
    QLineEdit *priceLeftEdit = new QLineEdit;
    connect(priceLeftEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditPriceFrom(QString)));
    QLabel *betweenPrice = new QLabel(" - ");
    QLineEdit *priceRightEdit = new QLineEdit;
    connect(priceRightEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditPriceTo(QString)));
    QHBoxLayout *rangePrice = new QHBoxLayout;
    rangePrice->addWidget(priceLeftEdit);
    rangePrice->addWidget(betweenPrice);
    rangePrice->addWidget(priceRightEdit);
    QVBoxLayout *price = new QVBoxLayout;
    price->addWidget(priceLabel);
    price->addLayout(rangePrice);

    QLabel *locationLabel = new QLabel("Location:");
    QLineEdit *locationEdit = new QLineEdit;
    connect(locationEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditLocation(QString)));
    QVBoxLayout *location = new QVBoxLayout;
    location->addWidget(locationLabel);
    location->addWidget(locationEdit);

    QPushButton *submit = new QPushButton("Filter");

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(h);
    page->addLayout(rooms);
    page->addLayout(price);
    page->addLayout(location);
    page->addWidget(submit);
    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);
    page->addItem(space);

    this->setLayout(page);
}

void Filter::EditRoomsFrom(QString from)
{
    QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
    if (re.exactMatch(from))
        roomsFrom = from.toInt();
    else
        QMessageBox::warning(this, "wrong data", "wrong data in rooms from");
}

void Filter::EditRoomsTo(QString to)
{
    QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
    if (re.exactMatch(to))
        roomsTo = to.toInt();
    else
        QMessageBox::warning(this, "wrong data", "wrong data in rooms to");
}

void Filter::EditPriceFrom(QString from)
{
    QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
    if (re.exactMatch(from))
        priceFrom = from.toInt();
    else
        QMessageBox::warning(this, "wrong data", "wrong data in rooms from");
}

void Filter::EditPriceTo(QString to)
{
    QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
    if (re.exactMatch(to))
        priceTo = to.toInt();
    else
        QMessageBox::warning(this, "wrong data", "wrong data in rooms to");
}

void Filter::EditLocation(QString newLocation)
{
    location = newLocation;
}
