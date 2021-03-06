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
            qDebug() << photos.size();
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

    QLabel *datetime = new QLabel("Choose a date and time:");
    datetimeEdit = new QDateTimeEdit;
    QVBoxLayout *datetimeL = new QVBoxLayout;
    datetimeL->addWidget(datetime);
    datetimeL->addWidget(datetimeEdit);

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

    //parsing the managers.json to create the list of managers
    QLabel *info_manager = new QLabel("Choose the manager:");
    managerSelect = new QComboBox();
    managersGraphic = ParseManagersGraphic("managers.json");
    for(QVariantMap::iterator i = managersGraphic.begin(); i != managersGraphic.end(); i++)
      managerSelect->addItem(i.key());
    managerSelect->setStyleSheet("QComboBox {"
                                 "background: #ffba00;"
                                 "}");


    QLabel *info_calendar = new QLabel("Choose the date:");

    //initialized the calendar
    calendar = new QCalendarWidget();
    calendar->setSelectionMode(QCalendarWidget::SingleSelection);
    //You can select the dates only for a week from today
    calendar->setNavigationBarVisible(false);
    if(QDate::currentDate().dayOfWeek() == Qt::Saturday) calendar->setDateRange(QDate::currentDate().addDays(2), QDate::currentDate().addDays(Qt::Saturday-QDate::currentDate().addDays(2).dayOfWeek()));
    else if(QDate::currentDate().dayOfWeek() == Qt::Sunday) calendar->setDateRange(QDate::currentDate().addDays(1), QDate::currentDate().addDays(Qt::Saturday-QDate::currentDate().addDays(1).dayOfWeek()));
    else calendar->setDateRange(QDate::currentDate(), QDate::currentDate().addDays(Qt::Saturday-QDate::currentDate().dayOfWeek()-1));
    calendar->setFirstDayOfWeek(Qt::Monday);

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
            pal.setColor(QPalette::HighlightedText, Qt::white);
            pal.setColor(QPalette::Highlight, "#ffba00");
            view->setPalette(pal);
        }

        //making the names for columns and rows names black
        QTextCharFormat header_format = calendar->headerTextFormat();
        header_format.setForeground(QBrush(Qt::black, Qt::SolidPattern));
        calendar->setHeaderTextFormat(header_format);

        //setting the style of the possible for selection days
        RefreshVisibleDays();
    }
    calendar->releaseMouse();

    connect(calendar, SIGNAL(selectionChanged()), this, SLOT(ScheduleRevisionDate()));
    connect(calendar, SIGNAL(selectionChanged()), this, SLOT(ScheduleRevisionTime()));
    connect(managerSelect, SIGNAL(currentIndexChanged(int)), this, SLOT(RefreshVisibleDays()));

    date = new QLabel("You haven't selected the date yet!");

    timeEdit = new QComboBox();

    ScheduleRevisionTime();
    timeEdit->hide();
    connect(timeEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(RefreshTime()));

    time = new QLabel("You haven't selected the time yet!");

    QPushButton *submit = new QPushButton("Submit");
    connect(submit, SIGNAL(clicked()), this, SLOT(MakeDial()));

    QSpacerItem *space = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Expanding);
    page->addLayout(bank);
    page->addItem(space_before_calendar);
    page->addWidget(info_manager);
    page->addWidget(managerSelect);
    page->addWidget(info_calendar);
    page->addWidget(calendar);
    page->addWidget(date);
    page->addWidget(timeEdit);
    page->addWidget(time);
    page->addWidget(submit);
    page->addItem(space);
    this->setLayout(page);
    this->setStyleSheet("background: #655b50;");
}

void DealHandler::SetBankAccountNumber(QString newBankAccountNumber)
{
    bancAccountNumber = newBankAccountNumber;
}

void DealHandler::ScheduleRevisionDate()
{
    QList<int> *days = new QList<int>();
    QVariant temp = managersGraphic[managerSelect->currentText()];
    if (temp.canConvert<QVariantList>()) {
        QSequentialIterable iterable = temp.value<QSequentialIterable>();
        for (const QVariant& x : iterable){
          days->push_back(x.toInt());
        }
    }
    if(days->contains(calendar->selectedDate().dayOfWeek())){
        date->setText(calendar->selectedDate().toString());
        timeEdit->show();
    }
    else {
        date->setText("Selected manager does not work in this day!");
        timeEdit->hide();
    }
}

