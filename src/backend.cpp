#include "backend.h"
#include "configurationhandler.h"
#include "filestoragebackend.h"
#include "sqlitestoragebackend.h"
#include "modules/bibleVerse/verse.h"

#include <QDebug>

Backend::Backend(QObject *const argParent) :
    QObject(argParent),
    configHndlr(new ConfigurationHandler),
    storageBackend(configHndlr->GetConfigValue(
                       ConfigurationHandler::ECV::STORAGE_BACKEND) == "file"
                   ? reinterpret_cast<AbstractStorageBackend*>(new FileStorageBackend)
                   : reinterpret_cast<AbstractStorageBackend*>(new SqliteStorageBackend))
{
    configHndlr->setParent(this);
    storageBackend->setParent(this);

    connect(storageBackend, &AbstractStorageBackend::DataSavingSucceeded,
            this, &Backend::VerseGotSuccessfullySaved);
}

void Backend::Initialize()
{
    storageBackend->RetrieveRandomData();
}

void Backend::saveVerse(const QString &argBook, int argChapterNo,
                        int argVerseNo, const QString &argVerseText)
{
    BookTitles::const_iterator foundCit = bookTitles.cend();

    for (auto cit = bookTitles.cbegin(); cit != bookTitles.cend(); ++cit) {
        if (QString{&(*cit->second)} == argBook) {
            foundCit = cit;
            break;
        }
    }
    if (foundCit == bookTitles.cend()) {
        qWarning() << "Book title could not be found";
        return;
    }

    // Filter invalid chapter and verse numbers
    if (((argChapterNo < 1) || argChapterNo > 150)
            || ((argVerseNo < 1) || argVerseNo > 176)) {
        qWarning() << "Invalid chapter or verse number given";
        return;
    }

    storageBackend->SaveData(
                AbstractDataTypeSharedPtr{
                    new Verse(&(*foundCit), argChapterNo,
                              argVerseNo, argVerseText, 0)});
}

void Backend::VerseGotSuccessfullySaved()
{
    ++savedVersesQty;
    emit SavedVersesChanged();
}
