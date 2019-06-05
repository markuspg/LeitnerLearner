import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: verseEntryPage

    signal itemEntered(string argBook, int argChapterNo, int argVerseNo, string argText)

    SilicaFlickable {
        anchors.fill: parent
        contentHeight: verseDataColumn.height + Theme.paddingLarge

    Column {
        id: verseDataColumn
        width: parent.width

        PageHeader { title: qsTr("Enter a Verse") }

        ComboBox {
            id: bookNameComboBox

            menu: ContextMenu {
                MenuItem { text: qsTr("Genesis") }
                MenuItem { text: qsTr("Exodus") }
                MenuItem { text: qsTr("Leviticus") }
                MenuItem { text: qsTr("Numbers") }
                MenuItem { text: qsTr("Deuteronomy") }
            }
        }

        TextField {
            id: chapterNoTextField

            inputMethodHints: Qt.ImhFormattedNumbersOnly
            label: qsTr("Chapter No.")
            validator: IntValidator { bottom: 1; top: 150 }
            width: parent.width
        }

        TextField {
            id: verseNoTextField

            inputMethodHints: Qt.ImhFormattedNumbersOnly
            label: qsTr("Verse No.")
            validator: IntValidator { bottom: 1; top: 176 }
            width: parent.width
        }


        TextEdit {
            id: verseText
        }

        Button {
            id: addButton

            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Add")
            // onClicked:
        }
    }
    }
}
