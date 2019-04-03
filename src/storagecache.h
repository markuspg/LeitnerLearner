#ifndef STORAGECACHE_H
#define STORAGECACHE_H

#include "constants.h"

class StorageCache
{
public:
    explicit StorageCache();

    void ItemGotAnsweredCorrectly(const unsigned short argItemsCurrentCat);
    void ItemGotAnsweredWrongly(const unsigned short argItemsCurrentCat);
    void SetCategoryQty(const unsigned short argCatIdx,
                        const unsigned long argQty);

private:
    unsigned long itemsPerCat[categoryQty];
};

#endif // STORAGECACHE_H
