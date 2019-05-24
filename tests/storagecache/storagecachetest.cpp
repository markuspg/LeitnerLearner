#include <QtTest>

#include "storagecache.h"

#include <random>

class StorageCacheTest : public QObject
{
    Q_OBJECT

private slots:
    void InitAndTotalTest();
    void ItemMoveTest();

};

void StorageCacheTest::InitAndTotalTest()
{
    // check if exception is thrown on invalid module type
    {
    StorageCache cache;
    QVERIFY_EXCEPTION_THROWN(cache.SetCategoryQty(EModIds::ZZZ_MOD_QTY, 0, 0),
                             std::out_of_range);
    }

    // check if the item quantities are correctly computed with static values
    {
    StorageCache cache;
    cache.SetCategoryQty(EModIds::BibleVerse, 7, 25237);
    cache.SetCategoryQty(EModIds::BibleVerse, 2, 4437);
    cache.SetCategoryQty(EModIds::SongVerse, 0, 29120);
    cache.SetCategoryQty(EModIds::BibleVerse, 5, 25591);
    cache.SetCategoryQty(EModIds::SongVerse, 1, 23423);
    cache.SetCategoryQty(EModIds::SongVerse, 7, 30146);
    cache.SetCategoryQty(EModIds::SongVerse, 2, 3814);
    cache.SetCategoryQty(EModIds::BibleVerse, 1, 19727);
    cache.SetCategoryQty(EModIds::SongVerse, 5, 2154);
    cache.SetCategoryQty(EModIds::BibleVerse, 6, 21442);
    cache.SetCategoryQty(EModIds::SongVerse, 4, 3485);
    cache.SetCategoryQty(EModIds::BibleVerse, 3, 6672);
    cache.SetCategoryQty(EModIds::SongVerse, 6, 13281);
    cache.SetCategoryQty(EModIds::SongVerse, 3, 22999);
    cache.SetCategoryQty(EModIds::BibleVerse, 0, 12793);
    cache.SetCategoryQty(EModIds::BibleVerse, 4, 1397);
    QCOMPARE(cache.GetTotalStoredItemsQty(), 245718ul);
    }

    // check if the item quantites are correctly computed with random values
    {
    std::mt19937_64 eng{std::random_device{"/dev/urandom"}()};
    std::uniform_int_distribution<ll::ItemQty>
        dist{0, std::numeric_limits<unsigned int>::max()};
    StorageCache cache;
    auto totalItemQty = 0ul;
    for (ll::Level i = 0; i < ll::levelQty; ++i) {
        const auto newBibleVerseQty = dist(eng);
        cache.SetCategoryQty(EModIds::BibleVerse, i, newBibleVerseQty);
        totalItemQty += newBibleVerseQty;
        const auto newSongVerseQty = dist(eng);
        cache.SetCategoryQty(EModIds::SongVerse, i, newSongVerseQty);
        totalItemQty += newSongVerseQty;
    }
    QCOMPARE(cache.GetTotalStoredItemsQty(), totalItemQty);
    }
}

void StorageCacheTest::ItemMoveTest()
{
    // check if exception is thrown if an item should be moved from an empty level
    {
    StorageCache cache;
    // initialize with a few random values
    cache.SetCategoryQty(EModIds::BibleVerse, 0, 17);
    cache.SetCategoryQty(EModIds::SongVerse, 3, 17);
    cache.SetCategoryQty(EModIds::BibleVerse, 5, 2);
    cache.SetCategoryQty(EModIds::BibleVerse, 6, 28);

    // move items out of level 5, one item moves a level down ...
    cache.ItemGotMoved(EModIds::BibleVerse, 5, 4);
    // ... another item moves a level up ...
    cache.ItemGotMoved(EModIds::BibleVerse, 5, 6);
    // ... and then an exception is thrown since all items are gone
    QVERIFY_EXCEPTION_THROWN(cache.ItemGotMoved(EModIds::BibleVerse, 5, 3),
                             std::exception);
    }
}

QTEST_APPLESS_MAIN(StorageCacheTest)

#include "storagecachetest.moc"
