#include "verseentrywdgt.h"
#include "ui_verseentrywdgt.h"

VerseEntryWdgt::VerseEntryWdgt(QWidget *const argParent) :
    AbstractEntryWdgt{argParent},
    ui{new Ui::VerseEntryWdgt}
{
    ui->setupUi(this);

    for (const auto &bookData : bookTitles) {
        QVariant tmpData;
        tmpData.setValue(&bookData);
        ui->CBBibleBook->addItem(tr(bookData.second), tmpData);
    }

    connect(ui->PTEVerseText, &QPlainTextEdit::textChanged,
            this, &VerseEntryWdgt::OnDataChanged);
}

VerseEntryWdgt::~VerseEntryWdgt()
{
    delete ui;
}

AbstractDataTypeSharedPtr VerseEntryWdgt::GetDataPr()
{
    return AbstractDataTypeSharedPtr{
        new Verse{ui->CBBibleBook->currentData().value<BookInfoPairPtr>(),
                  static_cast<unsigned short>(ui->SBChapterNo->value()),
                  static_cast<unsigned short>(ui->SBVerseNo->value()),
                  ui->PTEVerseText->toPlainText(), 0}};
}

void VerseEntryWdgt::OnDataChanged()
{
    if (ui->PTEVerseText->toPlainText().size() != 0) {
        emit DataComplete();
    }
}
