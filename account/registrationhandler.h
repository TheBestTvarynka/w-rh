#ifndef REGISTRATIONHANDLER_H
#define REGISTRATIONHANDLER_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMap>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QVariantMap>

class RegistrationHandler : public QDialog
{
    Q_OBJECT
    QMap<QString, QLineEdit *> userData;
    QString username;
public:
    RegistrationHandler();
    QLayout *MakeField(QString);
    QString GetUserName() {return username; }
public slots:
    void Register();
};

#endif // REGISTRATIONHANDLER_H
