#include "storagecache.h"

#include <stdexcept>

StorageCache::StorageCache() :
    itemsPerCat{}
{
}

void StorageCache::SetCategoryQty(const unsigned short argCatIdx,
                                  const unsigned long argQty)
{
    if (argCatIdx >= categoryQty) {
        throw std::out_of_range{"Invalid category index given for update"};
    }
    itemsPerCat[argCatIdx] = argQty;
}
