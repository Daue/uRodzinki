import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import person 1.0

ApplicationWindow {

    property color backgrounColor: "#eaeaea"

    width: 350
    height: 600
    visible: true
    color: backgrounColor

    Drawer{
        id: drawer
        width: Math.min( parent.width, parent.height ) / 3 * 2
        height: parent.height

        background: Rectangle {
            color: backgrounColor
        }

        SortSettings {
            id: sortSettings
            onSortRoleChanged: {
                personsModel.sortRole = sortSettings.sortRole
                drawer.close()
            }
        }
    }

    header: ToolBar {
        Material.background: Material.Purple
        ToolButton {
            id: menuButton
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            icon.source: "qrc:/icon/res/menu.svg"
            onClicked: drawer.open()
        }
    }

    ListView {
        anchors.fill: parent
        spacing: 5
        anchors.margins: 10

        model: personsModel

        delegate: PersonDelegate {
            personName: model.name
            personBornDate: model.birthday
            personImage: ("qrc:/img/res/avatar/" + model.icon)
            personYearsOld: model.yearsOld
        }
    }

    Component.onCompleted: {
        sortSettings.sortRole = personsModel.sortRole
    }
}
