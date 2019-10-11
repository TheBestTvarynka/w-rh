#include "dealhandler.h"

void DealHandler::CreateTitles()
{
    titles.push_back("Name");
    titles.push_back("Address");
    titles.push_back("Number of rooms");
    titles.push_back("Price");
    titles.push_back("Photos");
}

DealHandler::DealHandler(QWidget *parent, ProposalItem *i) : QDialog(parent)
{
    item = i;
    this->setStyleSheet("QWidget {"
                        "background: green; }");

    QVBoxLayout *page = new QVBoxLayout;


}
