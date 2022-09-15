import QtQuick
import QtQuick.Controls

//import org.dave 1.0

ApplicationWindow {

    width: 350
    height: 600
    visible: true
    color: "#eaeaea"

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
}
