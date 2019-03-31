#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QStandardPaths>

#include "mainwindow.h"
#include "verse.h"

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};
    app.setApplicationName("LeitnerLearner");

    qRegisterMetaType<BookInfoPairPtr>();
    qRegisterMetaType<Verse>();

    QDir dataDir{QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)};
    if (QFile::exists(dataDir.absolutePath()) == false) {
        if (dataDir.mkpath(dataDir.absolutePath()) == false) {
            qWarning() << "Failed to create data directory";
            return 1;
        }
    }

    MainWindow mainWin;
    mainWin.show();

    return app.exec();
}
