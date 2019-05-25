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

#ifndef STORAGECACHE_H
#define STORAGECACHE_H

#include "global_definitions.h"
#include "modules/helpers.h"

#include <boost/optional.hpp>

#include <map>
#include <random>

class StorageCache
{
public:
    struct DrawResult {
        constexpr DrawResult(EModIds argMod, ll::Level argLvlIdx,
                             ll::ItemQty argItemIdx) :
            mod{argMod},
            lvlIdx{argLvlIdx},
            itemIdx{argItemIdx}
        {
        }

        const EModIds mod;
        const ll::Level lvlIdx;
        const ll::ItemQty itemIdx;
    };

    using LevelQtyArr = std::array<ll::ItemQty, ll::levelQty>;

    StorageCache();

    boost::optional<DrawResult> DoMonteCarloDraw() const;
    ll::ItemQty GetTotalStoredItemsQty() const;
    void InsertNewItem(EModIds argMod);
    void ItemGotMoved(EModIds argItemsMod, ll::Level argItemsPrevLvl,
                      ll::Level argItemsNewLvl);
    void SetCategoryQty(EModIds argMod, ll::Level argLvlIdx,
                        ll::ItemQty argQty);

#ifdef CACHE_TEST
    ll::ItemQty GetItemQty(EModIds argItemsMod, ll::Level argItemsLvl) const
            { return itemsPerModPerLvl.at(argItemsMod).at(argItemsLvl); }
#endif

private:
    mutable std::uniform_real_distribution<double> dist;
    mutable std::mt19937_64 eng;
    std::map<EModIds, LevelQtyArr> itemsPerModPerLvl;
};

#endif // STORAGECACHE_H
