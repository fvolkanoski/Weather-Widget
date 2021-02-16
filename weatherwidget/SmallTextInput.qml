import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: smallTextInput

    property string currentText : ""
    signal textChanged(string text)

    border.width: 1
    border.color: "black"
    radius: 5
    
    TextInput {
        text: currentText
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 2.5
        anchors.leftMargin: 5
        width: smallTextInput.width

        onTextChanged: {
            currentText = text
            smallTextInput.textChanged(text)
        }
    }
}
