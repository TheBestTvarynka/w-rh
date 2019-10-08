#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QSplitter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QLabel>

class Account : public QSplitter
{
    Q_OBJECT
    QString username;
public:
    Account(Qt::Orientation orientation);
};

#endif // ACCOUNT_H
