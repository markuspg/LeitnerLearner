#include "filestoragebackend.h"

#include <QDebug>
#include <QDir>
#include <QStandardPaths>

FileStorageBackend::FileStorageBackend(QObject *const argParent) :
    AbstractStorageBackend{argParent}
{
    QDir dataDir{QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
                 + "/bibleVerse"};
    if (QFile::exists(dataDir.absolutePath()) == false) {
        if (dataDir.mkpath(dataDir.absolutePath()) == false) {
            qWarning() << "Failed to create data directory for FileStorageBackend";
            throw IOException{};
        }
    }
    for (unsigned short i = 1; i < 7; ++i) {
        QDir catDir{QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
                    + "/bibleVerse/" + QString::number(i)};
        if (QFile::exists(catDir.absolutePath()) == false) {
            if (catDir.mkpath(catDir.absolutePath()) == false) {
                qWarning() << "Failed to create category directories"
                              " for FileStorageBackend";
                throw IOException{};
            }
        }
    }
}

void FileStorageBackend::RetrieveRandomVerse()
{
    emit VerseRetrievalFailed();
}

void FileStorageBackend::SaveVerse(const Verse &argVerse)
{
    Q_UNUSED(argVerse)

    emit VerseSavingFailed();
}
