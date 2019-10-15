#include "meneger.h"

Meneger::Meneger()
{
    listDeals = new QListWidget;
    listDeals->setStyleSheet("QListWidget {"
                                 "background: #ffe7d0;"
                                 "border-radius: 4px; }"
                                 "QListWidget::item:hover { background: #b88c53; }"
                                 "QListWidget::item:selected { background: #f095ee; }");
    QFile dates("dates");
    dates.open(QIODevice::ReadOnly | QIODevice::Text);
    while (!dates.atEnd())
    {
        QString date = dates.readLine();
        listDeals->addItem(date);
    }

    QPushButton *done = new QPushButton("Done");
    done->setStyleSheet("QPushButton {"
                            "background: #ffe7d0;"
                            "color: #ffba00;"
                            "border-radius: 0px;"
                            "padding: 10px; }"
                            "QPushButton::hover {"
                            "background: #b88c53; }");
    connect(done, SIGNAL(clicked()), this, SLOT(Done()));

    QSpacerItem *space = new QSpacerItem(40, 60, QSizePolicy::Preferred, QSizePolicy::Expanding);
    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(listDeals);
    page->addWidget(done);
    page->addItem(space);

    this->setLayout(page);
}

void Meneger::Done()
{
    listDeals->takeItem(listDeals->currentRow());
}
