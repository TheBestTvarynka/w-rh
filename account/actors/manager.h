#ifndef MANAGER_H
#define MANAGER_H

#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class manager : public QWidget
{
    Q_OBJECT
    QListWidget *meetingsList;
    QString managerName;
public:
    manager(QString);
    void ReadSchedule();
    void WriteSchedule();
public slots:
    void Visited();
};

#endif // MANAGER_H
