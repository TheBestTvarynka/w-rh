#ifndef USERSETTINGS_H
#define USERSETTINGS_H

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QListWidget>
#include <QMap>
#include <QVariant>
#include <QList>
#include <QListIterator>

class UserSettings : public QWidget
{
    Q_OBJECT
    QMap<QString, QVariant> *userData;
public:
    UserSettings(QMap<QString, QVariant> *);
};

#endif // USERSETTINGS_H
