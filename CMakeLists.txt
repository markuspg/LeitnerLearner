cmake_minimum_required(VERSION 3.13.4 FATAL_ERROR)

project(LeitnerLearner
    VERSION 0.1
    LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(leitner_learner
    src/abstractdatachecker.cpp
    src/abstractdatachecker.ui
    src/abstractdataentry.cpp
    src/abstractdataentry.ui
    src/abstractdatatype.cpp
    src/abstractentrywdgt.cpp
    src/abstractstoragebackend.cpp
    src/configurationhandler.cpp
    src/filestoragebackend.cpp
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.ui
    src/sqlitestoragebackend.cpp
    src/storagecache.cpp
    src/modules/helpers.cpp
    src/modules/bibleVerse/verse.cpp
    src/modules/bibleVerse/versechecker.cpp
    src/modules/bibleVerse/verseentry.cpp
    src/modules/bibleVerse/verseentrywdgt.cpp
    src/modules/bibleVerse/verseentrywdgt.ui)
target_link_libraries(leitner_learner PRIVATE Qt5::Widgets)
