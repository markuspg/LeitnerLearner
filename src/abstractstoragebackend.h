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

#ifndef ABSTRACTSTORAGEBACKEND_H
#define ABSTRACTSTORAGEBACKEND_H

#include "abstractdatatype.h"
#include "storagecache.h"

#include <QException>
#include <QObject>

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
    void MoveDataOneLevelDown(AbstractDataTypeSharedPtr argData);
    void MoveDataOneLevelUp(AbstractDataTypeSharedPtr argData);
    virtual void RetrieveRandomData() = 0;
    virtual void SaveData(const AbstractDataTypeSharedPtr &argData) = 0;

signals:
    void DataMovingFailed();
    void DataRetrievalFailed();
    void DataRetrievalSucceeded(AbstractDataTypeSharedPtr argData);
    void DataSavingFailed();
    void DataSavingSucceeded();

protected:
    virtual void MoveData(AbstractDataTypeSharedPtr argData,
                          bool argMoveLevelUp) = 0;
    virtual bool UpdateCache() = 0;

    StorageCache cache;
};

#endif // ABSTRACTSTORAGEBACKEND_H
