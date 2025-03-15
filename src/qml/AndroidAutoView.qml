import QtQuick 2.12
import QtMultimedia 5.12

Item {
    id: root
    
    // Calculate appropriate dimensions to maintain aspect ratio
    width: parent.width * aaService.videoHeight/aaService.videoWidth < parent.height ? 
           parent.width : 
           parent.height * aaService.videoWidth/aaService.videoHeight
    
    height: parent.width * aaService.videoHeight/aaService.videoWidth < parent.height ? 
            parent.width * aaService.videoHeight/aaService.videoWidth : 
            parent.height
    
    // Whether touch input is enabled
    // Using the InputMode enum from AAService directly
    property bool touchEnabled: aaService.inputMode === 0 || aaService.inputMode === 2 // TOUCH or HYBRID
    
    // Video display
    VideoOutput {
        id: videoOutput
        anchors.fill: parent
        source: aaService
        
        // Forward touch events to Android Auto
        MouseArea {
            anchors.fill: parent
            enabled: touchEnabled
            
            onPressed: {
                // Use the mapping function instead of raw coordinates
                var mappedPoint = mapTouchCoordinates(mouse.x, mouse.y);
                aaService.mouseDown(mappedPoint);
            }

            onPositionChanged: {
                var mappedPoint = mapTouchCoordinates(mouse.x, mouse.y);
                aaService.mouseMove(mappedPoint);
            }

            onReleased: {
                var mappedPoint = mapTouchCoordinates(mouse.x, mouse.y);
                aaService.mouseUp(mappedPoint);
            }
            
            // Function to map touch coordinates correctly
            function mapTouchCoordinates(x, y) {
                // Scale directly from mouse area to Android Auto native size
                var mappedX = (x / width) * aaService.videoWidth;
                var mappedY = (y / height) * aaService.videoHeight;
                
                // Return point with the properly scaled coordinates
                return Qt.point(mappedX, mappedY);
            }
            
            // Support for mouse wheel as rotary controller
            onWheel: {
                if (wheel.angleDelta.y > 0) {
                    // Scroll up/clockwise
                    aaService.rotateClockwise();
                } else {
                    // Scroll down/counterclockwise
                    aaService.rotateCounterClockwise();
                }
            }
        }
    }
    
    // Capture keyboard events for rotary controller simulation
    Keys.onPressed: {
        event.accepted = true;
        
        switch(event.key) {
            case Qt.Key_Up:
                aaService.dpadUp();
                break;
            case Qt.Key_Down:
                aaService.dpadDown();
                break;
            case Qt.Key_Left:
                aaService.dpadLeft();
                break;
            case Qt.Key_Right:
                aaService.dpadRight();
                break;
            case Qt.Key_Return:
                aaService.dpadClick();
                break;
            case Qt.Key_Backspace:
                aaService.dpadBack();
                break;
            case Qt.Key_1:
                if (event.modifiers & Qt.ShiftModifier) {
                    aaService.rotateFlickCounterClockwise();
                } else {
                    aaService.rotateCounterClockwise();
                }
                break;
            case Qt.Key_2:
                if (event.modifiers & Qt.ShiftModifier) {
                    aaService.rotateFlickClockwise();
                } else {
                    aaService.rotateClockwise();
                }
                break;
            default:
                event.accepted = false;
                break;
        }
    }
    
    // Make sure the item can receive keyboard focus
    focus: true
    
    // Update output dimensions
    onWidthChanged: {
        aaService.outputWidth = root.width
    }
    
    onHeightChanged: {
        aaService.outputHeight = root.height
    }
    
    // Initialize output dimensions
    Component.onCompleted: {
        if (typeof aaService.setVideoSurface === "function") {
            aaService.setVideoSurface(videoOutput.videoSurface)
        } else {
            aaService.videoSurface = videoOutput.videoSurface
        }
        aaService.outputWidth = root.width
        aaService.outputHeight = root.height
        
        // Give focus to this element to receive keyboard events
        forceActiveFocus();
    }
}