#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class AbstractStorageBackend;

namespace Ui {
class MainWindow;
} // namespace Ui

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *const argParent = nullptr);
    ~MainWindow() override;

private:
    AbstractStorageBackend *storageBackend = nullptr;
    Ui::MainWindow *const ui = nullptr;
};

#endif // MAINWINDOW_H
