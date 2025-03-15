#include "aaservice.h"
#include "headunit.h"
#include "aasettings.h"
#include <QFile>
#include <QDir>
#include <QTextStream>

AAService::AAService(QObject *parent) : QObject(parent)
{
    // Initialize settings first
    AASettings::instance()->initialize();
    
    m_headunit = new Headunit(this);

    connect(m_headunit, &Headunit::statusChanged, this, &AAService::statusChanged);
    connect(m_headunit, &Headunit::videoResized, this, &AAService::videoResized);
    connect(m_headunit, &Headunit::playbackStarted, this, &AAService::playbackStarted);
    connect(m_headunit, &Headunit::btConnectionRequest, this, &AAService::btConnectionRequest);
    
    // Create a timer to periodically check for devices
    m_deviceCheckTimer = new QTimer(this);
    connect(m_deviceCheckTimer, &QTimer::timeout, this, &AAService::checkForDevice);
    m_deviceCheckTimer->start(1000); // Check every second
}

void AAService::checkForDevice()
{
    // Only attempt reconnection if we're not already connected
    if (m_headunit->status() == Headunit::NO_CONNECTION) {
        qDebug() << "Checking for Android Auto devices...";
        start(); // Attempt to start connection
    }
}

AAService::~AAService()
{
    // The m_headunit pointer will be deleted by Qt's parent-child mechanism
}

QAbstractVideoSurface* AAService::videoSurface() const
{
    return m_headunit->videoSurface();
}

void AAService::setVideoSurface(QAbstractVideoSurface* surface)
{
    qDebug() << "Setting video surface in AAService:" << surface;
    if (m_headunit->videoSurface() != surface) {
        m_headunit->setVideoSurface(surface);
        emit videoSurfaceChanged();
    }
}

int AAService::status() const
{
    return m_headunit->status();
}

int AAService::videoWidth() const
{
    return m_headunit->videoWidth();
}

int AAService::videoHeight() const
{
    return m_headunit->videoHeight();
}

bool AAService::mouseDown(QPoint point)
{
    return m_headunit->mouseDown(point);
}

bool AAService::mouseMove(QPoint point)
{
    return m_headunit->mouseMove(point);
}

bool AAService::mouseUp(QPoint point)
{
    return m_headunit->mouseUp(point);
}

bool AAService::keyEvent(QString key)
{
    return m_headunit->keyEvent(key);
}

void AAService::init()
{
    // Verify config file
    QFile configFile(QDir::currentPath() + "/android_auto_config.ini");
    if (!configFile.exists()) {
        qWarning() << "WARNING: Config file not found at:" << QDir::currentPath() + "/android_auto_config.ini";
        
        // List files in the current directory to help debugging
        QDir currentDir = QDir::current();
        QStringList files = currentDir.entryList(QDir::Files);
        qDebug() << "Files in current directory:";
        for (const QString& file : files) {
            qDebug() << "  " << file;
        }
    } else {
        qDebug() << "Found config file at:" << QDir::currentPath() + "/android_auto_config.ini";
        
        // Try to open and read the file
        if (configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&configFile);
            QString fileContent = in.readAll();
            configFile.close();
            
            qDebug() << "Config file content:";
            qDebug() << fileContent;
        } else {
            qWarning() << "WARNING: Could not open config file for reading!";
        }
    }
    
    // Dump all settings
    AASettings::instance()->dumpConfigInfo();
    
    // Apply custom settings before initializing
    applyCustomSettings();
    m_headunit->init();
}

void AAService::applyCustomSettings() 
{
    // Apply DPI setting from config
    int dpi = AASettings::instance()->getSetting("dpi", "240").toInt();
    qDebug() << "Setting Android Auto DPI to:" << dpi;
    
    // Apply resolution settings from config
    int resolutionSetting = AASettings::instance()->getSetting("resolution", "2").toInt();
    qDebug() << "Setting Android Auto resolution to:" << resolutionSetting;
    
    // Other settings will be applied by the headunit when it initializes
}

void AAService::start()
{
    if (m_headunit->status() == Headunit::RUNNING) {
        qDebug() << "Android Auto is already running";
        return;
    }
    
    qDebug() << "Attempting to start Android Auto";
    // First ensure initialization is done
    init();
    
    // Try to start the connection
    int result = m_headunit->startHU();
    if (result < 0) {
        qDebug() << "Failed to start Android Auto connection. Will retry automatically.";
    } else {
        qDebug() << "Android Auto connection initiated successfully";
    }
}

void AAService::stop()
{
    m_headunit->stopPipelines();
}