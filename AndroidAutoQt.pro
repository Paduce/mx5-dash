QT += quick multimedia
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

# Main application sources
SOURCES += \
    src/main.cpp \
    src/aaservice.cpp

HEADERS += \
    src/aaservice.h

# Android Auto module sources
SOURCES += \
    modules/android-auto/androidauto.cpp \
    modules/android-auto/headunit.cpp \
    modules/android-auto/headunit/hu/hu_aad.cpp \
    modules/android-auto/headunit/hu/hu_aap.cpp \
    modules/android-auto/headunit/hu/hu_ssl.cpp \
    modules/android-auto/headunit/hu/hu_tcp.cpp \
    modules/android-auto/headunit/hu/hu_usb.cpp \
    modules/android-auto/headunit/hu/hu_uti.cpp \
    modules/android-auto/headunit/common/glib_utils.cpp \
    modules/android-auto/qgstvideobuffer.cpp \
    modules/android-auto/headunit/hu/generated.x64/hu.pb.cc

HEADERS += \
    includes/plugininterface.h \
    includes/mediainterface.h \
    modules/android-auto/androidauto.h \
    modules/android-auto/headunit.h \
    modules/android-auto/headunit/hu/hu_aad.h \
    modules/android-auto/headunit/hu/hu_aap.h \
    modules/android-auto/headunit/hu/hu_ssl.h \
    modules/android-auto/headunit/hu/hu_tcp.h \
    modules/android-auto/headunit/hu/hu_usb.h \
    modules/android-auto/headunit/hu/hu_uti.h \
    modules/android-auto/headunit/common/glib_utils.h \
    modules/android-auto/qgstvideobuffer.h \
    modules/android-auto/headunit/hu/generated.x64/hu.pb.h

# Proto files will be added after compilation

RESOURCES += \
    src/qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Android Auto module path
INCLUDEPATH += $${PWD}/modules/android-auto
INCLUDEPATH += $${PWD}/modules/android-auto/headunit/hu
INCLUDEPATH += $${PWD}/modules/android-auto/headunit/hu/generated.x64
INCLUDEPATH += $${PWD}/modules/android-auto/headunit/common
INCLUDEPATH += $${PWD}/includes
# Libraries
CONFIG += link_pkgconfig
PKGCONFIG += gstreamer-1.0 gstreamer-app-1.0 gstreamer-video-1.0 libssl libcrypto libusb-1.0 glib-2.0 protobuf

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Add Bluetooth to QT modules
QT += quick multimedia bluetooth