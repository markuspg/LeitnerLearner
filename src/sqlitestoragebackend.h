#ifndef SQLITESTORAGEBACKEND_H
#define SQLITESTORAGEBACKEND_H

#include "abstractstoragebackend.h"

class SqliteStorageBackend : public AbstractStorageBackend
{
    Q_OBJECT

public:
    explicit SqliteStorageBackend(QObject *const argParent = nullptr);

public slots:
    void RetrieveRandomVerse() override;
    void SaveData(const AbstractDataTypeSharedPtr &argData) override;

protected:
    bool UpdateCache() override;
};

#endif // SQLITESTORAGEBACKEND_H
