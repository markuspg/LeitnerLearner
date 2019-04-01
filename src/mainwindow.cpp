#include "configurationhandler.h"
#include "filestoragebackend.h"
#include "mainwindow.h"
#include "sqlitestoragebackend.h"
#include "ui_mainwindow.h"
#include "versechecker.h"
#include "verseentry.h"

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
    connect(tmpEntry, &VerseEntry::Req_VerseSaving,
            storageBackend, &AbstractStorageBackend::SaveVerse);
    connect(storageBackend, &AbstractStorageBackend::VerseSavingFailed,
            tmpEntry, &VerseEntry::OnVerseSavingFailed);
    connect(storageBackend, &AbstractStorageBackend::VerseSavingSucceeded,
            tmpEntry, &VerseEntry::OnVerseSavingSucceeded);
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
