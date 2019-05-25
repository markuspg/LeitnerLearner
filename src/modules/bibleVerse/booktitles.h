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

constexpr std::array<std::pair<EBibleBook, const char * const>, 66> bookTitles{
    std::make_pair(EBibleBook::Gen, QT_TR_NOOP("Genesis")),
    std::make_pair(EBibleBook::Ex, QT_TR_NOOP("Exodus")),
    std::make_pair(EBibleBook::Lev, QT_TR_NOOP("Leviticus")),
    std::make_pair(EBibleBook::Num, QT_TR_NOOP("Numbers")),
    std::make_pair(EBibleBook::Deut, QT_TR_NOOP("Deuteronomy")),
    std::make_pair(EBibleBook::Josh, QT_TR_NOOP("Joshua")),
    std::make_pair(EBibleBook::Judg, QT_TR_NOOP("Judges")),
    std::make_pair(EBibleBook::Ruth, QT_TR_NOOP("Ruth")),
    std::make_pair(EBibleBook::Frst_Sam, QT_TR_NOOP("1 Samuel")),
    std::make_pair(EBibleBook::Scnd_Sam, QT_TR_NOOP("2 Samuel")),
    std::make_pair(EBibleBook::Frst_Kings, QT_TR_NOOP("1 Kings")),
    std::make_pair(EBibleBook::Scnd_Kings, QT_TR_NOOP("2 Kings")),
    std::make_pair(EBibleBook::Frst_Chron, QT_TR_NOOP("1 Chronicles")),
    std::make_pair(EBibleBook::Scnd_Chron, QT_TR_NOOP("2 Chronicles")),
    std::make_pair(EBibleBook::Ezra, QT_TR_NOOP("Ezra")),
    std::make_pair(EBibleBook::Neh, QT_TR_NOOP("Nehemiah")),
    std::make_pair(EBibleBook::Est, QT_TR_NOOP("Esther")),
    std::make_pair(EBibleBook::Job, QT_TR_NOOP("Job")),
    std::make_pair(EBibleBook::Ps, QT_TR_NOOP("Psalms")),
    std::make_pair(EBibleBook::Prov, QT_TR_NOOP("Proverbs")),
    std::make_pair(EBibleBook::Eccles, QT_TR_NOOP("Ecclesiastes")),
    std::make_pair(EBibleBook::Song, QT_TR_NOOP("Song of Solomon")),
    std::make_pair(EBibleBook::Isa, QT_TR_NOOP("Isaiah")),
    std::make_pair(EBibleBook::Jer, QT_TR_NOOP("Jeremiah")),
    std::make_pair(EBibleBook::Lam, QT_TR_NOOP("Lamentations")),
    std::make_pair(EBibleBook::Ezek, QT_TR_NOOP("Ezekiel")),
    std::make_pair(EBibleBook::Dan, QT_TR_NOOP("Daniel")),
    std::make_pair(EBibleBook::Hos, QT_TR_NOOP("Hosea")),
    std::make_pair(EBibleBook::Joel, QT_TR_NOOP("Joel")),
    std::make_pair(EBibleBook::Amos, QT_TR_NOOP("Amos")),
    std::make_pair(EBibleBook::Obad, QT_TR_NOOP("Obadiah")),
    std::make_pair(EBibleBook::Jonah, QT_TR_NOOP("Jonah")),
    std::make_pair(EBibleBook::Mic, QT_TR_NOOP("Micah")),
    std::make_pair(EBibleBook::Nah, QT_TR_NOOP("Nahum")),
    std::make_pair(EBibleBook::Hab, QT_TR_NOOP("Habakkuk")),
    std::make_pair(EBibleBook::Zeph, QT_TR_NOOP("Zephaniah")),
    std::make_pair(EBibleBook::Hag, QT_TR_NOOP("Haggai")),
    std::make_pair(EBibleBook::Zech, QT_TR_NOOP("Zechariah")),
    std::make_pair(EBibleBook::Mal, QT_TR_NOOP("Malachi")),
    std::make_pair(EBibleBook::Matt, QT_TR_NOOP("Matthew")),
    std::make_pair(EBibleBook::Mark, QT_TR_NOOP("Mark")),
    std::make_pair(EBibleBook::Luke, QT_TR_NOOP("Luke")),
    std::make_pair(EBibleBook::John, QT_TR_NOOP("John")),
    std::make_pair(EBibleBook::Acts, QT_TR_NOOP("Acts")),
    std::make_pair(EBibleBook::Rom, QT_TR_NOOP("Romans")),
    std::make_pair(EBibleBook::Frst_Cor, QT_TR_NOOP("1 Corinthians")),
    std::make_pair(EBibleBook::Scnd_Cor, QT_TR_NOOP("2 Corithians")),
    std::make_pair(EBibleBook::Gal, QT_TR_NOOP("Galatians")),
    std::make_pair(EBibleBook::Eph, QT_TR_NOOP("Ephesians")),
    std::make_pair(EBibleBook::Phil, QT_TR_NOOP("Philippians")),
    std::make_pair(EBibleBook::Col, QT_TR_NOOP("Colossians")),
    std::make_pair(EBibleBook::Frst_Thess, QT_TR_NOOP("1 Thessalonians")),
    std::make_pair(EBibleBook::Scnd_Thess, QT_TR_NOOP("2 Thessalonians")),
    std::make_pair(EBibleBook::Frst_Tim, QT_TR_NOOP("1 Timothy")),
    std::make_pair(EBibleBook::Scnd_Tim, QT_TR_NOOP("2 Timothy")),
    std::make_pair(EBibleBook::Titus, QT_TR_NOOP("Titus")),
    std::make_pair(EBibleBook::Philem, QT_TR_NOOP("Philemon")),
    std::make_pair(EBibleBook::Heb, QT_TR_NOOP("Hebrews")),
    std::make_pair(EBibleBook::James, QT_TR_NOOP("James")),
    std::make_pair(EBibleBook::Frst_Pet, QT_TR_NOOP("1 Peter")),
    std::make_pair(EBibleBook::Scnd_Pet, QT_TR_NOOP("2 Peter")),
    std::make_pair(EBibleBook::Frst_John, QT_TR_NOOP("1 John")),
    std::make_pair(EBibleBook::Scnd_John, QT_TR_NOOP("2 John")),
    std::make_pair(EBibleBook::Thrd_John, QT_TR_NOOP("3 John")),
    std::make_pair(EBibleBook::Jude, QT_TR_NOOP("Jude")),
    std::make_pair(EBibleBook::Rev, QT_TR_NOOP("Revelation"))};
using BookInfoPairPtr = const decltype(bookTitles)::value_type*;
Q_DECLARE_METATYPE(BookInfoPairPtr)

#endif // BOOKTITLES_H
