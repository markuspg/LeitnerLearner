#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    Ui::MainWindow *const ui = nullptr;
};

#endif // MAINWINDOW_H
