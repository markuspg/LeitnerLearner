import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: modeChooserPage

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaFlickable {
        anchors.fill: parent

        // PullDownMenu and PushUpMenu must be declared in SilicaFlickable, SilicaListView or SilicaGridView
        PullDownMenu {
            MenuItem {
                text: qsTr("Check Verses")
                onClicked: pageStack.push(Qt.resolvedUrl("VerseCheck.qml"))
            }
        }

        PushUpMenu {
            MenuItem {
                text: qsTr("Enter Verses")
                onClicked: pageStack.push(Qt.resolvedUrl("VerseEntry.qml"))
            }
        }
    }
}
