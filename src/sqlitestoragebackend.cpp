#include "sqlitestoragebackend.h"

SqliteStorageBackend::SqliteStorageBackend(QObject *const argParent) :
    AbstractStorageBackend{argParent}
{
}

void SqliteStorageBackend::RetrieveRandomVerse()
{
    emit VerseRetrievalFailed();
}

void SqliteStorageBackend::SaveData(const AbstractDataTypeSharedPtr &argData)
{
    Q_UNUSED(argData)

    emit DataSavingFailed();
}

bool SqliteStorageBackend::UpdateCache()
{
    return false;
}
