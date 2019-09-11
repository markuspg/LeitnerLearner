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

#include "abstractdatatype.h"
#include "modules/bibleVerse/verse.h"

#include <QDebug>
#include <QRegularExpression>

AbstractDataType::AbstractDataType(const EModIds argType) noexcept :
    type{argType}
{
}

AbstractDataTypeSharedPtr AbstractDataType::ParseFromData(
        const EModIds argMod, const ll::Level argLevel,
        const QString &argIdentifier, const QByteArray &argData)
{
    if (argMod == EModIds::BibleVerse) {
        const QStringList splitRes{argIdentifier.split(QRegularExpression{"[-_]"})};
        if (splitRes.size() != 3) {
            qWarning() << "Invalid identifier passed into Verse parser";
            return AbstractDataTypeSharedPtr{};
        }
        const QString bookTitle{splitRes.at(0)};
        if (bookTitle.isEmpty() == true) {
            qWarning() << "Invalid book title encountered in Verse parsing";
            return AbstractDataTypeSharedPtr{};
        }
        BookInfoPairPtr bookInfoPairPtr = nullptr;
        for (const BookTitles::value_type &bookInfoPair : bookTitles) {
            if (bookInfoPair.second == bookTitle) {
                bookInfoPairPtr = &bookInfoPair;
                break;
            }
        }
        if (bookInfoPairPtr == nullptr) {
            qWarning() << "No fitting book title was found";
            return AbstractDataTypeSharedPtr{};
        }
        bool convSucc = false;
        const unsigned short chapterNo{splitRes.at(1).toUShort(&convSucc)};
        if (convSucc == false) {
            qWarning() << "Failed to parse chapter number for Verse";
            return AbstractDataTypeSharedPtr{};
        }
        convSucc = false;
        const unsigned short verseNo{splitRes.at(2).toUShort(&convSucc)};
        if (convSucc == false) {
            qWarning() << "Failed to parse verse number for Verse";
            return AbstractDataTypeSharedPtr{};
        }
        const QString verseText{QString{argData}};

        return std::make_shared<Verse>(bookInfoPairPtr, chapterNo, verseNo,
                                          argData, argLevel);
    } else {
        qWarning() << "Invalid module passed for data type parsing";
        return AbstractDataTypeSharedPtr{};
    }
    return AbstractDataTypeSharedPtr{};
}
