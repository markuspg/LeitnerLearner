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
    auto tmpLayoutItem = ui->VLCheck->replaceWidget(ui->WCheck, tmpChecker);
    if (tmpLayoutItem != nullptr) {
        tmpLayoutItem->widget()->deleteLater();
        delete tmpLayoutItem;
        tmpLayoutItem = nullptr;
    } else {
        qWarning() << "Could not replace WCheck";
    }
    tmpChecker->show();
    const auto tmpEntry = new VerseEntry{this};
    connect(tmpEntry, &AbstractDataEntry::Req_DataSaving,
            storageBackend, &AbstractStorageBackend::SaveData);
    connect(storageBackend, &AbstractStorageBackend::DataSavingFailed,
            tmpEntry, &AbstractDataEntry::OnDataSavingFailed);
    connect(storageBackend, &AbstractStorageBackend::DataSavingSucceeded,
            tmpEntry, &AbstractDataEntry::OnDataSavingSucceeded);
    tmpLayoutItem = ui->VLEntry->replaceWidget(ui->WEntry, tmpEntry);
    if (tmpLayoutItem != nullptr) {
        tmpLayoutItem->widget()->deleteLater();
        delete tmpLayoutItem;
        tmpLayoutItem = nullptr;
    } else {
        qWarning() << "Could not replace WEntry";
    }
    tmpEntry->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
