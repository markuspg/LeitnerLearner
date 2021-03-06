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

#ifndef HELPERS_H
#define HELPERS_H

#include <QMetaType>

#include <array>

/*!
 * \brief The EModIds enum's values are used as unique ids for the modules
 *
 * The numerical id values should be available for use in other parts of the
 * program. Therefore their order should NEVER change. New module ids should be
 * added below the existing ones.
 */
enum class EModIds {
    BibleVerse,
    SongVerse,

    // this element should always be last to represent the quantity of modules
    ZZZ_MOD_QTY
};
Q_DECLARE_METATYPE(EModIds)

using ModNamesArr = std::array<std::pair<EModIds, const char *>, 1>;

const char * GetModuleNameById(EModIds argModId);
const ModNamesArr& GetModuleNames();

#endif // HELPERS_H
