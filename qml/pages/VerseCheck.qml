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

    Label {
        id: bookLabel

        text: appBackend.checkedBook
        width: parent.width
    }

    Label {
        id: chapterNoLabel

        anchors.top: bookLabel.bottom
        text: appBackend.checkedChapterNo
        width: parent.width
    }

    Label {
        id: verseNoLabel

        anchors.top: chapterNoLabel.bottom
        text: appBackend.checkedVerseNo
        width: parent.width
    }

    TextArea {
        id: verseTextArea

        anchors.top: verseNoLabel.bottom
        readOnly: true
    }

    Button {
        id: showButton

        anchors.top: verseTextArea.bottom
        text: qsTr("Show")

        onClicked: {
            verseTextArea.text = appBackend.checkedVerseText
        }
    }

    Row {
        anchors.top: showButton.bottom
    Button {
        id: correctButton
        text: qsTr("Correct")

        onClicked: {
            verseTextArea.text = ""
            appBackend.verseAnsweredRightly()
        }
    }

    Button {
        id: wrongButton
        text: qsTr("Wrong")

        onClicked: {
            verseTextArea.text = ""
            appBackend.verseAnsweredWrongly()
        }
    }
    }

    }
}
