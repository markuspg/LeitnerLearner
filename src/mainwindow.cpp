#include "configurationhandler.h"
#include "filestoragebackend.h"
#include "mainwindow.h"
#include "sqlitestoragebackend.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}
