#ifndef VERSEENTRYWDGT_H
#define VERSEENTRYWDGT_H

#include "../../abstractentrywdgt.h"
#include "verse.h"

namespace Ui {
class VerseEntryWdgt;
} // namespace Ui

class VerseEntryWdgt : public AbstractEntryWdgt
{
    Q_OBJECT

public:
    explicit VerseEntryWdgt(QWidget *const argParent = nullptr);
    ~VerseEntryWdgt() override;

    void ClearAndPrepare() override;
    AbstractDataTypeSharedPtr GetDataPr() override;

private:
    Ui::VerseEntryWdgt *const ui = nullptr;

private slots:
    void OnDataChanged();
};

#endif // VERSEENTRYWDGT_H