void DealHandler::ScheduleRevisionTime()
{
    qDebug() << "Selected a time!";
    //parsing the meetings.json to create the list of managers
    managersMeetings = ParseManagersMeetings("meetings.json");
    QList<int> *hours = new QList<int>();
    QVariant temp2 = managersMeetings[managerSelect->currentText()];
    timeEdit->clear();
    if (temp2.canConvert<QVariantList>()) {
        QSequentialIterable iterable = temp2.value<QSequentialIterable>();
        QDate temp3;
        for (const QVariant& x : iterable){
            qDebug() << "ITEM: " << x;
            temp3 = QDate::fromString(ParseMeeting(x)[1], "ddd MMM dd yyyy");
            if(temp3 == calendar->selectedDate()) {
                qDebug() << "hour: " << ParseMeeting(x)[2].split(':')[0].toInt();
                hours->push_back(ParseMeeting(x)[2].split(':')[0].toInt());
            }
        }
    }

    //filling the timeEdit with possible for choosing variants
    QTime time_iter = QTime(8, 0, 0);
    while(time_iter.hour() < QTime(18, 0, 0).hour()){
        if(hours->contains(time_iter.hour())) {
            time_iter = time_iter.addSecs(60 * 60);
            continue;
        }
        timeEdit->addItem(time_iter.toString());
        time_iter = time_iter.addSecs(60 * 60);
    }
    timeEdit->setStyleSheet("QComboBox {"
                                 "background: #ffba00;"
                                 "}");
}

QVariantMap DealHandler::ParseManagersGraphic(QString address){
    QFile temp(address);
    temp.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!temp.isOpen())
        {
            qDebug() << "file not found";
            return {};
        }
    QString data = temp.readAll();
    temp.close();
    QJsonObject file = QJsonDocument::fromJson(data.toUtf8()).object();
    return file.toVariantMap();
}

QVariantMap DealHandler::ParseManagersMeetings(QString address){
  QFile temp(address);
  temp.open(QIODevice::ReadOnly | QIODevice::Text);
  if (!temp.isOpen())
      {
          qDebug() << "file not found";
          return {};
      }
  QString data = temp.readAll();
  temp.close();
  QJsonObject file = QJsonDocument::fromJson(data.toUtf8()).object();
  return file.toVariantMap();
}

QStringList DealHandler::ParseMeeting(QVariant meeting){
    return meeting.toString().split('/');
}

void DealHandler::RefreshVisibleDays(){


  QTextCharFormat format = calendar->weekdayTextFormat(Qt::Saturday);
  format.setForeground(QBrush(Qt::green, Qt::SolidPattern));
  QTextCharFormat format_invisible = format;
  format_invisible.setForeground(QBrush(Qt::black, Qt::SolidPattern));
  QDate x = calendar->minimumDate();
  QDate y = calendar->maximumDate();

  QList<int> *days = new QList<int>();
  QVariant temp = managersGraphic[managerSelect->currentText()];
  if (temp.canConvert<QVariantList>()) {
      QSequentialIterable iterable = temp.value<QSequentialIterable>();
      for (const QVariant& x : iterable){
        days->push_back(x.toInt());
      }
  }

  while(x != y.addDays(1)){
      if(days->contains(x.dayOfWeek()))
        calendar->setDateTextFormat(x, format);
      else
        calendar->setDateTextFormat(x, format_invisible);
      x = x.addDays(1);
  }
}

void DealHandler::RefreshTime(){
  time->setText(timeEdit->currentText());
}

void DealHandler::WriteMeetings(QString address, QString meeting){
  QFile temp(address);
  temp.open(QIODevice::ReadOnly | QIODevice::Text);
  if (!temp.isOpen())
      {
          qDebug() << "file not found";
          return;
      }
  QString data = temp.readAll();
  temp.close();
  QJsonObject file = QJsonDocument::fromJson(data.toUtf8()).object();
  QJsonArray arr = file[managerSelect->currentText()].toArray();
  arr.push_back(meeting);
  file[managerSelect->currentText()] = arr;

  temp.open(QIODevice::WriteOnly | QIODevice::Text);
  if (!temp.isOpen())
      {
          qDebug() << "file not found";
          return;
      }
  temp.write(QJsonDocument(file).toJson());
  temp.close();
}

void DealHandler::MakeDial()
{
    if(timeEdit->isHidden() || time->text() == "You haven't selected the time yet!"){
        QMessageBox msgBox;
        msgBox.setText("You have to choose appropriate date and time to continue!");
        msgBox.exec();
      }
    else{
      Bank *bank = new Bank("bankusers.json");
      QString meeting("id: " + item->GetProposalDetails("id").toString() + "/" + date->text() + "/" + time->text());
      WriteMeetings("meetings.json", meeting);
      emit AddToUser(item->GetProposalDetails("id").toString());
      this->close();
    }
}
