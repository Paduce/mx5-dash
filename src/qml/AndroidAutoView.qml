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
                // instead of relying on intermediate scaling in headunit.cpp
                var mappedX = (x / width) * aaService.videoWidth;
                var mappedY = (y / height) * aaService.videoHeight;
                
                // Return point with the properly scaled coordinates
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