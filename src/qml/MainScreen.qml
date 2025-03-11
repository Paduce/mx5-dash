import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root
    
    // Background
    Rectangle {
        anchors.fill: parent
        color: "#000000"
    }
    
    // Optional: Add a top bar to make it clear where users can drag the window
    Rectangle {
        id: topBar
        width: parent.width
        height: 40
        color: "#222222"
        
        Text {
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 10
            text: "Android Auto"
            color: "#ffffff"
            font.pixelSize: 16
            font.bold: true
        }
    }
    
    // Status message when not connected
    Rectangle {
        visible: aaService.status === 0 || aaService.status === 1 // NO_CONNECTION or VIDEO_WAITING
        width: parent.width * 0.6
        height: parent.height * 0.4
        anchors.centerIn: parent
        color: "#66000000"
        
        Text {
            visible: aaService.status === 0 // NO_CONNECTION
            anchors.centerIn: parent
            text: "Please connect an Android device"
            color: "#ffffff"
            font.pixelSize: 24
        }
        
        Text {
            visible: aaService.status === 1 // VIDEO_WAITING
            anchors.centerIn: parent
            text: "Waiting for video stream..."
            color: "#ffffff"
            font.pixelSize: 24
        }
    }
    
    // Android Auto view
    AndroidAutoView {
        id: androidAutoView
        visible: aaService.status === 2 // RUNNING
        anchors.centerIn: parent
        // Adjust anchors to account for the top bar
        anchors.top: topBar.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
    }
    
    // Connection info (for debugging)
    Text {
        anchors.top: topBar.bottom
        anchors.left: parent.left
        anchors.margins: 8
        text: "Status: " + aaService.status
        color: "#ffffff"
        font.pixelSize: 14
    }
}