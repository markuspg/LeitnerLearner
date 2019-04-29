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

#include "storagecache.h"

#include <iostream>
#include <numeric>

StorageCache::StorageCache() :
    eng{std::random_device{}()}
{
    for (const auto &modInfo : GetModuleNames()) {
        itemsPerModPerLvl.emplace(modInfo.first,
                                  LevelQtyArr{});
    }
}

/*!
 * \brief Draw module and level of a random item
 * \return A DrawResult struct with the required info or empty, if no data available
 */
std::optional<StorageCache::DrawResult> StorageCache::DoMonteCarloDraw() const
{
    // draw a random category and level indicator
    const auto modDraw = dist(eng);
    const auto lvlDraw = dist(eng);

    // iterate modules one after the other and sum up their item quantites
    auto totalItemQty = 0ul;
    for (const auto &modLvls : itemsPerModPerLvl) {
        totalItemQty += std::accumulate(modLvls.second.cbegin(),
                                        modLvls.second.cend(), 0ul);
    }
    if  (totalItemQty == 0) {
        return std::optional<DrawResult>{};
    }

    // choose module
    auto accumulatedItems = 0ul;
    EModIds chosenModule = EModIds::ZZZ_MOD_QTY;
    const auto partitionQty = static_cast<ll::ItemQty>(modDraw * totalItemQty);
    for (const auto &modLvls : itemsPerModPerLvl) {
        const auto itemsInMod = std::accumulate(modLvls.second.cbegin(),
                                                modLvls.second.cend(), 0ul);
        if ((accumulatedItems + itemsInMod) >= partitionQty) {
            chosenModule = modLvls.first;
            break;
        }
        accumulatedItems += itemsInMod;
    }

    // choose level of module
    accumulatedItems = 0;
    ll::Level chosenLevel = 0;
    const auto modQty = std::accumulate(itemsPerModPerLvl.at(chosenModule).cbegin(),
                                        itemsPerModPerLvl.at(chosenModule).cend(),
                                        0ul);
    const auto lvlPartQty = static_cast<ll::ItemQty>(lvlDraw * modQty);
    ll::Level lvlIdx = 0;
    for (const auto &lvlQty : itemsPerModPerLvl.at(chosenModule)) {
        if ((accumulatedItems + lvlQty) >= lvlPartQty) {
            chosenLevel = lvlIdx;
            break;
        }
        ++lvlIdx;
    }

    std::uniform_int_distribution<ll::ItemQty> itemDist{
            0, itemsPerModPerLvl.at(chosenModule).at(chosenLevel) - 1};
    return DrawResult{chosenModule, chosenLevel, itemDist(eng)};
}

ll::ItemQty StorageCache::GetTotalStoredItemsQty() const
{
    ll::ItemQty totalQty = 0;

    for (const auto &module : itemsPerModPerLvl) {
        totalQty += std::accumulate(module.second.cbegin(),
                                    module.second.cend(), 0ul);
    }

    return totalQty;
}

void StorageCache::InsertNewItem(const EModIds argMod)
{
    itemsPerModPerLvl.at(argMod)[0] += 1;
}

void StorageCache::ItemGotMovedLevelUp(const EModIds argItemsMod,
                                       const ll::Level argItemsCurrentLvl)
{
    auto &currMod{itemsPerModPerLvl.at(argItemsMod)};

    // if the item is already in the highest category it cannot be moved further
    if (argItemsCurrentLvl == ll::levelQty - 1) {
        return;
    }

    const auto currLevelQty = currMod.at(argItemsCurrentLvl);
    // the quantity in any level should never be attempted to be decreased below 0
    if (currLevelQty == 0) {
        std::cerr << "A level's quantity cannot be decreased below '0'" << std::endl;
        throw std::exception{};
    }
    currMod.at(argItemsCurrentLvl) -= 1;
    currMod.at(argItemsCurrentLvl + 1) += 1;
}

void StorageCache::ItemGotMovelLevelDown(const EModIds argItemsMod,
                                         const ll::Level argItemsCurrentLvl)
{
    auto &currMod{itemsPerModPerLvl.at(argItemsMod)};

    // if the item is already in the lowest category it cannot be moved further
    if (argItemsCurrentLvl == 0) {
        return;
    }

    const auto currLevelQty = currMod.at(argItemsCurrentLvl);
    // the quantity in any level should never be attempted to be decreased below 0
    if (currLevelQty == 0) {
        std::cerr << "A level's quantity cannot be decreased below '0'" << std::endl;
        throw std::exception{};
    }
    currMod.at(argItemsCurrentLvl) -= 1;
    currMod.at(argItemsCurrentLvl - 1) += 1;
}

bool StorageCache::SetCategoryQty(const EModIds argMod,
                                  const ll::Level argLvlIdx,
                                  const ll::ItemQty argQty) noexcept
{
    try {
        itemsPerModPerLvl.at(argMod).at(argLvlIdx) = argQty;
    } catch ([[maybe_unused]] const std::out_of_range &argExc) {
        std::cerr << "Invalid access of \"itemsPerModPerCat\"\n";
        return false;
    }
    return true;
}
