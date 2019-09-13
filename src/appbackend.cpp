#include "appbackend.h"
#include "configurationhandler.h"
#include "filestoragebackend.h"
#include "sqlitestoragebackend.h"

AppBackend::AppBackend(QObject *const argParent) :
    QObject(argParent),
    configHndlr(new ConfigurationHandler),
    storageBackend(configHndlr->GetConfigValue(
                       ConfigurationHandler::ECV::STORAGE_BACKEND) == "file"
                   ? reinterpret_cast<AbstractStorageBackend*>(new FileStorageBackend)
                   : reinterpret_cast<AbstractStorageBackend*>(new SqliteStorageBackend))
{
    configHndlr->setParent(this);
    storageBackend->setParent(this);
}

void AppBackend::saveVerse(const QString &argBook, const int argChapterNo,
                           const int argVerseNo, const QString &argVerseText)
{
    Q_UNUSED(argBook)
    Q_UNUSED(argChapterNo)
    Q_UNUSED(argVerseNo)
    Q_UNUSED(argVerseText)
}
