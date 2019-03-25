#include "filestoragebackend.h"

FileStorageBackend::FileStorageBackend(QObject *const argParent) :
    AbstractStorageBackend{argParent}
{
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
