#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class AbstractStorageBackend;
class ConfigurationHandler;

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int savedVerses READ GetSavedVerses() NOTIFY SavedVersesChanged)

public:
    Backend(QObject *argParent = nullptr);

    ConfigurationHandler* GetConfigHndlr() const noexcept { return configHndlr; }
    int GetSavedVerses() const noexcept { return savedVersesQty; }
    AbstractStorageBackend* GetStorageBcknd() const noexcept { return storageBackend; }
    void Initialize();
    Q_INVOKABLE void saveVerse(const QString &argBook, int argChapterNo,
                               int argVerseNo, const QString &argVerseText);

signals:
    void SavedVersesChanged();

private:
    ConfigurationHandler *const configHndlr = nullptr;
    unsigned int savedVersesQty = 0u;
    AbstractStorageBackend *const storageBackend = nullptr;
};

#endif // BACKEND_H
