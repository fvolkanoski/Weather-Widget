import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import Basics.QmlController 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color: "#c7c7c7"
    //flags: Qt.FramelessWindowHint;

    QmlController
    {
        id: qmlCtrl
    }

    Button
    {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: "Call API"
        onClicked: qmlCtrl.callApi()
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
