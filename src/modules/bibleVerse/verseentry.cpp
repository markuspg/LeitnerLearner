#include "verseentry.h"
#include "verseentrywdgt.h"

VerseEntry::VerseEntry(QWidget *const argParent) :
    AbstractDataEntry{new VerseEntryWdgt, argParent}
{
}
