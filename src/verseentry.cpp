#include "ui_verseentry.h"
#include "verse.h"
#include "verseentry.h"

VerseEntry::VerseEntry(QWidget *const argParent) :
    QWidget{argParent},
    ui{new Ui::VerseEntry}
{
    ui->setupUi(this);
    connect(ui->PBAdd, &QPushButton::clicked,
            this, &VerseEntry::OnAddButtonClicked);
}

VerseEntry::~VerseEntry()
{
    delete ui;
}

void VerseEntry::OnAddButtonClicked()
{
    // disable the widgets to prevent further save requests to be sent
    setEnabled(false);

    // emit the signal to save the verse
    emit Req_VerseSaving(Verse{});
}

void VerseEntry::OnVerseSavingFailed()
{
    // set the "Add" push button to false to signal failure to the user
    ui->PBAdd->setStyleSheet("background: red");

    // enable the button again to make another try to save possible
    setEnabled(true);
}

void VerseEntry::OnVerseSavingSucceeded()
{
    // reset the stylesheet to clear any previously signalled error conditions
    ui->PBAdd->setStyleSheet("");

    // clear the verse text entry field to make room for the next verse
    ui->PTEVerseText->clear();

    // automatically jump to the next verse to ease entry of succeeding verses
    ui->SBVerseNo->setValue(ui->SBVerseNo->value() + 1);

    // allow the user to send next request to save a verse
    setEnabled(true);
}
