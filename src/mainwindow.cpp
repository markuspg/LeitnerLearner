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
#include "filestoragebackend.h"
#include "mainwindow.h"
#include "sqlitestoragebackend.h"
#include "ui_mainwindow.h"
#include "modules/bibleVerse/versechecker.h"
#include "modules/bibleVerse/verseentry.h"
#include "modules/songVerse/songverseentry.h"

#include <QDebug>

#include <memory>

MainWindow::MainWindow(QWidget *const argParent) :
    QMainWindow{argParent},
    configHndlr{new ConfigurationHandler},
    storageBackend{configHndlr->GetConfigValue(
                       ConfigurationHandler::ECV::STORAGE_BACKEND) == "file"
        ? reinterpret_cast<AbstractStorageBackend*>(new FileStorageBackend)
        : reinterpret_cast<AbstractStorageBackend*>(new SqliteStorageBackend)},
    ui{new Ui::MainWindow}
{
    configHndlr->setParent(this);
    storageBackend->setParent(this);

    ui->setupUi(this);
    const auto tmpChecker = new VerseChecker{this};
    connect(tmpChecker, &AbstractDataChecker::DataVerificationFailed,
            storageBackend, &AbstractStorageBackend::MoveDataOneLevelDown);
    connect(tmpChecker, &AbstractDataChecker::DataVerificationSucceeded,
            storageBackend, &AbstractStorageBackend::MoveDataOneLevelUp);
    connect(storageBackend, &AbstractStorageBackend::DataMovingFailed,
            tmpChecker, &AbstractDataChecker::DataLevelUpdateFailed);
    connect(storageBackend, &AbstractStorageBackend::DataRetrievalSucceeded,
            tmpChecker, &AbstractDataChecker::SetDataToCheck);
    auto tmpLayoutItem = ui->VLCheck->replaceWidget(ui->WCheck, tmpChecker);
    if (tmpLayoutItem != nullptr) {
        tmpLayoutItem->widget()->deleteLater();
        delete tmpLayoutItem;
        tmpLayoutItem = nullptr;
    } else {
        qWarning() << "Could not replace WCheck";
    }
    tmpChecker->show();

    const auto &modNames{GetModuleNames()};
    for (const auto &modName : modNames) {
        ui->CBModuleChooser->addItem(modName.second,
                                     QVariant::fromValue(modName.first));
    }
    connect(ui->CBModuleChooser, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::OnModChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Initialize()
{
    ui->CBModuleChooser->currentIndexChanged(0);
    storageBackend->RetrieveRandomData();
}

void MainWindow::OnModChanged(const int argCurrentIdx)
{
    Q_UNUSED(argCurrentIdx)

    const auto newModVar{ui->CBModuleChooser->currentData()};
    if (newModVar.canConvert<EModIds>() == false) {
        qWarning() << "Invalid data in CBModuleChooser";
        return;
    }

    const auto newMod{newModVar.value<EModIds>()};
    AbstractDataEntry *tmpEntry = nullptr;
    if (newMod == EModIds::BibleVerse) {
        tmpEntry = new VerseEntry{this};
    } else if (newMod == EModIds::SongVerse) {
        tmpEntry = new SongVerseEntry{this};
    } else {
        qWarning() << "Invalid new module for entry chosen"
                   << static_cast<std::underlying_type<EModIds>::type>(newMod);
    return;
    }

    connect(tmpEntry, &AbstractDataEntry::Req_DataSaving,
            storageBackend, &AbstractStorageBackend::SaveData);
    connect(storageBackend, &AbstractStorageBackend::DataSavingFailed,
            tmpEntry, &AbstractDataEntry::OnDataSavingFailed);
    connect(storageBackend, &AbstractStorageBackend::DataSavingSucceeded,
            tmpEntry, &AbstractDataEntry::OnDataSavingSucceeded);
    auto tmpLayoutItem = ui->VLEntries->replaceWidget(ui->WEntry,
                                                            tmpEntry);
    if (tmpLayoutItem != nullptr) {
        ui->WEntry = tmpEntry;
        tmpLayoutItem->widget()->deleteLater();
        delete tmpLayoutItem;
        tmpLayoutItem = nullptr;
    } else {
        qWarning() << "Could not replace WBibleVerseEntry";
    }
}
