import QtQuick 2.0
import Sailfish.Silica 1.0
import com.github.leitnerlearner.backend 1.0

Page {
    id: verseCheckPage

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    Component.onCompleted: appBackend.requestNextVerse()

    Backend {
        id: appBackend
    }

    SilicaFlickable {
        anchors.fill: parent
        contentHeight: checkedVerseDataColumn.height + Theme.paddingLarge

    Column {
        id: checkedVerseDataColumn
        width: parent.width

    Label {
        id: bookLabel
        text: appBackend.checkedBook
        width: parent.width
    }

    Label {
        id: chapterNoLabel
        text: appBackend.checkedChapterNo
        width: parent.width
    }

    Label {
        id: verseNoLabel
        text: appBackend.checkedVerseNo
        width: parent.width
    }

    TextArea {
        id: verseTextArea
        readOnly: true
    }

    Button {
        id: showButton
        text: qsTr("Show")

        onClicked: {
            verseTextArea.text = appBackend.checkedVerseText
        }
    }

    Button {
        id: nextItemButton
        text: qsTr("Next")

        onClicked: {
            verseTextArea.text = ""
            appBackend.requestNextVerse()
        }
    }

    }
    }
}
