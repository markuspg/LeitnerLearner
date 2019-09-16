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
    BookTitleInfo{EBibleBook::Gen, QT_TR_NOOP("Genesis"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Ex, QT_TR_NOOP("Exodus"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Lev, QT_TR_NOOP("Leviticus"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Num, QT_TR_NOOP("Numbers"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Deut, QT_TR_NOOP("Deuteronomy"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Josh, QT_TR_NOOP("Joshua"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Judg, QT_TR_NOOP("Judges"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Ruth, QT_TR_NOOP("Ruth"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Frst_Sam, QT_TR_NOOP("1 Samuel"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Scnd_Sam, QT_TR_NOOP("2 Samuel"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Frst_Kings, QT_TR_NOOP("1 Kings"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Scnd_Kings, QT_TR_NOOP("2 Kings"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Frst_Chron, QT_TR_NOOP("1 Chronicles"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Scnd_Chron, QT_TR_NOOP("2 Chronicles"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Ezra, QT_TR_NOOP("Ezra"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Neh, QT_TR_NOOP("Nehemiah"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Est, QT_TR_NOOP("Esther"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Job, QT_TR_NOOP("Job"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Ps, QT_TR_NOOP("Psalms"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Prov, QT_TR_NOOP("Proverbs"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Eccles, QT_TR_NOOP("Ecclesiastes"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Song, QT_TR_NOOP("Song of Solomon"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Isa, QT_TR_NOOP("Isaiah"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Jer, QT_TR_NOOP("Jeremiah"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Lam, QT_TR_NOOP("Lamentations"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Ezek, QT_TR_NOOP("Ezekiel"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Dan, QT_TR_NOOP("Daniel"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Hos, QT_TR_NOOP("Hosea"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Joel, QT_TR_NOOP("Joel"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Amos, QT_TR_NOOP("Amos"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Obad, QT_TR_NOOP("Obadiah"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Jonah, QT_TR_NOOP("Jonah"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Mic, QT_TR_NOOP("Micah"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Nah, QT_TR_NOOP("Nahum"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Hab, QT_TR_NOOP("Habakkuk"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Zeph, QT_TR_NOOP("Zephaniah"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Hag, QT_TR_NOOP("Haggai"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Zech, QT_TR_NOOP("Zechariah"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Mal, QT_TR_NOOP("Malachi"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Matt, QT_TR_NOOP("Matthew"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Mark, QT_TR_NOOP("Mark"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Luke, QT_TR_NOOP("Luke"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::John, QT_TR_NOOP("John"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Acts, QT_TR_NOOP("Acts"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Rom, QT_TR_NOOP("Romans"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Frst_Cor, QT_TR_NOOP("1 Corinthians"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Scnd_Cor, QT_TR_NOOP("2 Corithians"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Gal, QT_TR_NOOP("Galatians"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Eph, QT_TR_NOOP("Ephesians"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Phil, QT_TR_NOOP("Philippians"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Col, QT_TR_NOOP("Colossians"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Frst_Thess, QT_TR_NOOP("1 Thessalonians"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Scnd_Thess, QT_TR_NOOP("2 Thessalonians"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Frst_Tim, QT_TR_NOOP("1 Timothy"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Scnd_Tim, QT_TR_NOOP("2 Timothy"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Titus, QT_TR_NOOP("Titus"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Philem, QT_TR_NOOP("Philemon"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Heb, QT_TR_NOOP("Hebrews"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::James, QT_TR_NOOP("James"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Frst_Pet, QT_TR_NOOP("1 Peter"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Scnd_Pet, QT_TR_NOOP("2 Peter"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Frst_John, QT_TR_NOOP("1 John"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Scnd_John, QT_TR_NOOP("2 John"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Thrd_John, QT_TR_NOOP("3 John"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Jude, QT_TR_NOOP("Jude"), nullptr, nullptr},
    BookTitleInfo{EBibleBook::Rev, QT_TR_NOOP("Revelation"), nullptr, nullptr}};
using BookTitleInfoPtr = const BookTitleInfos::value_type*;
Q_DECLARE_METATYPE(BookTitleInfoPtr)

#endif // BOOKTITLES_H
