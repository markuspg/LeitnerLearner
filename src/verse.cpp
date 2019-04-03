#include "verse.h"

Verse::Verse(const BookInfoPairPtr argBook, const unsigned short argChapterNo,
             const unsigned short argVerseNo, const QString &argText,
             const unsigned short argCurrCat) :
    book{argBook},
    chapterNo{argChapterNo},
    currCat{argCurrCat},
    verseNo{argVerseNo},
    text{argText}
{
}
