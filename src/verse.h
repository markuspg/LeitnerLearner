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
          const unsigned short argVerseNo, const QString &argText);

private:
    const BookInfoPairPtr book = nullptr;
    unsigned short chapterNo = std::numeric_limits<unsigned short>::max();
    unsigned short verseNo = std::numeric_limits<unsigned short>::max();
    const QString text;

};
Q_DECLARE_METATYPE(Verse)

#endif // VERSE_H
