#include "manager.h"
#include <QDebug>

manager::manager(QString name) : QWidget(nullptr)
{
    managerName = name;
    QLabel *meetingsLabel = new QLabel("Next meetings:");
    meetingsList = new QListWidget;

    QPushButton *visited = new QPushButton("visited");
    connect(visited, SIGNAL(clicked()), this, SLOT(Visited()));

    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(meetingsLabel);
    page->addWidget(meetingsList);
    page->addWidget(visited);

    this->setLayout(page);
    this->setStyleSheet("QWiget {"
                        "background: black; }");

    ReadSchedule();
}

void manager::ReadSchedule()
{
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
    QJsonArray curManagerSchedule = schedules[managerName].toArray();
    for (QJsonArray::iterator it = curManagerSchedule.begin(); it != curManagerSchedule.end(); it++)
    {
        meetingsList->addItem(it->toString());
    }
}

void manager::WriteSchedule()
{
    QJsonArray restMeetings;
    for (int i = 0; i < meetingsList->count(); i++)
    {
        restMeetings.push_back(meetingsList->takeItem(i)->text());
    }
    qDebug() << restMeetings;
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

    schedules[managerName] = QJsonValue(restMeetings);

    QFile managersWrite("usersdata.json");
    managersWrite.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!managersWrite.isOpen())
    {
        qDebug() << "file not found";
        return;
    }
    managersWrite.write(QJsonDocument(schedules).toJson());
    managersWrite.close();
}

void manager::Visited()
{
    meetingsList->takeItem(meetingsList->currentRow());
}
