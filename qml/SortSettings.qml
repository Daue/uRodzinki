import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import person 1.0

Item {
    id: root

    property int sortRole : -1
    //signal sortChanged( var sortRole )

    GroupBox
    {
        label : Label {
           x: 10
           y: 10
           text: qsTr("Sortuj według:")
           font.bold: true
           font.pixelSize: 17
        }

        background: Rectangle {
            color: "transparent"
        }

        ColumnLayout
        {
            height: children.height
            width: parent.width

            Repeater {
                id: radioButtonsRepeater

                property variant itemsInfo: [
                      {
                          text: "Najbliższych urodzin"
                        , sortRole: PersonRole.DaysToBirthday
                        }
                    , {
                          text: "Wieku"
                        , sortRole: PersonRole.YearsOld
                        }
                    , {
                          text: "Alfabetycznie"
                        , sortRole: PersonRole.Name
                        }
                    ]

                model: itemsInfo
                delegate: RadioButton {
                    text: radioButtonsRepeater.itemsInfo[index].text
                    checked: root.sortRole === radioButtonsRepeater.itemsInfo[index].sortRole
                    onClicked: sortRole = radioButtonsRepeater.itemsInfo[index].sortRole
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;height:400;width:400}
}
##^##*/
