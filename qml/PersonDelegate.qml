import QtQuick

Item {

    property alias personName: name.text
    property alias personBornDate: born.text
    property alias personImage: image.source
    property int personYearsOld
    signal click;

    id: root
    width: ListView.view.width
    height: 80
    visible: true

    SequentialAnimation {
        id: touchAnimation
        NumberAnimation { target: root; property: "scale"; to: 1.1; duration: 50 }
        NumberAnimation { target: root; property: "scale"; to: 1; duration: 50 }
    }

    Rectangle {
        id: shadow
        color: "#dbdbdb"
        anchors.fill: parent
        radius: 3

        Rectangle {
            width: parent.width - 2
            height: parent.height - 2
            anchors.left: parent.left
            anchors.top: parent.top
            color: "white"
            radius: 3
            border.color: "#c2c2c2"
            border.width: 1

            Image {
                id: image
                width: height
                height: parent.height - 16
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.margins: 8
            }

            Text {
                id: name
                anchors.left: image.right
                anchors.top: image.top
                anchors.leftMargin: 10
                font.pixelSize: 20
                text: "Placeholder..."
                font.bold: true
            }
            
            Text {
                id: born
                anchors.top: name.bottom
                anchors.left: name.left
                anchors.topMargin: 7
                font.pixelSize: 13
                text: "20 marzec (2002)"
            }

            Text {
                id: yearsOld
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.margins: 8
                text: personYearsOld
                font.italic: true
            }

        }

        MouseArea {
            anchors.fill: parent;
            onClicked: touchAnimation.start()
        }

    }
}

/*##^##
Designer {
    D{i:0;width:400}
}
##^##*/
