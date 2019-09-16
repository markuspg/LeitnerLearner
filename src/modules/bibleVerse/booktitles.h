/*
 * Copyright 2019 Markus Prasser
 *
 * This file is part of LeitnerLearner.
 *
 *  LeitnerLearner is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  LeitnerLearner is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with LeitnerLearner.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BOOKTITLES_H
#define BOOKTITLES_H

#include "bookenum.h"

#include <QtGlobal>

#include <array>

struct BookTitleInfo {
    constexpr BookTitleInfo() = default;
    constexpr BookTitleInfo(EBibleBook argEnumVal,
                            const char * const argPrettyTitle,
                            const char * const argAbbreviation,
                            const char * const argTechnicalTitle) :
        enumVal(argEnumVal),
        prettyTitle(argPrettyTitle),
        abbreviation(argAbbreviation),
        technicalTitle(argTechnicalTitle)
    {
    }

    const EBibleBook enumVal
        = static_cast<EBibleBook>(
            std::numeric_limits<std::underlying_type<EBibleBook>::type>::max());
    const char * const prettyTitle = nullptr;
    const char * const abbreviation = nullptr;
    const char * const technicalTitle = nullptr;
};
Q_DECLARE_METATYPE(BookTitleInfo)

using BookTitleInfos = std::array<BookTitleInfo, 66>;
static constexpr BookTitleInfos bookTitles{
    BookTitleInfo{EBibleBook::Gen, QT_TR_NOOP("Genesis"),
                  QT_TR_NOOP("Gen."), nullptr},
    BookTitleInfo{EBibleBook::Ex, QT_TR_NOOP("Exodus"),
                  QT_TR_NOOP("Ex."), nullptr},
    BookTitleInfo{EBibleBook::Lev, QT_TR_NOOP("Leviticus"),
                  QT_TR_NOOP("Lev."), nullptr},
    BookTitleInfo{EBibleBook::Num, QT_TR_NOOP("Numbers"),
                  QT_TR_NOOP("Num."), nullptr},
    BookTitleInfo{EBibleBook::Deut, QT_TR_NOOP("Deuteronomy"),
                  QT_TR_NOOP("Deut."), nullptr},
    BookTitleInfo{EBibleBook::Josh, QT_TR_NOOP("Joshua"),
                  QT_TR_NOOP("Josh."), nullptr},
    BookTitleInfo{EBibleBook::Judg, QT_TR_NOOP("Judges"),
                  QT_TR_NOOP("Judg."), nullptr},
    BookTitleInfo{EBibleBook::Ruth, QT_TR_NOOP("Ruth"),
                  QT_TR_NOOP("Ruth"), nullptr},
    BookTitleInfo{EBibleBook::Frst_Sam, QT_TR_NOOP("1 Samuel"),
                  QT_TR_NOOP("1 Sam."), nullptr},
    BookTitleInfo{EBibleBook::Scnd_Sam, QT_TR_NOOP("2 Samuel"),
                  QT_TR_NOOP("2 Sam."), nullptr},
    BookTitleInfo{EBibleBook::Frst_Kings, QT_TR_NOOP("1 Kings"),
                  QT_TR_NOOP("1 Kings"), nullptr},
    BookTitleInfo{EBibleBook::Scnd_Kings, QT_TR_NOOP("2 Kings"),
                  QT_TR_NOOP("2 Kings"), nullptr},
    BookTitleInfo{EBibleBook::Frst_Chron, QT_TR_NOOP("1 Chronicles"),
                  QT_TR_NOOP("1 Chron."), nullptr},
    BookTitleInfo{EBibleBook::Scnd_Chron, QT_TR_NOOP("2 Chronicles"),
                  QT_TR_NOOP("2 Chron."), nullptr},
    BookTitleInfo{EBibleBook::Ezra, QT_TR_NOOP("Ezra"),
                  QT_TR_NOOP("Ezra"), nullptr},
    BookTitleInfo{EBibleBook::Neh, QT_TR_NOOP("Nehemiah"),
                  QT_TR_NOOP("Neh."), nullptr},
    BookTitleInfo{EBibleBook::Est, QT_TR_NOOP("Esther"),
                  QT_TR_NOOP("Est."), nullptr},
    BookTitleInfo{EBibleBook::Job, QT_TR_NOOP("Job"),
                  QT_TR_NOOP("Job"), nullptr},
    BookTitleInfo{EBibleBook::Ps, QT_TR_NOOP("Psalms"),
                  QT_TR_NOOP("Ps."), nullptr},
    BookTitleInfo{EBibleBook::Prov, QT_TR_NOOP("Proverbs"),
                  QT_TR_NOOP("Prov."), nullptr},
    BookTitleInfo{EBibleBook::Eccles, QT_TR_NOOP("Ecclesiastes"),
                  QT_TR_NOOP("Eccles."), nullptr},
    BookTitleInfo{EBibleBook::Song, QT_TR_NOOP("Song of Solomon"),
                  QT_TR_NOOP("Song"), nullptr},
    BookTitleInfo{EBibleBook::Isa, QT_TR_NOOP("Isaiah"),
                  QT_TR_NOOP("Isa."), nullptr},
    BookTitleInfo{EBibleBook::Jer, QT_TR_NOOP("Jeremiah"),
                  QT_TR_NOOP("Jer."), nullptr},
    BookTitleInfo{EBibleBook::Lam, QT_TR_NOOP("Lamentations"),
                  QT_TR_NOOP("Lam."), nullptr},
    BookTitleInfo{EBibleBook::Ezek, QT_TR_NOOP("Ezekiel"),
                  QT_TR_NOOP("Ezek."), nullptr},
    BookTitleInfo{EBibleBook::Dan, QT_TR_NOOP("Daniel"),
                  QT_TR_NOOP("Dan."), nullptr},
    BookTitleInfo{EBibleBook::Hos, QT_TR_NOOP("Hosea"),
                  QT_TR_NOOP("Hos."), nullptr},
    BookTitleInfo{EBibleBook::Joel, QT_TR_NOOP("Joel"),
                  QT_TR_NOOP("Joel"), nullptr},
    BookTitleInfo{EBibleBook::Amos, QT_TR_NOOP("Amos"),
                  QT_TR_NOOP("Amos"), nullptr},
    BookTitleInfo{EBibleBook::Obad, QT_TR_NOOP("Obadiah"),
                  QT_TR_NOOP("Obad."), nullptr},
    BookTitleInfo{EBibleBook::Jonah, QT_TR_NOOP("Jonah"),
                  QT_TR_NOOP("Jonah"), nullptr},
    BookTitleInfo{EBibleBook::Mic, QT_TR_NOOP("Micah"),
                  QT_TR_NOOP("Mic."), nullptr},
    BookTitleInfo{EBibleBook::Nah, QT_TR_NOOP("Nahum"),
                  QT_TR_NOOP("Nah."), nullptr},
    BookTitleInfo{EBibleBook::Hab, QT_TR_NOOP("Habakkuk"),
                  QT_TR_NOOP("Hab."), nullptr},
    BookTitleInfo{EBibleBook::Zeph, QT_TR_NOOP("Zephaniah"),
                  QT_TR_NOOP("Zeph."), nullptr},
    BookTitleInfo{EBibleBook::Hag, QT_TR_NOOP("Haggai"),
                  QT_TR_NOOP("Hag."), nullptr},
    BookTitleInfo{EBibleBook::Zech, QT_TR_NOOP("Zechariah"),
                  QT_TR_NOOP("Zech."), nullptr},
    BookTitleInfo{EBibleBook::Mal, QT_TR_NOOP("Malachi"),
                  QT_TR_NOOP("Mal."), nullptr},
    BookTitleInfo{EBibleBook::Matt, QT_TR_NOOP("Matthew"),
                  QT_TR_NOOP("Matt."), nullptr},
    BookTitleInfo{EBibleBook::Mark, QT_TR_NOOP("Mark"),
                  QT_TR_NOOP("Mark"), nullptr},
    BookTitleInfo{EBibleBook::Luke, QT_TR_NOOP("Luke"),
                  QT_TR_NOOP("Luke"), nullptr},
    BookTitleInfo{EBibleBook::John, QT_TR_NOOP("John"),
                  QT_TR_NOOP("John"), nullptr},
    BookTitleInfo{EBibleBook::Acts, QT_TR_NOOP("Acts"),
                  QT_TR_NOOP("Acts"), nullptr},
    BookTitleInfo{EBibleBook::Rom, QT_TR_NOOP("Romans"),
                  QT_TR_NOOP("Rom."), nullptr},
    BookTitleInfo{EBibleBook::Frst_Cor, QT_TR_NOOP("1 Corinthians"),
                  QT_TR_NOOP("1 Cor."), nullptr},
    BookTitleInfo{EBibleBook::Scnd_Cor, QT_TR_NOOP("2 Corinthians"),
                  QT_TR_NOOP("2 Cor."), nullptr},
    BookTitleInfo{EBibleBook::Gal, QT_TR_NOOP("Galatians"),
                  QT_TR_NOOP("Gal."), nullptr},
    BookTitleInfo{EBibleBook::Eph, QT_TR_NOOP("Ephesians"),
                  QT_TR_NOOP("Eph."), nullptr},
    BookTitleInfo{EBibleBook::Phil, QT_TR_NOOP("Philippians"),
                  QT_TR_NOOP("Phil."), nullptr},
    BookTitleInfo{EBibleBook::Col, QT_TR_NOOP("Colossians"),
                  QT_TR_NOOP("Col."), nullptr},
    BookTitleInfo{EBibleBook::Frst_Thess, QT_TR_NOOP("1 Thessalonians"),
                  QT_TR_NOOP("1 Thess."), nullptr},
    BookTitleInfo{EBibleBook::Scnd_Thess, QT_TR_NOOP("2 Thessalonians"),
                  QT_TR_NOOP("2 Thess."), nullptr},
    BookTitleInfo{EBibleBook::Frst_Tim, QT_TR_NOOP("1 Timothy"),
                  QT_TR_NOOP("1 Tim."), nullptr},
    BookTitleInfo{EBibleBook::Scnd_Tim, QT_TR_NOOP("2 Timothy"),
                  QT_TR_NOOP("2 Tim."), nullptr},
    BookTitleInfo{EBibleBook::Titus, QT_TR_NOOP("Titus"),
                  QT_TR_NOOP("Titus"), nullptr},
    BookTitleInfo{EBibleBook::Philem, QT_TR_NOOP("Philemon"),
                  QT_TR_NOOP("Philem."), nullptr},
    BookTitleInfo{EBibleBook::Heb, QT_TR_NOOP("Hebrews"),
                  QT_TR_NOOP("Heb."), nullptr},
    BookTitleInfo{EBibleBook::James, QT_TR_NOOP("James"),
                  QT_TR_NOOP("James"), nullptr},
    BookTitleInfo{EBibleBook::Frst_Pet, QT_TR_NOOP("1 Peter"),
                  QT_TR_NOOP("1 Pet."), nullptr},
    BookTitleInfo{EBibleBook::Scnd_Pet, QT_TR_NOOP("2 Peter"),
                  QT_TR_NOOP("2 Pet."), nullptr},
    BookTitleInfo{EBibleBook::Frst_John, QT_TR_NOOP("1 John"),
                  QT_TR_NOOP("1 John"), nullptr},
    BookTitleInfo{EBibleBook::Scnd_John, QT_TR_NOOP("2 John"),
                  QT_TR_NOOP("2 John"), nullptr},
    BookTitleInfo{EBibleBook::Thrd_John, QT_TR_NOOP("3 John"),
                  QT_TR_NOOP("3 John"), nullptr},
    BookTitleInfo{EBibleBook::Jude, QT_TR_NOOP("Jude"),
                  QT_TR_NOOP("Jude"), nullptr},
    BookTitleInfo{EBibleBook::Rev, QT_TR_NOOP("Revelation"),
                  QT_TR_NOOP("Rev."), nullptr}};
using BookTitleInfoPtr = const BookTitleInfos::value_type*;
Q_DECLARE_METATYPE(BookTitleInfoPtr)

#endif // BOOKTITLES_H
