#include "sqlitestoragebackend.h"

SqliteStorageBackend::SqliteStorageBackend(QObject *const argParent) :
    AbstractStorageBackend{argParent}
{
}

void SqliteStorageBackend::RetrieveRandomVerse()
{
    emit VerseRetrievalFailed();
}

void SqliteStorageBackend::SaveVerse(const Verse &argVerse)
{
    Q_UNUSED(argVerse)

    emit VerseSavingFailed();
}

bool SqliteStorageBackend::UpdateCache()
{
    return false;
}
