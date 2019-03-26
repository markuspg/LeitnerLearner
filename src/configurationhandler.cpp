#include "booktitles.h"
#include "configurationhandler.h"

constexpr auto confsAndDefaults = std::experimental::make_array(
    std::make_pair(ConfigurationHandler::ECV::LAST_SAVED_BOOK,
                   bookTitles.at(0).second),
    std::make_pair(ConfigurationHandler::ECV::STORAGE_BACKEND,
                   "file"),
    std::make_pair(ConfigurationHandler::ECV::DEFAULT_TRANSLATION,
                   ""),
    std::make_pair(ConfigurationHandler::ECV::LAST_SAVED_VERSE_NO,
                   ""),
    std::make_pair(ConfigurationHandler::ECV::LAST_SAVED_CHAPTER_NO,
                   ""));

ConfigurationHandler::ConfigurationHandler(QObject *const argParent) :
    QObject{argParent}
{
}

QString ConfigurationHandler::GetConfigValue(
        const EConfigValues argConfVal) const
{
    Q_UNUSED(argConfVal)

    Q_UNUSED(confsAndDefaults)

    return QString{};
}

void ConfigurationHandler::SetConfigValue(const EConfigValues argConfVal,
                                          const QString &argVal)
{
    Q_UNUSED(argConfVal)
    Q_UNUSED(argVal)
}

bool ConfigurationHandler::SyncConfiguration()
{
    return false;
}
