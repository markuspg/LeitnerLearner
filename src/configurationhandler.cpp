/*
 * Copyright 2019 Markus Prasser
 *
 * This file is part of LeitnerLearner.
 *
 *  LeitnerLearner is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  LeitnerLearner is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with LeitnerLearner.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "configurationhandler.h"

#include <QDebug>
#include <QFile>
#include <QStandardPaths>

#include <experimental/array>

// ConfOpt ---------------------------------------------------------------------

struct ConfOpt {
    constexpr ConfOpt(ConfigurationHandler::EConfigValues argEnumVal,
                      const char *argName, const char *argDefaultVal) noexcept :
        defaultVal{argDefaultVal},
        enumVal{argEnumVal},
        name{argName}
    {
    }

    const char *const defaultVal = nullptr;
    const ConfigurationHandler::EConfigValues enumVal
        = ConfigurationHandler::EConfigValues::AAA_INVALID;
    const char * const name = nullptr;
};

constexpr auto configOpts = std::experimental::make_array(
            ConfOpt{ConfigurationHandler::EConfigValues::ACTIVE_MODULES,
                    "active_modules", "BibleVerse"},
            ConfOpt{ConfigurationHandler::EConfigValues::STORAGE_BACKEND,
                    "storage_backend", "file"});

// ConfigurationHandler --------------------------------------------------------

ConfigurationHandler::ConfigurationHandler(QObject *const argParent) :
    QObject{argParent}
{
    if (UpdateConfigFile() == false) {
        throw ConfigException{};
    }
}

QString ConfigurationHandler::GetConfigValue(
        const EConfigValues argConfVal) const
{
    Q_UNUSED(argConfVal)

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

bool ConfigurationHandler::UpdateConfigFile() {
    const QString configFilePath{QStandardPaths::writableLocation(
                    QStandardPaths::AppDataLocation) + "/" + configFileName};

    QFile confFile{configFilePath};
    // create the configuration file if it does not exist yet
    if (confFile.exists() == false) {
        if (confFile.open(QIODevice::Text | QIODevice::WriteOnly) == false) {
            qWarning() << "Failed to create and open new configuration file";
            return false;
        }
        confFile.close();
    }


    return true;
}

// ConfigurationHandler::ConfigException ---------------------------------------

ConfigurationHandler::ConfigException*
ConfigurationHandler::ConfigException::clone() const
{
    return new ConfigException{*this};
}

void ConfigurationHandler::ConfigException::raise() const
{
    throw *this;
}
