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

#ifndef SQLITESTORAGEBACKEND_H
#define SQLITESTORAGEBACKEND_H

#include "abstractstoragebackend.h"

class SqliteStorageBackend : public AbstractStorageBackend
{
    Q_OBJECT

public:
    explicit SqliteStorageBackend(QObject *const argParent = nullptr);

public slots:
    void RetrieveRandomData() override;
    void SaveData(const AbstractDataTypeSharedPtr &argData) override;

protected:
    bool UpdateCache() override;
};

#endif // SQLITESTORAGEBACKEND_H
