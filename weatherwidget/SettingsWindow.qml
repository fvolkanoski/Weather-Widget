import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Window {
    id: settings
    width: 300
    height: 300
    minimumHeight: 300
    minimumWidth: 300
    maximumHeight: 300
    maximumWidth: 300
    title: qsTr("Settings")
    flags: Qt.Window
    visible: false

    property double widgetOpacity: 1.0
    property string widgetBackgroundColor : "#ccf2f4"

    Text {
        id: bgOpacityText
        x: 10
        y: 10
        text: "Background opacity: "
    }

    SmallSlider {
        id: opacitySlider
        from: 0
        to: 1
        value: 1
        width: 180
        x: bgOpacityText.width + 10
        y: 5

        onValueChanged: {
            widgetOpacity = value
        }
    }

    Text {
        id: bgColorText
        x: 10
        y: 35
        text: "Background color (HEX): "
    }

    Rectangle {
        id: bgColorInput
        x: bgColorText.width + 10
        y: 32.5
        height: 20
        width: 160
        z: -1
        border.width: 1
        border.color: "black"
        radius: 5

        TextInput {
            text: widgetBackgroundColor
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 2.5
            anchors.leftMargin: 5

            onTextChanged: {
                widgetBackgroundColor = text
            }
        }
    }


}

