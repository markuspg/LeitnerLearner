#include "constants.h"
#include "filestoragebackend.h"

#include <QDebug>
#include <QDir>
#include <QFileInfo>
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
    if (UpdateCache() == false) {
        qWarning() << "Failed to update FileStorageBackend cache";
        throw IOException{};
    }
}

void FileStorageBackend::RetrieveRandomVerse()
{
    emit VerseRetrievalFailed();
}

void FileStorageBackend::SaveVerse(const Verse &argVerse)
{
    QFile outFile{QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
                  + "/bibleVerse/1/" + argVerse.GetIdentifier() + ".txt"};
    if (outFile.open(QIODevice::Text | QIODevice::WriteOnly) == false) {
        emit VerseSavingFailed();
        return;
    }
    const auto outDataBuf{argVerse.GetData()};
    if (outFile.write(outDataBuf) == outDataBuf.size()) {
        emit VerseSavingSucceeded();
        return;
    }
    emit VerseSavingFailed();
}

bool FileStorageBackend::UpdateCache()
{
    for (unsigned short i = 0; i < categoryQty; ++i) {
        const QString dirPath{QStandardPaths::writableLocation(
                              QStandardPaths::AppDataLocation) + "/bibleVerse/"
                              + QString::number(i + 1)};
        if (QFile::exists(dirPath) == false) {
            return false;
        }
        QDir dirInfo{dirPath};
        cache.SetCategoryQty(i,
                             static_cast<unsigned long>(dirInfo.entryList(
                                                            QStringList{"*.txt"},
                                                            QDir::Files).size()));
    }
    return true;
}
