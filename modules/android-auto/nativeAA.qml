import QtQuick 2.0
import Qt.labs.settings 1.0
import QtMultimedia 5.11
import QtQml 2.11

import HUDTheme 1.0
ThemeRoot {
    id:__root

    property QtObject pluginContext
    property int margin_width
    property int margin_height
    property string resolution

    Rectangle {
        visible: pluginContext.status === 0 /*AndroidAuto.NO_CONNECTION*/ || pluginContext.status === 1/*AndroidAuto.VIDEO_WAITING*/
        width: parent.width * 0.6
        height: parent.height * 0.4
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#66000000"
        ThemeText{
            visible: pluginContext.status === 0/*AndroidAuto.NO_CONNECTION*/
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            text:"Please connect a device"
            color: "#ffffff"
        }
        ThemeText{
            visible: pluginContext.status === 1/*AndroidAuto.VIDEO_WAITING*/
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            text:"Waiting for video"
            color: "#ffffff"
        }
    }

    VideoOutput {
        id: aaVideo
        visible: pluginContext.status === 2 /*AndroidAuto.RUNNING*/
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        width:parent.width * pluginContext.videoHeight/pluginContext.videoWidth < parent.height ? parent.width : parent.height * pluginContext.videoWidth/pluginContext.videoHeight
        height:parent.width * pluginContext.videoHeight/pluginContext.videoWidth < parent.height ? parent.width * pluginContext.videoHeight/pluginContext.videoWidth : parent.height
        source: pluginContext
        MouseArea {
            id: mouseArea1
            anchors.fill: parent
            onPressed:{
                // Map coordinates directly to video coordinates
                var mappedPoint = mapTouchCoordinates(mouse.x, mouse.y);
                pluginContext.mouseDown(mappedPoint);
            }
            onPositionChanged:{
                var mappedPoint = mapTouchCoordinates(mouse.x, mouse.y);
                pluginContext.mouseMove(mappedPoint);
            }
            onReleased:{
                var mappedPoint = mapTouchCoordinates(mouse.x, mouse.y);
                pluginContext.mouseUp(mappedPoint);
            }
            
            // Add mapping function
            function mapTouchCoordinates(x, y) {
                // Scale directly from mouse area to Android Auto native size
                var mappedX = (x / width) * pluginContext.videoWidth;
                var mappedY = (y / height) * pluginContext.videoHeight;
                
                return Qt.point(mappedX, mappedY);
            }
        }

        Keys.onPressed: {
            switch(event.key){
            case Qt.Key_Left:
                break;
            }
        }

        onWidthChanged: {
            pluginContext.outputWidth = aaVideo.width
        }
        onHeightChanged: {
            pluginContext.outputHeight = aaVideo.height
        }

        Component.onCompleted:{
            pluginContext.outputHeight = aaVideo.height
            pluginContext.outputWidth = aaVideo.width
        }
    }
}