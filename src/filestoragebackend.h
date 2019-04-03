#ifndef FILESTORAGEBACKEND_H
#define FILESTORAGEBACKEND_H

#include "abstractstoragebackend.h"

class FileStorageBackend : public AbstractStorageBackend
{
    Q_OBJECT

public:
    explicit FileStorageBackend(QObject *const argParent = nullptr);

public slots:
    void RetrieveRandomVerse() override;
    void SaveVerse(const Verse &argVerse) override;

protected:
    bool UpdateCache() override;
};

#endif // FILESTORAGEBACKEND_H
