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
    flags: Qt.Window | Qt.FramelessWindowHint | Qt.WA_TranslucentBackground
    color: "#00000000"

    QmlController {
        id: qmlCtrl
    }

    SettingsWindow{
        id: settingsWindow
    }

    Rectangle {
        id: moveRect
        anchors.fill: parent
        color: settingsWindow.widgetBackgroundColor
        opacity: settingsWindow.widgetOpacity

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
        x: 2
        y: 2
        source: "qrc:///img/settings.png";
        width: 16
        height: 16

        MouseArea {
            anchors.fill: parent

            onClicked: {
                settingsWindow.show()
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
