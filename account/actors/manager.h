#ifndef MANAGER_H
#define MANAGER_H

#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSpacerItem>
#include <QCheckBox>
#include <QVector>
#include <QSplitter>

class manager : public QWidget
{
    Q_OBJECT
    QListWidget *meetingsList;
    QString managerName;
public:
    manager(QString);
    void ReadSchedule();
public slots:
    void WriteSchedule();
    void Visited();
};

#endif // MANAGER_H
