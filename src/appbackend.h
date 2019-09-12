#ifndef APPBACKEND_H
#define APPBACKEND_H

#include <QObject>

class AbstractStorageBackend;
class ConfigurationHandler;

class AppBackend : public QObject
{
public:
    AppBackend(QObject *argParent = nullptr);

private:
    ConfigurationHandler *const configHndlr = nullptr;
    AbstractStorageBackend *const storageBackend = nullptr;
};

#endif // APPBACKEND_H
