#include "constants.h"
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
    for (unsigned short i = 0; i < categoryQty; ++i) {
        QDir catDir{QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
                    + "/bibleVerse/" + QString::number(i + 1)};
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
    QFile outFile{QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
                  + "/bibleVerse/1/" + argVerse.GetBookInfoPairPtr()->second
                  + "_" + QString::number(argVerse.GetChapterNo())
                  + "-" + QString::number(argVerse.GetVerseNo()) +  ".txt"};
    if (outFile.open(QIODevice::Text | QIODevice::WriteOnly) == false) {
        emit VerseSavingFailed();
        return;
    }
    const auto outDataBuf{argVerse.GetText().toUtf8()};
    if (outFile.write(outDataBuf) == outDataBuf.size()) {
        emit VerseSavingSucceeded();
        return;
    }
    emit VerseSavingFailed();
}
