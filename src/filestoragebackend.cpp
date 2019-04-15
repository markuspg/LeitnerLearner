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

#include "filestoragebackend.h"

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>

FileStorageBackend::FileStorageBackend(QObject *const argParent) :
    AbstractStorageBackend{argParent}
{
    // prepare storage directories for all modules' data
    for (const auto &moduleData : GetModuleNames()) {
        // first create the modules' directories themselves
        const QString dataDirPath{QStandardPaths::writableLocation(
                                      QStandardPaths::AppDataLocation)
                                  + "/" + moduleData.second};
        QDir dataDir{dataDirPath};
        if (QFile::exists(dataDir.absolutePath()) == false) {
            if (dataDir.mkpath(dataDir.absolutePath()) == false) {
                qWarning() << "Failed to create data directory for FileStorageBackend";
                throw IOException{};
            }
        }
        // then create the directories for the different learning levels
        for (unsigned short i = 0; i < categoryQty; ++i) {
            QDir catDir{dataDirPath + "/" + QString::number(i + 1)};
            if (QFile::exists(catDir.absolutePath()) == false) {
                if (catDir.mkpath(catDir.absolutePath()) == false) {
                    qWarning() << "Failed to create category directories"
                                  " for FileStorageBackend";
                    throw IOException{};
                }
            }
        }
    }
    if (UpdateCache() == false) {
        qWarning() << "Failed to update FileStorageBackend cache";
        throw IOException{};
    }
}

bool FileStorageBackend::MoveData(AbstractDataTypeSharedPtr argData,
                                  const bool argMoveLevelUp)
{
    Q_UNUSED(argData)
    Q_UNUSED(argMoveLevelUp)

    return false;
}

void FileStorageBackend::RetrieveRandomData()
{
    emit DataRetrievalFailed();
}

void FileStorageBackend::SaveData(const AbstractDataTypeSharedPtr &argData)
{
    if (!argData) {
        qWarning() << "Empty data got passed for saving";
        emit DataSavingFailed();
    }
    QFile outFile{QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
                  + QString{"/%1/1/"}.arg(GetModuleNameById(argData->GetType()))
                            + argData->GetIdentifier() + ".txt"};
    if (outFile.open(QIODevice::Text | QIODevice::WriteOnly) == false) {
        emit DataSavingFailed();;
        return;
    }
    const auto outDataBuf{argData->GetData()};
    if (outFile.write(outDataBuf) == outDataBuf.size()) {
        emit DataSavingSucceeded();
        return;
    }
    emit DataSavingFailed();
}

bool FileStorageBackend::UpdateCache()
{
    for (unsigned short i = 0; i < categoryQty; ++i) {
        const QString dirPath{QStandardPaths::writableLocation(
                              QStandardPaths::AppDataLocation)
                              + QString{"/%1/"}.arg(GetModuleNameById(EModIds::BibleVerse))
                              + QString::number(i + 1)};
        if (QFile::exists(dirPath) == false) {
            return false;
        }
        QDir dirInfo{dirPath};
        if (cache.SetCategoryQty(EModIds::BibleVerse, i,
                             static_cast<unsigned long>(dirInfo.entryList(
                                                            QStringList{"*.txt"},
                                                            QDir::Files).size()))
                == false) {
            return false;
        }
    }
    return true;
}
