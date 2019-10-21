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
    QVector<QCheckBox *> weekDays;
    QString managerName;
public:
    manager(QString);
    void ReadMeetings();
    void ReadSchedule();
public slots:
    void WriteMeetings();
    void Visited();
    void WriteSchedule();
};

#endif // MANAGER_H
