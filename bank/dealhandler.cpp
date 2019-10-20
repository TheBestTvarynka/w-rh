#include "dealhandler.h"
#include <QDebug>

DealHandler::DealHandler(QWidget *parent, ProposalItem *i) : QDialog(parent)
{
    item = i;
    QVBoxLayout *page = new QVBoxLayout;

    QHBoxLayout *inscription;
    QLabel *title, *value;
    QMap<QString, QVariant> *details = i->GetProposal();
    for (QMap<QString, QVariant>::Iterator i = details->begin(); i != details->end(); i++)
    {
        if (i->type() == QVariant::Type::List)
        {
            title = new QLabel(i.key());
            QList<QVariant> photos = i.value().toList();
            QVBoxLayout *collectionPhoto = new QVBoxLayout;
            for (QList<QVariant>::Iterator photo = photos.begin(); photo != photos.end(); photo++)
            {
                value = new QLabel(photo->toString());
                collectionPhoto->addWidget(value);
            }
            QVBoxLayout *photosLayout = new QVBoxLayout;
            photosLayout->addWidget(title);
            photosLayout->addLayout(collectionPhoto);
            page->addLayout(photosLayout);
        }
        else
        {
            title = new QLabel(i.key() + ": ");
            value = new QLabel(i.value().toString());
            inscription = new QHBoxLayout;
            inscription->addWidget(title);
            inscription->addWidget(value);
            page->addLayout(inscription);
        }
    }

    title = new QLabel("Enter your bank account: ");
    bankAccount = new QLineEdit;
    bankAccount->setStyleSheet("QLineEdit {"
                               "background: #ffba00;"
                               "margin-top: 3px;"
                               "margin-bottom: 3px; }");
    connect(bankAccount, SIGNAL(textEdited(const QString &)), this, SLOT(SetBankAccountNumber(QString)));
    QVBoxLayout *bank = new QVBoxLayout;
    bank->addWidget(title);
    bank->addWidget(bankAccount);

    QSpacerItem *space_before_calendar = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Expanding);

    QCalendarWidget *calendar = new QCalendarWidget();
    calendar->setSelectionMode(QCalendarWidget::SingleSelection);
    //You can select the dates only for a week from today
    calendar->setNavigationBarVisible(false);
    if(QDate::currentDate().dayOfWeek() == Qt::Saturday) calendar->setDateRange(QDate::currentDate().addDays(2), QDate::currentDate().addDays(Qt::Saturday-QDate::currentDate().addDays(2).dayOfWeek()));
    else if(QDate::currentDate().dayOfWeek() == Qt::Sunday) calendar->setDateRange(QDate::currentDate().addDays(1), QDate::currentDate().addDays(Qt::Saturday-QDate::currentDate().addDays(1).dayOfWeek()));
    else calendar->setDateRange(QDate::currentDate(), QDate::currentDate().addDays(Qt::Saturday-QDate::currentDate().dayOfWeek()-1));
    calendar->setFirstDayOfWeek(Qt::Monday);
    qDebug() << "The amount of visible days: " << calendar->maximumDate().dayOfWeek() - calendar->minimumDate().dayOfWeek() + 1;

    //setting the style of the calendar
    {
        //setting the style of the calendar areas and unable to select days
        QTableView *view = calendar->findChild<QTableView*>("qt_calendar_calendarview");
        if (view)
        {
            QPalette pal = view->palette();
            pal.setColor(QPalette::Base, "#655b50");
            pal.setColor(QPalette::AlternateBase, "#ffba00");
            pal.setColor(QPalette::Text, Qt::gray);
            pal.setColor(QPalette::HighlightedText, Qt::green);
            pal.setColor(QPalette::Highlight, "#ffba00");
            view->setPalette(pal);
        }
        qDebug() << "Hello!";

        //making the names for columns and rows names black
        QTextCharFormat header_format = calendar->headerTextFormat();
        header_format.setForeground(QBrush(Qt::black, Qt::SolidPattern));
        calendar->setHeaderTextFormat(header_format);

        //setting the style of the possible for selection days
        QTextCharFormat format = calendar->weekdayTextFormat(Qt::Saturday);
        format.setForeground(QBrush(Qt::green, Qt::SolidPattern));
        QDate x = calendar->minimumDate();
        QDate y = calendar->maximumDate();
        while(x != y.addDays(1)){
            calendar->setNavigationBarVisible(true);
            calendar->setDateTextFormat(x, format);
            x = x.addDays(1);
        }
    }

    connect(calendar, SIGNAL(calendar->activated(QDate &)), this, SLOT(ScheduleRevision(QDate &)));

    QPushButton *submit = new QPushButton("Submit");
    connect(submit, SIGNAL(clicked()), this, SLOT(MakeDial()));

    QSpacerItem *space = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Expanding);
    page->addLayout(bank);
    page->addItem(space_before_calendar);
    page->addWidget(calendar);
    page->addWidget(submit);
    page->addItem(space);
    this->setLayout(page);
    this->setStyleSheet("background: #655b50;");
}

void DealHandler::SetBankAccountNumber(QString newBankAccountNumber)
{
    bancAccountNumber = newBankAccountNumber;
}

void DealHandler::ScheduleRevision(QDate selectedDate)
{
    if(selectedDate.dayOfWeek() == Qt::Sunday || selectedDate.dayOfWeek() == Qt::Saturday) {
        qDebug() << "WRONG)";
        return;
    }

    qDebug() << "Selected a date!";
}

void DealHandler::MakeDial()
{
    Bank *bank = new Bank("bankusers.json");

    emit AddToUser(item->GetProposalDetails("id").toString());
    this->close();
}
