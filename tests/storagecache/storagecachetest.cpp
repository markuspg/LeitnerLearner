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

    // check the item quantities after a few moves
    {
    StorageCache cache;
    // initialize with a few random values
    cache.SetCategoryQty(EModIds::BibleVerse, 5, 231);
    cache.SetCategoryQty(EModIds::SongVerse, 2, 42);
    cache.SetCategoryQty(EModIds::BibleVerse, 3, 993);
    cache.SetCategoryQty(EModIds::BibleVerse, 2, 32423);
    cache.SetCategoryQty(EModIds::BibleVerse, 7, 192);

    // conduct a few moves
    cache.ItemGotMoved(EModIds::SongVerse, 2, 1);
    cache.ItemGotMoved(EModIds::BibleVerse, 5, 0);
    cache.ItemGotMoved(EModIds::BibleVerse, 7, 0);
    cache.ItemGotMoved(EModIds::BibleVerse, 3, 4);

    // check if the values got moved properly
    QCOMPARE(cache.GetItemQty(EModIds::SongVerse, 0), 0);
    QCOMPARE(cache.GetItemQty(EModIds::SongVerse, 1), 1);
    QCOMPARE(cache.GetItemQty(EModIds::SongVerse, 2), 41);
    QCOMPARE(cache.GetItemQty(EModIds::SongVerse, 3), 0);
    QCOMPARE(cache.GetItemQty(EModIds::SongVerse, 4), 0);
    QCOMPARE(cache.GetItemQty(EModIds::SongVerse, 5), 0);
    QCOMPARE(cache.GetItemQty(EModIds::SongVerse, 6), 0);
    QCOMPARE(cache.GetItemQty(EModIds::SongVerse, 7), 0);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 0), 2);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 1), 0);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 2), 32423);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 3), 992);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 4), 1);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 5), 230);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 6), 0);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 7), 191);

    // check if the data is still valid and unchanged after a thrown exception
    QVERIFY_EXCEPTION_THROWN(cache.ItemGotMoved(EModIds::ZZZ_MOD_QTY, 7, 1),
                             std::out_of_range);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 1), 0);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 7), 191);
    QCOMPARE(cache.GetItemQty(EModIds::SongVerse, 1), 1);
    QCOMPARE(cache.GetItemQty(EModIds::SongVerse, 7), 0);
    QVERIFY_EXCEPTION_THROWN(cache.ItemGotMoved(EModIds::BibleVerse, 8, 3),
                             std::out_of_range);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 3), 992);
    QVERIFY_EXCEPTION_THROWN(cache.ItemGotMoved(EModIds::BibleVerse, 2, 8),
                             std::out_of_range);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 3), 992);
    cache.ItemGotMoved(EModIds::BibleVerse, 2, 3);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 2), 32422);
    QCOMPARE(cache.GetItemQty(EModIds::BibleVerse, 3), 993);
    }
}

QTEST_APPLESS_MAIN(StorageCacheTest)

#include "storagecachetest.moc"
