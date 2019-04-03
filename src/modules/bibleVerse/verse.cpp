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

QByteArray Verse::GetData() const
{
    return text.toUtf8();
}

QString Verse::GetIdentifier() const
{
    return QString{book->second}
            + "_" + QString::number(chapterNo)
            + "-" + QString::number(verseNo);
}
