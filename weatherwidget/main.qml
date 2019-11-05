import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import Basics.QmlController 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    //flags: Qt.FramelessWindowHint;

    QmlController
    {
        id: qmlCtrl
    }

    Button {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: "Call API"
        onClicked: qmlCtrl.callApi()
    }

    Text {
        id: weatherTxt
        text: qmlCtrl.weatherIcon
    }
}
