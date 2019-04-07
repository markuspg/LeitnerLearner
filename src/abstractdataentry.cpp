#include "abstractdataentry.h"
#include "ui_abstractdataentry.h"

AbstractDataEntry::AbstractDataEntry(QWidget *const argParent) :
    QWidget{argParent},
    ui{new Ui::AbstractDataEntry}
{
}

AbstractDataEntry::~AbstractDataEntry()
{
    delete ui;
}
