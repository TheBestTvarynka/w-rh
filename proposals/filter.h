#ifndef FILTER_H
#define FILTER_H

#include <QPushButton>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QRegExp>
#include <QMessageBox>

#include "data/datamanager.h"
#include "proposalitem.h"

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
    void SetDataManaer(DataManager *newData);
public slots:
    void EditRoomsFrom(QString);
    void EditRoomsTo(QString);
    void EditPriceFrom(QString);
    void EditPriceTo(QString);
    void EditLocation(QString);
    void FilterItems();
signals:
    void UpdateProposalTablet(QVector<QMap<QString, QVariant> >);
};

#endif // FILTER_H
