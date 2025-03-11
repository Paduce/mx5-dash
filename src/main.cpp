#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <gst/gst.h>

#include "aaservice.h"


int main(int argc, char *argv[])
{
    // Set up environment for GST
    qputenv("GST_PLUGIN_SYSTEM_PATH_1_0", "");
    qputenv("GST_PLUGIN_SYSTEM_PATH", "");
    qputenv("GST_PLUGIN_PATH", "/usr/lib/x86_64-linux-gnu/gstreamer-1.0");

    // Add before starting your application
    guint major, minor, micro, nano;
    gst_version(&major, &minor, &micro, &nano);
    qDebug() << "GStreamer version:" << major << "." << minor << "." << micro << "." << nano;

    // Check if plugins are available
    GstElementFactory *src_factory = gst_element_factory_find("appsrc");
    if (!src_factory) {
        qCritical() << "Could not find appsrc element - make sure gstreamer plugins are installed";
    } else {
        gst_object_unref(src_factory);
        qDebug() << "Found appsrc element";
    }

    
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    
    // Initialize GStreamer
    gst_init(&argc, &argv);
    
    // Create Android Auto service
    AAService aaService;
    
    // Initialize QML engine
    QQmlApplicationEngine engine;
    
    // Expose AAService to QML
    engine.rootContext()->setContextProperty("aaService", &aaService);
    
    // Load main QML file
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    
    // Initialize Android Auto service
    aaService.init();
    
    return app.exec();
}