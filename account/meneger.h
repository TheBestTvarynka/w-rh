#ifndef MENEGER_H
#define MENEGER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFile>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>

class Meneger : public QWidget
{
    Q_OBJECT
    QListWidget *listDeals;
public:
    Meneger();
public slots:
    void Done();
};

#endif // MENEGER_H
