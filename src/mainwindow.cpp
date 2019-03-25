#include "mainwindow.h"
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
