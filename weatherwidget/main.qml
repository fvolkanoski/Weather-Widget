import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import Weather.QmlController 1.0

Window
{
    id: widgetWindow
    visible: true
    width: 150
    height: 150
    title: qsTr("Weather Widget")
    flags: Qt.Window | Qt.FramelessWindowHint

    QmlController {
        id: qmlCtrl
    }

    Rectangle {
        id: moveRect
        anchors.fill: parent
        color: "#ccf2f4"

        MouseArea {
            anchors.fill: parent
            property variant clickPos: "1,1"

            onPressed: {
                clickPos  = Qt.point(mouse.x,mouse.y)
            }

            onPositionChanged: {
                var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)
                widgetWindow.x += delta.x;
                widgetWindow.y += delta.y;
            }
        }
    }

    Image {
        id: weatherIcon
        anchors.horizontalCenter: parent.horizontalCenter
        y: 10
        source: "http://openweathermap.org/img/wn/" + qmlCtrl.weatherIcon + "@2x.png"
    }

    Text {
        id: weatherTemp
        anchors.horizontalCenter: parent.horizontalCenter
        y: 100
        text: qmlCtrl.weatherTemperature + "\xB0" + "C"
        font.bold: true
        color: "#314e52"
        font.pixelSize: 20
    }

    Text {
        id: cityName
        text: qmlCtrl.city
        color: "#314e52"
        font.pointSize: 10
        anchors.horizontalCenter: parent.horizontalCenter
        y: weatherTemp.y + 30
    }
}
