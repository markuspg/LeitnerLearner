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

std::pair<EModIds, unsigned short> StorageCache::DoMonteCarloDraw() const
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

    // choose module
    auto accumulatedItems = 0ul;
    EModIds chosenModule = EModIds::ZZZ_MOD_QTY;
    const auto partitionQty = static_cast<unsigned long>(modDraw * totalItemQty);
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
    unsigned short chosenLevel = 0;
    const auto modQty = std::accumulate(itemsPerModPerLvl.at(chosenModule).cbegin(),
                                        itemsPerModPerLvl.at(chosenModule).cend(),
                                        0ul);
    const auto lvlPartQty = static_cast<unsigned long>(lvlDraw
                                                       * modQty);
    unsigned short lvlIdx = 0;
    for (const auto &lvlQty : itemsPerModPerLvl.at(chosenModule)) {
        if ((accumulatedItems + lvlQty) >= lvlPartQty) {
            chosenLevel = lvlIdx;
            break;
        }
        ++lvlIdx;
    }

    return std::make_pair(chosenModule, chosenLevel);
}

unsigned long StorageCache::GetTotalStoredItemsQty() const
{
    unsigned long totalQty = 0;

    for (const auto &module : itemsPerModPerLvl) {
        totalQty += std::accumulate(module.second.cbegin(),
                                    module.second.cend(), 0ul);
    }

    return totalQty;
}

void StorageCache::ItemGotAnsweredCorrectly(const EModIds argItemsMod,
                                            const unsigned short argItemsCurrentCat)
{
    auto &currMod{itemsPerModPerLvl.at(argItemsMod)};

    // if the item is already in the highest category it cannot be moved further
    if (argItemsCurrentCat == ll::categoryQty - 1) {
        return;
    }

    const auto currLevelQty = currMod.at(argItemsCurrentCat);
    // the quantity in any level should never be attempted to be decreased below 0
    if (currLevelQty == 0) {
        std::cerr << "A level's quantity cannot be decreased below '0'" << std::endl;
        throw std::exception{};
    }
    currMod.at(argItemsCurrentCat) -= 1;
    currMod.at(argItemsCurrentCat + 1) += 1;
}

void StorageCache::ItemGotAnsweredWrongly(const EModIds argItemsMod,
                                          const unsigned short argItemsCurrentCat)
{
    auto &currMod{itemsPerModPerLvl.at(argItemsMod)};

    // if the item is already in the lowest category it cannot be moved further
    if (argItemsCurrentCat == 0) {
        return;
    }

    const auto currLevelQty = currMod.at(argItemsCurrentCat);
    // the quantity in any level should never be attempted to be decreased below 0
    if (currLevelQty == 0) {
        std::cerr << "A level's quantity cannot be decreased below '0'" << std::endl;
        throw std::exception{};
    }
    currMod.at(argItemsCurrentCat) -= 1;
    currMod.at(argItemsCurrentCat - 1) += 1;
}

bool StorageCache::SetCategoryQty(const EModIds argMod,
                                  const unsigned short argCatIdx,
                                  const unsigned long argQty) noexcept
{
    try {
        itemsPerModPerLvl.at(argMod).at(argCatIdx) = argQty;
    } catch ([[maybe_unused]] const std::out_of_range &argExc) {
        std::cerr << "Invalid access of \"itemsPerModPerCat\"\n";
        return false;
    }
    return true;
}
