import QtQuick
import QtQuick.Controls
import "../js/Utils.js" as Utils

ApplicationWindow {

    width: 350
    height: 600
    visible: true
    color: "#eaeaea"

    //header: Header{}

    ListView {
        anchors.fill: parent
        spacing: 5
        anchors.margins: 10

        model: DataModel{}

        delegate: PersonDelegate {
            personName: name
            personBornDate: Utils.formatDate( Utils.dateFromString( born ) )
            personImage: ("qrc:/img/res/avatar/" + image)
        }
    }
}
