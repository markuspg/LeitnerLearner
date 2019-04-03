#ifndef VERSE_H
#define VERSE_H

#include "booktitles.h"

#include <limits>

#include <QString>

class Verse
{
public:
    Verse() = default;
    Verse(const BookInfoPairPtr argBook, const unsigned short argChapterNo,
          const unsigned short argVerseNo, const QString &argText,
          const unsigned short argCurrCat);

    BookInfoPairPtr GetBookInfoPairPtr() const noexcept { return book; }
    unsigned short GetChapterNo() const noexcept { return chapterNo; }
    unsigned short GetVerseNo() const noexcept { return verseNo; }
    const QString& GetText() const noexcept { return text; }

private:
    const BookInfoPairPtr book = nullptr;
    const unsigned short chapterNo = std::numeric_limits<unsigned short>::max();
    const unsigned short currCat = std::numeric_limits<unsigned short>::max();
    const unsigned short verseNo = std::numeric_limits<unsigned short>::max();
    const QString text;

};
Q_DECLARE_METATYPE(Verse)

#endif // VERSE_H
