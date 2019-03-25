#include <QApplication>

#include "mainwindow.h"
#include "verse.h"

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};
    app.setApplicationName("VerseAccumulator");

    qRegisterMetaType<Verse>();

    MainWindow mainWin;
    mainWin.show();

    return app.exec();
}
