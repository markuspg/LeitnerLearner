#include "backend.h"
#include "configurationhandler.h"
#include "filestoragebackend.h"
#include "sqlitestoragebackend.h"

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
}
