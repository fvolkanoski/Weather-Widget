import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4
import Weather.QmlController 1.0

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
    property string widgetTextColor : "#314e52"

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

    SmallTextInput {
        id: bgColorInput
        x: bgColorText.width + 10
        y: 32.5
        height: 20
        width: 160
        z: -1
        currentText: widgetBackgroundColor

        onTextChanged: {
            widgetBackgroundColor = text
        }
    }

    Text {
        id: textColorText
        x: 10
        y: 65
        text: "Text color (HEX): "
    }

    SmallTextInput {
        id: textColorInput
        x: bgColorText.width + 10
        y: 62.5
        height: 20
        width: 160
        z: -1
        currentText: widgetTextColor

        onTextChanged: {
            widgetTextColor = text
        }
    }
}

