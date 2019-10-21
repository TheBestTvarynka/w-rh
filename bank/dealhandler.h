#ifndef DEALHANDLER_H
#define DEALHANDLER_H

#include <QDialog>
#include <QPushButton>
#include <QVector>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCalendarWidget>
#include <QDate>
#include <QTableView>
#include <QComboBox>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QMessageBox>

#include "../proposals/proposalitem.h"
#include "bank.h"

class DealHandler : public QDialog
{
    Q_OBJECT
    ProposalItem *item;
    QString bancAccountNumber;
    QLineEdit *bankAccount;
    QComboBox *managerSelect;
    QComboBox *timeEdit;
    QVariantMap managersGraphic, managersMeetings;
    QCalendarWidget *calendar;
    QLabel *date, *time;
    QDateTime *inspectionTime;
public:
    DealHandler(QWidget *, ProposalItem *);
public slots:
    void ScheduleRevisionDate();
    void ScheduleRevisionTime();
    void RefreshVisibleDays();
    QVariantMap ParseManagersGraphic(QString);
    QVariantMap ParseManagersMeetings(QString);
    QStringList ParseMeeting(QVariant);
    void RefreshTime();
    void WriteMeetings(QString, QString);
    void SetBankAccountNumber(QString);
    void MakeDial();
signals:
    void AddToUser(QString);
};

#endif // DEALHANDLER_H
