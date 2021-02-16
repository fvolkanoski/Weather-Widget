import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Slider {
    id: slider
    
    background: Rectangle {
        x: opacitySlider.leftPadding
        y: opacitySlider.topPadding + opacitySlider.availableHeight / 2 - height / 2
        implicitWidth: 200
        implicitHeight: 2
        width: opacitySlider.availableWidth
        height: implicitHeight
        radius: 2
        color: "#bdbebf"
        
        Rectangle {
            width: opacitySlider.visualPosition * parent.width
            height: parent.height
            color: "#ccf2f4"
            radius: 2
        }
    }
    
    handle: Rectangle {
        x: opacitySlider.leftPadding + opacitySlider.visualPosition * (opacitySlider.availableWidth - width)
        y: opacitySlider.topPadding + opacitySlider.availableHeight / 2 - height / 2
        implicitWidth: 15
        implicitHeight: 15
        radius: 13
        color: opacitySlider.pressed ? "#f0f0f0" : "#f6f6f6"
        border.color: "#bdbebf"
    }
}
