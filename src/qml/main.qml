import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: mainWindow
    visible: true
    width: 1280     
    height: 720
    title: qsTr("Android Auto")
    
    // Make window frameless
    flags: Qt.Window | Qt.FramelessWindowHint
    
    // Add a mouse area to allow dragging the window
    MouseArea {
        id: dragArea
        anchors.fill: parent
        property real lastMouseX: 0
        property real lastMouseY: 0
        
        onPressed: {
            lastMouseX = mouseX
            lastMouseY = mouseY
        }
        
        onMouseXChanged: {
            var dx = mouseX - lastMouseX
            mainWindow.x += dx
        }
        
        onMouseYChanged: {
            var dy = mouseY - lastMouseY
            mainWindow.y += dy
        }
        
        // Pass through mouse events to the content below
        propagateComposedEvents: true
        
        // Only enable window dragging when clicking in the top bar area
        enabled: mouseY < 40
    }
    
    // Add a close button
    Rectangle {
        id: closeButton
        width: 30
        height: 30
        color: closeButtonMouseArea.containsMouse ? "#e81123" : "transparent"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 5
        
        Text {
            anchors.centerIn: parent
            text: "✕"
            color: closeButtonMouseArea.containsMouse ? "white" : "#888888"
            font.pixelSize: 16
        }
        
        MouseArea {
            id: closeButtonMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                Qt.quit()
            }
        }
    }
    
    // Main content
    MainScreen {
        anchors.fill: parent
    }
    
    // Start Android Auto when window is shown
    Component.onCompleted: {
        aaService.start()
    }
}