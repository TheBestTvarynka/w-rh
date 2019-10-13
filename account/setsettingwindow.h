#ifndef SETSETTINGWINDOW_H
#define SETSETTINGWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>

class SetSettingWindow : public QDialog
{
    Q_OBJECT
    QString FirstName;
    QString SecondName;
    QString Email;
    QString BankAccount;
    QString Location;
    QString PhoneNumber;
    QString Deals;
    QLineEdit *FirstNameEdit;
    QLineEdit *SecondNameEdit;
    QLineEdit *EmailEdit;
    QLineEdit *BankAccountEdit;
    QLineEdit *LocationEdit;
    QLineEdit *PhoneNumberEdit;
    QLineEdit *DealsEdit;
public:
    SetSettingWindow();
public slots:
    void SetSetting();
};


#endif // SETSETTINGWINDOW_H
