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

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QStandardPaths>
#include <QTimer>

#include "abstractdatatype.h"
#ifdef WIDGETS_APP
#include "mainwindow.h"
#endif // WIDGETS_APP
#include "modules/bibleVerse/booktitles.h"

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};
    app.setApplicationName("LeitnerLearner");

    qRegisterMetaType<AbstractDataTypeSharedPtr>();
    qRegisterMetaType<BookInfoPairPtr>();

    QDir dataDir{QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)};
    if (QFile::exists(dataDir.absolutePath()) == false) {
        if (dataDir.mkpath(dataDir.absolutePath()) == false) {
            qWarning() << "Failed to create data directory";
            return 1;
        }
    }

#ifdef WIDGETS_APP
    MainWindow mainWin;
    mainWin.show();

    QTimer::singleShot(0, &mainWin, &MainWindow::Initialize);
#endif // WIDGETS_APP

    return app.exec();
}
