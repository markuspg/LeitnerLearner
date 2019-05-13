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

#ifndef CONFIGURATIONHANDLER_H
#define CONFIGURATIONHANDLER_H

#include <QObject>

class ConfigurationHandler : public QObject
{
    Q_OBJECT

public:
    enum class EConfigValues {
        AAA_INVALID,

        STORAGE_BACKEND,
    };
    using ECV = EConfigValues;

    explicit ConfigurationHandler(QObject *const argParent = nullptr);

    QString GetConfigValue(const EConfigValues argConfVal) const;
    void SetConfigValue(const EConfigValues argConfVal, const QString &argVal);
    bool SyncConfiguration();
};

#endif // CONFIGURATIONHANDLER_H
