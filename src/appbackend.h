#ifndef APPBACKEND_H
#define APPBACKEND_H

#include <QObject>

class AbstractStorageBackend;
class ConfigurationHandler;

class AppBackend : public QObject
{
    Q_OBJECT

public:
    AppBackend(QObject *argParent = nullptr);

    Q_INVOKABLE void saveVerse(const QString &argBook, int argChapterNo, int argVerseNo,
                   const QString &argVerseText);

private:
    ConfigurationHandler *const configHndlr = nullptr;
    AbstractStorageBackend *const storageBackend = nullptr;
};

#endif // APPBACKEND_H
