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
    
    // Video display
    VideoOutput {
        id: videoOutput
        anchors.fill: parent
        source: aaService
        
        // Forward touch events to Android Auto
        MouseArea {
            anchors.fill: parent
            
            onPressed: {
                // Map from MouseArea coordinates to Android Auto coordinates
                var mappedPoint = mapTouchCoordinates(mouse.x, mouse.y);
                aaService.mouseDown(mappedPoint);
            }
            
            onPositionChanged: {
                // Map from MouseArea coordinates to Android Auto coordinates
                var mappedPoint = mapTouchCoordinates(mouse.x, mouse.y);
                aaService.mouseMove(mappedPoint);
            }
            
            onReleased: {
                // Map from MouseArea coordinates to Android Auto coordinates
                var mappedPoint = mapTouchCoordinates(mouse.x, mouse.y);
                aaService.mouseUp(mappedPoint);
            }
            
            // Function to map touch coordinates correctly
            function mapTouchCoordinates(x, y) {
                // Scale from display size to Android Auto native size
                var scaleX = aaService.videoWidth / videoOutput.width;
                var scaleY = aaService.videoHeight / videoOutput.height;
                
                // Apply scaling and offset if needed
                var mappedX = x * scaleX;
                var mappedY = y * scaleY;
                
                // Create a point with the translated coordinates
                return Qt.point(mappedX, mappedY);
            }
        }
    }
    
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
    }
}