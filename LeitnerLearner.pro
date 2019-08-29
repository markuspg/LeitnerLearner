TARGET = LeitnerLearner

CONFIG += sailfishapp c++11

DEFINES += QML_APP

SOURCES += \
    src/main.cpp \

DISTFILES += \
    LeitnerLearner.desktop \
    qml/LeitnerLearner.qml \
    qml/cover/CoverPage.qml \
    qml/pages/ModeChooser.qml \
    qml/pages/VerseCheck.qml \
    qml/pages/VerseEntry.qml \
    rpm/LeitnerLearner.changes.in \
    rpm/LeitnerLearner.changes.run.in \
    rpm/LeitnerLearner.spec \
    rpm/LeitnerLearner.yaml \
    translations/*.ts \

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

TRANSLATIONS += translations/LeitnerLearner-de.ts
