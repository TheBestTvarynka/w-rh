#include "filter.h"
#include <QDebug>

Filter::Filter(DataManager *ps)
{
    proposals = ps;
    QLabel *h = new QLabel("Filter");

    roomsTo = roomsFrom = 0;
    priceTo = priceFrom = 0;
    location = "";

    QLabel *roomsLabel = new QLabel("Number of rooms: ");
    QLineEdit *roomsLeftEdit = new QLineEdit("0");
    connect(roomsLeftEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditRoomsFrom(QString)));
    QLabel *betweenRooms = new QLabel(" - ");
    QLineEdit *roomsRightEdit = new QLineEdit("5");
    connect(roomsRightEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditRoomsTo(QString)));
    QHBoxLayout *rangeRooms = new QHBoxLayout;
    rangeRooms->addWidget(roomsLeftEdit);
    rangeRooms->addWidget(betweenRooms);
    rangeRooms->addWidget(roomsRightEdit);
    QVBoxLayout *rooms = new QVBoxLayout;
    rooms->addWidget(roomsLabel);
    rooms->addLayout(rangeRooms);

    QLabel *priceLabel = new QLabel("Range of price: ");
    QLineEdit *priceLeftEdit = new QLineEdit("0");
    connect(priceLeftEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditPriceFrom(QString)));
    QLabel *betweenPrice = new QLabel(" - ");
    QLineEdit *priceRightEdit = new QLineEdit("10000");
    connect(priceRightEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditPriceTo(QString)));
    QHBoxLayout *rangePrice = new QHBoxLayout;
    rangePrice->addWidget(priceLeftEdit);
    rangePrice->addWidget(betweenPrice);
    rangePrice->addWidget(priceRightEdit);
    QVBoxLayout *price = new QVBoxLayout;
    price->addWidget(priceLabel);
    price->addLayout(rangePrice);

    QLabel *locationLabel = new QLabel("Location:");
    QLineEdit *locationEdit = new QLineEdit("Kyiv");
    connect(locationEdit, SIGNAL(textEdited(const QString &)), this, SLOT(EditLocation(QString)));
    QVBoxLayout *location = new QVBoxLayout;
    location->addWidget(locationLabel);
    location->addWidget(locationEdit);

    QPushButton *submit = new QPushButton("Filter");
    connect(submit, SIGNAL(clicked()), this, SLOT(FilterItems()));

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(h);
    page->addLayout(rooms);
    page->addLayout(price);
    page->addLayout(location);
    page->addWidget(submit);
    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);
    page->addItem(space);

    this->setLayout(page);
    FilterItems();
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

void Filter::FilterItems()
{
    int number;
    QVector<QMap<QString, QVariant> > filteredProposals;
    DataManager::iterator it = proposals->begin();
    while (it.hasNext())
    {
        it.value();
        number = it.value()["Number of room"].toString().toInt();
        qDebug() << number << roomsFrom << roomsTo;
        if (number > roomsTo && number < roomsFrom)
        {
            qDebug() << "hide rooms";
            it.next();
            continue;
        }
        number = it.value()["Price"].toString().toInt();
        qDebug() << number << priceFrom << priceTo;
        if (number > priceTo && number < priceFrom)
        {
            qDebug() << "add price";
            it.next();
            continue;
        }
        if (location != it.value()["location"].toString())
        {
            qDebug() << "hide location";
            it.next();
            continue;
        }
        qDebug() << "add";
        filteredProposals.append(it.value());
        it.next();
    }

    emit UpdateProposalTablet(filteredProposals);
}
