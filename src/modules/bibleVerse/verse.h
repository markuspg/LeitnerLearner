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

#ifndef VERSE_H
#define VERSE_H

#include "booktitles.h"
#include "../../abstractdatatype.h"
#include "../../global_definitions.h"

#include <limits>

#include <QString>

class Verse : public AbstractDataType
{
public:
    Verse() = default;
    Verse(const BookInfoPairPtr argBook, const unsigned short argChapterNo,
          const unsigned short argVerseNo, const QString &argText,
          const ll::Level argCurrLvl);

    QByteArray GetData() const override;
    QString GetIdentifier() const override;

private:
    const BookInfoPairPtr book = nullptr;
    const unsigned short chapterNo = std::numeric_limits<unsigned short>::max();
    const ll::Level currLvl = std::numeric_limits<ll::Level>::max();
    const unsigned short verseNo = std::numeric_limits<unsigned short>::max();
    const QString text;

};

#endif // VERSE_H
