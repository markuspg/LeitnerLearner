#ifndef ABSTRACTSTORAGEBACKEND_H
#define ABSTRACTSTORAGEBACKEND_H

#include <QException>
#include <QObject>

#include "verse.h"

class Verse;

class IOException : public QException
{
    IOException* clone() const override;
    void raise() const override;
};

class AbstractStorageBackend : public QObject
{
    Q_OBJECT

public:
    explicit AbstractStorageBackend(QObject *const argParent = nullptr);

public slots:
    virtual void RetrieveRandomVerse() = 0;
    virtual void SaveVerse(const Verse &argVerse) = 0;

signals:
    void VerseRetrievalFailed();
    void VerseRetrievalSucceeded(Verse argVerse);
    void VerseSavingFailed();
    void VerseSavingSucceeded();
};

#endif // ABSTRACTSTORAGEBACKEND_H
