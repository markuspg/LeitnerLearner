#ifndef STORAGECACHE_H
#define STORAGECACHE_H

class StorageCache
{
public:
    explicit StorageCache();

    void ItemGotAnsweredCorrectly(const unsigned short argItemsCurrentCat);
    void ItemGotAnsweredWrongly(const unsigned short argItemsCurrentCat);

private:
    unsigned long itemsPerCat[7];
};

#endif // STORAGECACHE_H
