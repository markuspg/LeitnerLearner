#include "filestoragebackend.h"
#include "mainwindow.h"
#include "sqlitestoragebackend.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *const argParent) :
    QMainWindow{argParent},
    ui{new Ui::MainWindow}
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
