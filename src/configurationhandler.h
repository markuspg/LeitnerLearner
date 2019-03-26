#ifndef CONFIGURATIONHANDLER_H
#define CONFIGURATIONHANDLER_H

#include <QObject>

class ConfigurationHandler : public QObject
{
    Q_OBJECT

public:
    enum class EConfigValues {
        DEFAULT_TRANSLATION,
        LAST_SAVED_BOOK,
        LAST_SAVED_CHAPTER_NO,
        LAST_SAVED_VERSE_NO,
        STORAGE_BACKEND,
    };
    using ECV = EConfigValues;

    explicit ConfigurationHandler(QObject *const argParent = nullptr);

    QString GetConfigValue(const EConfigValues argConfVal) const;
    void SetConfigValue(const EConfigValues argConfVal, const QString &argVal);
    bool SyncConfiguration();
};

#endif // CONFIGURATIONHANDLER_H
