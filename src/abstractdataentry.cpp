#include "abstractdataentry.h"
#include "abstractentrywdgt.h"
#include "ui_abstractdataentry.h"

AbstractDataEntry::AbstractDataEntry(AbstractEntryWdgt *const argEntryWdgt,
                                     QWidget *const argParent) :
    QWidget{argParent},
    entryWdgt{argEntryWdgt},
    ui{new Ui::AbstractDataEntry}
{
    ui->setupUi(this);
    connect(ui->PBAdd, &QPushButton::clicked,
            this, &AbstractDataEntry::OnAddButtonClicked);

    entryWdgt->setParent(this);
    connect(entryWdgt, &AbstractEntryWdgt::DataComplete,
            this, &AbstractDataEntry::OnDataComplete);
}

AbstractDataEntry::~AbstractDataEntry()
{
    delete ui;
}

void AbstractDataEntry::OnAddButtonClicked()
{
    // disable the widget to prevent further save requests to be sent
    setEnabled(false);

    emit Req_DataSaving(entryWdgt->GetDataPr());
}

void AbstractDataEntry::OnDataComplete()
{
    ui->PBAdd->setEnabled(true);
}

void AbstractDataEntry::OnDataSavingFailed()
{
    // set the "Add" push button to false to signal failure to the user
    ui->PBAdd->setStyleSheet("background: red");

    // enable the button again to make another try to save possible
    setEnabled(true);
}

void AbstractDataEntry::OnDataSavingSucceeded()
{
    // reset the stylesheet to clear any previously signalled error conditions
    ui->PBAdd->setStyleSheet("");

    // clear the data entry widget and prepare entry of next data
    entryWdgt->ClearAndPrepare();

    // allow the user to send next request to save a verse
    setEnabled(true);

    // the "Add" push button shall be disabled until next data is available
    ui->PBAdd->setEnabled(false);
}
