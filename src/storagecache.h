#ifndef STORAGECACHE_H
#define STORAGECACHE_H

#include "constants.h"

class StorageCache
{
public:
    explicit StorageCache();

    void ItemGotAnsweredCorrectly(const unsigned short argItemsCurrentCat);
    void ItemGotAnsweredWrongly(const unsigned short argItemsCurrentCat);

private:
    unsigned long itemsPerCat[categoryQty];
};

#endif // STORAGECACHE_H
