import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import Basics.QmlController 1.0

Window
{
    Window
    {
        id: settingsWindow
        width: 350
        height: 350
        visible: false
        title: qsTr("Settings")
        flags: Qt.Window | Qt.FramelessWindowHint

        Rectangle
        {
            id: settingsMoveRect
            anchors.fill: parent
            color: "white"
            border.color: "black"
            border.width: 1

            MouseArea
            {
                anchors.fill: parent
                property variant clickPos: "1,1"

                onPressed: {
                    clickPos  = Qt.point(mouse.x,mouse.y)
                }

                onPositionChanged: {
                    var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)
                    settingsWindow.x += delta.x;
                    settingsWindow.y += delta.y;
                }
            }
        }

        Image
        {
            id: settingsExitBtn
            x: parent.width - 20
            y: 5
            height: 16
            width: 16
            source: "qrc:///img/close.png"

            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    settingsWindow.visible = false
                }
            }
        }
    }

    id: widgetWindow
    visible: true
    width: 250
    height: 350
    title: qsTr("Weather Widget")
    flags: Qt.Window | Qt.FramelessWindowHint

    Rectangle
    {
        id: moveRect
        anchors.fill: parent
        color: "#c7c7c7"

        MouseArea
        {
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

    QmlController
    {
        id: qmlCtrl
    }

    Image {
        id: exitBtn
        x: parent.width - 20
        y: 5
        height: 16
        width: 16
        source: "qrc:///img/close.png"

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                Qt.quit()
            }
        }
    }

    Image {
        id: settingsBtn
        x: parent.width - 43
        y: 4
        height: 18
        width: 18
        source: "qrc:///img/settings.png"

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                settingsWindow.visible = true
            }
        }
    }

    Image
    {
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
        color: "#0d64c8"
        font.pixelSize: 50
    }
}
