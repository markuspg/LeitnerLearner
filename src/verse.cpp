#include "verse.h"

Verse::Verse(const BookInfoPairPtr argBook, const unsigned short argChapterNo,
             const unsigned short argVerseNo, const QString &argText) :
    book{argBook},
    chapterNo{argChapterNo},
    verseNo{argVerseNo},
    text{argText}
{
}
