#ifndef VERSEENTRY_H
#define VERSEENTRY_H

#include "../../abstractdataentry.h"

class VerseEntry : public AbstractDataEntry
{
    Q_OBJECT

public:
    explicit VerseEntry(QWidget *const argParent = nullptr);
};

#endif // VERSEENTRY_H
