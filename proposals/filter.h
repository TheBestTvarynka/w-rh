#ifndef FILTER_H
#define FILTER_H

#include <QPushButton>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRegExp>
#include <QMessageBox>

#include "data/datamanager.h"

class Filter : public QWidget
{
    Q_OBJECT
    DataManager *proposals;
    int roomsFrom;
    int roomsTo;
    int priceFrom;
    int priceTo;
    QString location;
public:
    Filter(DataManager *);
public slots:
    void EditRoomsFrom(QString);
    void EditRoomsTo(QString);
    void EditPriceFrom(QString);
    void EditPriceTo(QString);
    void EditLocation(QString);
};

#endif // FILTER_H
