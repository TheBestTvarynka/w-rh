#include "dealhandler.h"

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

    QCalendarWidget *calendar = new QCalendarWidget();
    calendar->setSelectionMode(QCalendarWidget::SingleSelection);
    //You can select the dates only for a week from today
    calendar->setDateRange(QDate::currentDate(), QDate::currentDate().addDays(7));
    calendar->setFirstDayOfWeek(Qt::Monday);

    //setting the style of the calendar
    {
        //setting the style of the calendar areas
        QTableView *view = calendar->findChild<QTableView*>("qt_calendar_calendarview");
        if (view)
        {
            QPalette pal = view->palette();
            pal.setColor(QPalette::Base, "#655b50");
            pal.setColor(QPalette::AlternateBase, "#ffba00");
            pal.setColor(QPalette::HighlightedText, Qt::white);
            pal.setColor(QPalette::Highlight, "#ffba00");
            view->setPalette(pal);
        }

        QTextCharFormat format = calendar->weekdayTextFormat(Qt::Saturday);

        //setting the style of the days to the 'inactive' color
//        format.setForeground(QBrush(Qt::lightGray, Qt::SolidPattern));
//        calendar->setWeekdayTextFormat(Qt::Saturday, format);
//        calendar->setWeekdayTextFormat(Qt::Sunday, format);
//        calendar->setWeekdayTextFormat(Qt::Monday, format);
//        calendar->setWeekdayTextFormat(Qt::Tuesday, format);
//        calendar->setWeekdayTextFormat(Qt::Wednesday, format);
//        calendar->setWeekdayTextFormat(Qt::Thursday, format);
//        calendar->setWeekdayTextFormat(Qt::Friday, format);

        //setting the style of the possible for selection days
        QDate x = QDate::currentDate();
        QDate y = QDate::currentDate().addDays(7);
        format.setForeground(QBrush(Qt::green, Qt::SolidPattern));
        while(x != y){
            if(x.dayOfWeek() != Qt::Saturday && x.dayOfWeek() != Qt::Sunday) calendar->setDateTextFormat(x, format);
            x = x.addDays(1);
        }
    }





    QPushButton *submit = new QPushButton("Submit");
    connect(submit, SIGNAL(clicked()), this, SLOT(MakeDial()));

    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);
    page->addLayout(bank);
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

void DealHandler::MakeDial()
{
    Bank *bank = new Bank("bankusers.json");

    emit AddToUser(item->GetProposalDetails("id").toString());
    this->close();
}
