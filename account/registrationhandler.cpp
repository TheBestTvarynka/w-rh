#include "registrationhandler.h"
#include <QDebug>

RegistrationHandler::RegistrationHandler()
{
    QPushButton *registration = new QPushButton("Register");
    registration->setStyleSheet("QPushButton {"
                                "background: #ffe7d0;"
                                "color: #ffba00;"
                                "border-radius: 4px;"
                                "padding: 5px; }");
    connect(registration, SIGNAL(clicked()), this, SLOT(Register()));

    QVBoxLayout *page = new QVBoxLayout;
    page->addLayout(MakeField("username"));
    page->addLayout(MakeField("password"));
    page->addLayout(MakeField("First name"));
    page->addLayout(MakeField("Second name"));
    page->addLayout(MakeField("Location"));
    page->addLayout(MakeField("bank account"));
    page->addLayout(MakeField("email"));
    page->addLayout(MakeField("phone number"));
    page->addWidget(registration);

    this->setLayout(page);
}

QLayout *RegistrationHandler::MakeField(QString text)
{
    QLabel *textLabel = new QLabel(text);
    QLineEdit *textEdit = new QLineEdit;
    userData.insert(text, textEdit);

    QHBoxLayout *field = new QHBoxLayout;
    field->addWidget(textLabel);
    field->addWidget(textEdit);

    return field;
}

void RegistrationHandler::Register()
{
    const QJsonValue newUser = userData["username"]->text();
    QFile users("users.json");
    users.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!users.isOpen())
    {
        qDebug() << "users.json not opened";
        return;
    }
    QString data = users.readAll();
    qDebug() << "fewfwf";
    users.close();
    QJsonDocument usersDataDocument = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject usersData = usersDataDocument.object();
    usersData[userData["username"]->text()] = QJsonValue(userData["password"]->text());
    QFile usersWrite("users.json");
    usersWrite.open(QIODevice::WriteOnly | QIODevice::Text);
    usersWrite.write(QJsonDocument(usersData).toJson());
    usersWrite.close();

    username = userData["username"]->text();
    userData.remove("username");
    userData.remove("password");

    QVariantMap newData;
    QMapIterator<QString, QLineEdit *> it(userData);
    while (it.hasNext())
    {
        it.next();
        newData.insert(it.key(), it.value()->text());
    }
    newData.insert("permission", "user");
    newData.insert("deals", QJsonArray());
    QFile usersDB("usersdata.json");
    usersDB.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!usersDB.isOpen())
    {
        qDebug() << "usersdata.json not opened";
        return;
    }
    data = usersDB.readAll();
    usersDB.close();
    usersDataDocument = QJsonDocument::fromJson(data.toUtf8());
    usersData = usersDataDocument.object();
    usersData[username] = QJsonObject::fromVariantMap(newData);
    QFile usersDataWrite("usersdata.json");
    usersDataWrite.open(QIODevice::WriteOnly | QIODevice::Text);
    usersDataWrite.write(QJsonDocument(usersData).toJson());
    usersDataWrite.close();

    this->close();
}

