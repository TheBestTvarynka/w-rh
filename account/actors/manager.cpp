#include "manager.h"
#include <QDebug>

manager::manager(QString name) : QWidget(nullptr)
{
    managerName = name;
    QLabel *meetingsLabel = new QLabel("Next meetings:");
    meetingsList = new QListWidget;
    meetingsList->setStyleSheet("QListWidget {"
                                "background: #ffe7d0;"
                                "border-radius: 4px; }"
                                "QListWidget::item:hover { background: #b88c53; }"
                                "QListWidget::item:selected { background: #f095ee; }");

    QPushButton *visited = new QPushButton("visited");
    connect(visited, SIGNAL(clicked()), this, SLOT(Visited()));

    QPushButton *save = new QPushButton("Save settins");
    connect(save, SIGNAL(clicked()), this, SLOT(WriteSchedule()));

    QSpacerItem *space = new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Preferred);
    QHBoxLayout *downPanel = new QHBoxLayout;
    downPanel->addWidget(visited);
    downPanel->addItem(space);
    downPanel->addWidget(save);

    QCheckBox *day;
    QVector<QString> daysWeek = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    QHBoxLayout *week = new QHBoxLayout;
    week->setSpacing(5);
    for (int i = 0; i < 7; i++)
    {
        day = new QCheckBox(daysWeek[i]);
        week->addWidget(day);
        weekDays.push_back(day);
    }

    QPushButton *updateSchedule = new QPushButton("Update schedule");
    connect(updateSchedule, SIGNAL(clicked()), this, SLOT(WriteSchedule()));
    QSpacerItem *scheduleSpace = new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Preferred);
    QHBoxLayout *submitSchedule = new QHBoxLayout;
    submitSchedule->addItem(scheduleSpace);
    submitSchedule->addWidget(updateSchedule);

    QVBoxLayout *schedule = new QVBoxLayout;
    schedule->addLayout(week);
    schedule->addLayout(submitSchedule);

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(meetingsLabel);
    page->addWidget(meetingsList);
    page->addLayout(downPanel);
    page->addLayout(schedule);

    this->setLayout(page);
    this->setStyleSheet("QWiget {"
                        "background: #ffba00; }"
                        "QCheckBox::indicator {"
                        "    width: 25px;"
                        "    height: 25px; }"
                        "QCheckBox::indicator:unchecked {"
                        "    background: #ffba00; }"
                        "QCheckBox::indicator:unchecked:hover {"
                        "    background: #ba9841; }"
                        "QCheckBox::indicator:unchecked:pressed {"
                        "    background: #52431e; }"
                        "QCheckBox::indicator:checked {"
                        "    background: #2b241e; }"
                        "QCheckBox::indicator:checked:hover {"
                        "    background: #7e5c05; }"
                        "QCheckBox::indicator:checked:pressed {"
                        "    background: #52431e; }");

    ReadSchedule();
    ReadMeetings();
}

void manager::ReadMeetings()
{
    QFile managersMeetings("meetings.json");
    managersMeetings.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!managersMeetings.isOpen())
    {
        qDebug() << "file not found";
        return;
    }
    QString data = managersMeetings.readAll();
    managersMeetings.close();
    QJsonObject schedules = QJsonDocument::fromJson(data.toUtf8()).object();
    qDebug() << schedules;
    QJsonArray curManagerSchedule = schedules[managerName].toArray();
    qDebug() << curManagerSchedule;
    for (QJsonArray::iterator it = curManagerSchedule.begin(); it != curManagerSchedule.end(); it++)
    {
        meetingsList->addItem(it->toString());
    }
}

void manager::ReadSchedule()
{
    QFile managerSchedule("managers.json");
    managerSchedule.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!managerSchedule.isOpen())
    {
        qDebug() << "file not found";
        return;
    }
    QString data = managerSchedule.readAll();
    managerSchedule.close();
    QJsonArray schedule = QJsonDocument::fromJson(data.toUtf8())[managerName].toArray();
    qDebug() << schedule;
    for (QJsonArray::iterator it = schedule.begin(); it != schedule.end(); it++)
    {
        weekDays[it->toInt()]->setCheckState(Qt::CheckState::Checked);
    }
}

void manager::WriteMeetings()
{
    QJsonArray restMeetings;
    for (int i = 0; i < meetingsList->count(); i++)
    {
        restMeetings.push_back(meetingsList->item(i)->text());
    }
    qDebug() << restMeetings;
    QFile managersMeetings("meetings.json");
    managersMeetings.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!managersMeetings.isOpen())
    {
        qDebug() << "file not found";
        return;
    }
    QString data = managersMeetings.readAll();
    managersMeetings.close();
    QJsonObject schedules = QJsonDocument::fromJson(data.toUtf8()).object();

    schedules[managerName] = QJsonValue(restMeetings);

    QFile meetingsWrite("meetings.json");
    meetingsWrite.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!meetingsWrite.isOpen())
    {
        qDebug() << "file not found";
        return;
    }
    meetingsWrite.write(QJsonDocument(schedules).toJson());
    meetingsWrite.close();
}

void manager::Visited()
{
    meetingsList->takeItem(meetingsList->currentRow());
}

void manager::WriteSchedule()
{
    QJsonArray newSchedule;
    for (int i = 0; i < weekDays.size(); i++)
    {
        if (weekDays[i]->isChecked())
        {
            newSchedule.push_back(i);
        }
    }

    QFile managersSchedule("managers.json");
    managersSchedule.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!managersSchedule.isOpen())
    {
        qDebug() << "file not found";
        return;
    }
    QString data = managersSchedule.readAll();
    managersSchedule.close();
    QJsonObject schedules = QJsonDocument::fromJson(data.toUtf8()).object();

    schedules[managerName] = QJsonValue(newSchedule);

    QFile schedulesWrite("managers.json");
    schedulesWrite.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!schedulesWrite.isOpen())
    {
        qDebug() << "file not found";
        return;
    }
    schedulesWrite.write(QJsonDocument(schedules).toJson());
    schedulesWrite.close();
}
