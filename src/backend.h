#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class AbstractStorageBackend;
class ConfigurationHandler;

class Backend : public QObject
{
    Q_OBJECT

public:
    Backend(QObject *argParent = nullptr);

    ConfigurationHandler* GetConfigHndlr() const noexcept { return configHndlr; }
    AbstractStorageBackend* GetStorageBcknd() const noexcept { return storageBackend; }
    void Initialize();
    Q_INVOKABLE void saveVerse(const QString &argBook, int argChapterNo,
                               int argVerseNo, const QString &argVerseText);

private:
    ConfigurationHandler *const configHndlr = nullptr;
    AbstractStorageBackend *const storageBackend = nullptr;
};

#endif // BACKEND_H
